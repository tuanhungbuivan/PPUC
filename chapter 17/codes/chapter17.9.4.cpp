#include <iostream>

struct Link{
    std::string value;
    Link* prev;
    Link* succ;
    Link(const std::string& v, Link* p = nullptr, Link* s=nullptr)
        : value{v}, prev{p}, succ{s} {}
};

Link* insert(Link* p, Link* n)
{
    if( n == nullptr) return p;
    if( p == nullptr) return n;

    n->succ = p;
    n->prev = p->prev;
    if(p->prev) p->prev->succ = n;
    p->prev = n;

    return n;
}

Link* erase(Link*p)
{
    if(p==nullptr) return nullptr;
    if(p->succ) p->succ->prev = p->prev;
    if(p->prev) p->prev->succ = p->succ;
    return p->succ;
}

Link* find(Link* p, const std::string& s)
{
    while(p){
        if(p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}

Link* advance(Link* p, int n)
{
    if(p == nullptr) return nullptr;
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

void print(Link* p)
{
    std::cout<<"{ ";
    while(p){
        std::cout<< p->value;
        if(p->succ) std::cout<<" , ";
        p = p->succ;
    }
    std::cout<<" }\n";
}

int main()
{
    Link* norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods,new Link{"Odin"});
    norse_gods = insert(norse_gods,new Link{"Zeus"});
    norse_gods = insert(norse_gods,new Link{"Freia"});
    norse_gods = insert(norse_gods,new Link{"Poseidon"});

    //print(norse_gods);
    //std::cout<<std::endl;

    Link* m = find(norse_gods,"Zeus");
    if(m) m->value = "Loki";

    //print(norse_gods);
    //std::cout<<std::endl;

    Link* greek_gods = new Link{"Hera"};
    greek_gods = insert(greek_gods,new Link{"Ares"});
    greek_gods = insert(greek_gods,new Link{"Loki"});
    greek_gods = insert(greek_gods,new Link{"Hades"});

    Link* p = find(norse_gods,"Poseidon");
    if(p){
        if(p == norse_gods) norse_gods = p->succ;
        erase(p);
        greek_gods = insert(greek_gods,p);
    }

    print(greek_gods);



    return 0;
}