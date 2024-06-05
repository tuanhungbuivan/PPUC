#include <iostream>
#include <vector>
//drill 2, 3, 4, 5
template<typename T> struct S{
    T val;
    S(T s) :val(s){ } //drill 2
    T &get(); //drill 5
};



int main()
{
    //drill 3
    S<double> d(10.2);
    std::cout<<d.val<<'\n';

    S<std::string> s("my name is ");
    std::cout<<s.val<<'\n';

    S<char> c('!');
    std::cout<<c.val<<'\n';

    S<int> i(10);
    std::cout<<i.val<<'\n';

    S<std::vector<int>> v(std::vector<int>(5,10));
    for(int i : v.val) std::cout<<i<<" ";
    std::cout<<std::endl;

    //drill 4
    int nums;
    std::cout<<"enter numbers: ";
    S<std::vector<int>> v1(std::vector<int>(5));
    for(int i=0;i<5;i++){
        std::cin>>nums;
        v1.val[i] = nums;
    }

    std::cout<<"entered numbers: ";
    for(int i : v1.val) std::cout<<i<<" ";
    std::cout<<std::endl;

    return 0;
}