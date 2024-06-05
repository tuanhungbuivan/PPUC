#include <iostream>

struct God{
    God(const std::string& n, const std::string& m, const std::string& v, const std::string& w)
        : name(n), mythology(m), vehicle(v), weapon(w) { }

    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;
};

std::ostream& operator<<(std::ostream& os, const God& g)
{
    os << g.name << ": " << g.mythology << ", "
        << g.vehicle << ", " << g.weapon;
    return os;
}

//------------------------------------------------------------------------------

bool operator==(const God& g1, const God& g2)
{
    return (g1.name==g2.name && g1.mythology==g2.mythology
        && g1.vehicle==g2.vehicle && g1.weapon==g2.weapon);
}

//------------------------------------------------------------------------------

bool operator!=(const God& g1, const God& g2)
{
    return !(g1==g2);
}

//------------------------------------------------------------------------------

bool operator<(const God& g1, const God& g2)
{
    return g1.name<g2.name;
}

//------------------------------------------------------------------------------

bool operator>(const God& g1, const God& g2)
{
    return g2<g1;
}

//------------------------------------------------------------------------------

bool operator<=(const God& g1, const God& g2)
{
    return !(g1>g2);
}

//------------------------------------------------------------------------------

bool operator>=(const God& g1, const God& g2)
{
    return !(g1<g2);
}

template <class T>
struct Link{
    T value;
    Link* prev;
    Link* succ;
    Link(const T& v, Link* p = nullptr, Link* s=nullptr)
        : value{v}, prev{p}, succ{s} {}
};

template <class T>
Link<T>* insert(Link<T>* p, Link<T>* n)
{
    if( n == nullptr) return p;
    if( p == nullptr) return n;

    n->succ = p;
    n->prev = p->prev;
    if(p->prev) p->prev->succ = n;
    p->prev = n;

    return n;
}

template <class T>
Link<T>* erase(Link<T>*p)
{
    if(p==nullptr) return nullptr;
    if(p->succ) p->succ->prev = p->prev;
    if(p->prev) p->prev->succ = p->succ;
    return p->succ;
}

template <class T>
Link<T>* find(Link<T>* p, const T& s)
{
    while(p){
        if(p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}

template <class T>
Link<T>* advance(Link<T>* p, T n)
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

template <class T>
void print(Link<T>* p)
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

    God thor("Thor", "Norse", "Pinzgauer", "Hammer");
    Link<God>* norse_gods = new Link<God>(thor);

    God odin("Odin", "Norse", "Eight-legged horse", "");
    norse_gods = insert(norse_gods, new Link<God>(odin));

    print(norse_gods);

    while (norse_gods) {
        Link<God>* next = norse_gods->succ;
        delete norse_gods;
        norse_gods = next;
    }

    return 0;
}
