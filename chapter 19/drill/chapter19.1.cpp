#include <iostream>

template<typename T> struct S{
    T val;
};

int main()
{
    S<double> d;
    d.val = 10.2;
    std::cout<<d.val<<'\n';

    S<std::string> s;
    s.val = "my name is ";
    std::cout<<s.val<<'\n';

    return 0;
}