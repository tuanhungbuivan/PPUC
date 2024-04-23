#include "classfile.h"

Link* Link::insert(Link* n)
{
    if( n == nullptr) return this;

    n->succ = this;
    n->prev = prev;
    if(prev) prev->succ = n;
    prev = n;

    return n;
}

Link* Link::add(Link* n)
{
    if( n == nullptr) return this;

    n->prev = this;
    if(succ) succ->prev = n;
    n->succ = succ;
    succ = n;

    return n;
}

Link* Link::erase()
{
    if(succ) succ->prev = prev;
    if(prev) prev->succ = succ;
    return succ;
}

Link* Link::find(const std::string& s)
{
    Link* p = this;
    while(p){
        if(p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}
const Link* Link::find(const std::string& s) const
{
    return nullptr;
}

Link* Link::advance(int n) const
{
    Link* p = const_cast<Link*>(this);
    if(0<n){
        while(n--){
            if(p->prev == nullptr) return nullptr;
            p = p->succ;
        }
    }else if(0>n){
        while(n++){
            if(p->prev == nullptr) return nullptr;
            p = p->succ;
        }
    }
    return p;
}

void Link::print(Link* p)
{
    std::cout<<"{ ";
    while(p){
        std::cout<< p->value;
        if(p->next()) std::cout<<" , ";
        p = p->next();
    }
    std::cout<<" }\n";
}

int main()
{
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});
    norse_gods = norse_gods->insert(new Link{"Poseidon"});

    Link* m = norse_gods->find("Zeus");
    if(m) m->value = "Loki";

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Ares"});
    greek_gods = greek_gods->insert(new Link{"Loki"});
    greek_gods = greek_gods->insert(new Link{"Hades"});

    Link* p = norse_gods->find("Poseidon");
    if(p){
        if(p == norse_gods) norse_gods = p->next();
        p->erase();
        greek_gods = greek_gods->insert(p);
    }

    greek_gods->print(greek_gods);
}