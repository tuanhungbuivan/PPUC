#include <iostream>
#include <set>

struct Fruit {
    std::string name;
    int count;
    double unit_price;
    Fruit(std::string n, int c, double up = 0.0)
        :name(n), count(c), unit_price(up) { }
};

struct Fruit_comparison{
    bool operator()(const Fruit* a, const Fruit* b){
        return a->name < b->name;
    }
};

std::ostream& operator<<(std::ostream& os, const Fruit* p)
{
    os << p->name << " " << p->count << " " << p->unit_price << '\n';

    return os;
}

int main()
{
    std::set<Fruit*,Fruit_comparison> fruits;
    fruits.insert(new Fruit("Apple", 20, 5.0));
    fruits.insert(new Fruit("Orange", 10, 6.0));
    fruits.insert(new Fruit("Pearl", 40, 9.4));
    fruits.insert(new Fruit("Strawberry", 100, 2.1));
    fruits.insert(new Fruit("Grape", 1, 100.20));

    typedef std::set<Fruit*,Fruit_comparison>::const_iterator Si;
    for (Si p = fruits.begin(); p!=fruits.end(); ++p) std::cout << *p << '\n';
}