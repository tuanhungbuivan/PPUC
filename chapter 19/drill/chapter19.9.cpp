#include <iostream>
#include <vector>
#include <istream>

//
template<typename T> struct S{
    S() : val(){}
    S(T s) : val(s){}
    
    void set(T t) { val = t; } // drill 9
    T& operator=(const T&); //drill 10
    T& get() {return val;} //drill 11
    const T& get() const {return val;} //drill 11
    std::istream operator>>(T t){ std::cin>>val; } //drill 12
private:
    T val; 
};

template<typename T> T& S<T>::operator=(const T& d)
{
    val = d;
    return val;
}

template<typename T> 
const T& get(S<T>& g)
{
    return g.get();
}

//drill 13
template<typename T>
void read_val(T& v)
{
    std::cin>>v;
}

int main()
{
    //drill 8
    S<double> d;
    d.set(10.2);
    std::cout<<get(d)<<'\n';

    S<std::string> s;
    s.set("my name is ");
    std::cout<<get(s)<<'\n';

    S<char> c;
    c.set('!');
    std::cout<<get(c)<<'\n';

    S<int> i;
    i.set(10);
    std::cout<<get(i)<<'\n';

    S<std::vector<int>> v;
    v.set(std::vector<int>(5,10));
    for(int i : get(v)) std::cout<<i<<" ";
    std::cout<<std::endl;

    //drill 13
    int nums;
    std::cout<<"enter numbers: ";
    S<std::vector<int>> v1(std::vector<int>(5));
    for(int i=0;i<5;i++){
        read_val(v1.get()[i]);
    }

    std::cout<<"entered numbers: ";
    for(int i : get(v1)) std::cout<<i<<" ";
    std::cout<<std::endl;

    return 0;
}