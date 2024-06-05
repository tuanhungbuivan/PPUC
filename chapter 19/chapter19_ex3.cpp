#include <iostream>
#include <vector>

template<class T,class U>
struct Pair{
    Pair(T t, U u) : t(t), u(u) { }

    T t;
    U u;
};

class Symbol_table{
public:
    double get(std::string s);                   // return the value of the Variable named s
    void set(std::string s, double d);           // set the Variable named s to d
    bool is_declared(std::string var);           // is var already in var_table?
    double declare(std::string var, double val); // add (var,val) to var_table
    void print();

private:
    std::vector<Pair<std::string,double>> table;
};

double Symbol_table::get(std::string s)
{
    for(int i=0;i<table.size();i++){
        if(table[i].t == s){
            return table[i].u;
        }
    }

    return 0;
}

void Symbol_table::set(std::string s, double d)
{
    for(int i=0;i<table.size();i++){
        if(table[i].t == s){
            table[i].u = d;
        }
    }
}

bool Symbol_table::is_declared(std::string var)
{
    for(int i=0;i<table.size();i++){
        if(table[i].t == var){
            return true;
        }
    }
    return 0;
}

double Symbol_table::declare(std::string var, double val)
{
    if(is_declared(var)){
        std::cerr << "Already exist in the table\n";
        return 0;
    }

    table.push_back(Pair<std::string,double>(var,val));
    return val;
}

void Symbol_table::print()
{
    for(int i=0;i<table.size();i++){
        std::cout << table[i].t << '\t' << table[i].u << '\n';
    }
}

int main()
{
    Symbol_table s;
    
    s.declare("Pi",3.14);
    s.declare("e",2.72);

    s.print();
    std::cout << "Pi is " << s.get("Pi") << "\n";

    if (s.is_declared("Pi"))
        std::cout << "Pi is declared\n";
    else
        std::cout << "Pi is not declared\n";
    if (s.is_declared("nd"))
        std::cout << "nd is declared\n";
    else
        std::cout << "nd is not declared\n";
    s.set("Pi",4.14);
    std::cout << "Pi is now " << s.get("Pi") << "\n";

    return 0;
}