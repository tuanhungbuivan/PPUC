#ifndef CLASSFILE_H
#define CLASSFILE_H

#include <iostream>
#include <string>

class Link{

public:
    std::string value;
    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
        :value{v}, prev{p}, succ{s}{ }
    
    Link* insert(Link* n);
    Link* add(Link* n);
    Link* erase();
    Link* find(const std::string& s);
    const Link* find(const std::string& s) const;

    Link* advance(int n) const;
    static void print(Link* p);

    Link* next() const {return succ;}
    Link* previous() const {return prev;}

private:
    Link* prev;
    Link* succ;
};

#endif