#include <iostream>
#include <vector>

//drill 6, 7, 8
template<typename T> struct S{
    S() : val(){}
    S(T s) : val(s){}
    T& get() {return val;}//drill 6
    const T& get() const {return val;}
private:
    T val; //drill 7
};

//drill 6
template<typename T> 
const T& get(S<T>& g)
{
    return g.get();
}

int main()
{
    //drill 8
    S<double> d(10.2);
    std::cout<<get(d)<<'\n';

    S<std::string> s("my name is ");
    std::cout<<get(s)<<'\n';

    S<char> c('!');
    std::cout<<get(c)<<'\n';

    S<int> i(10);
    std::cout<<get(i)<<'\n';

    S<std::vector<int>> v(std::vector<int>(5,10));
    for(int i : get(v)) std::cout<<i<<" ";
    std::cout<<std::endl;

    //drill 4
    int nums;
    std::cout<<"enter numbers: ";
    S<std::vector<int>> v1(std::vector<int>(5));
    for(int i=0;i<5;i++){
        std::cin>>nums;
        v1.get()[i] = nums;
    }

    std::cout<<"entered numbers: ";
    for(int i : get(v1)) std::cout<<i<<" ";
    std::cout<<std::endl;

    return 0;
}