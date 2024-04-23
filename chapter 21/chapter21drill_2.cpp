#include <iostream>
#include <map>
#include <iomanip>
#include <iterator>
#include <numeric>

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T,U>& p)
{
    os << std::setw(15) << std::left << p.first << '\t' << p.second;
    return os;
};

template<typename iter>
void print(iter first, iter last)
{
    while(first != last){
        std::cout<<*first<<'\n';
        ++first;
    }
}
// 2.5
void read(std::map<std::string,int>& msi)
{
    std::string s;
    int i;
    std::cin>>s>>i;
    if(!std::cin) std::cout<<"error \n";
    msi[s] = i; 
}

template<typename T>
struct map_add{
    T operator()(T v, const std::pair<std::string,T>& p)
    {
        return v + p.second;
    }
};

int main()
{
    // 2.1
    std::map<std::string,int> msi;

    // 2.2
    msi["lecture"] = 21;
    msi["university"] = 35;
    msi["education"] = 15;
    msi["school"] = 99;
    msi["kindergarten"] = 105;
    msi["river"] = 5;
    msi["city"] = 10;
    msi["capital"] = 70;
    msi["software"] = 88;
    msi["hardware"] = 43;
    // 2.3
    print(msi.begin(),msi.end());
    std::cout<<'\n';
    // 2.4
    std::cout<<"after deleting: \n";
    typedef std::map<std::string,int>::const_iterator msi_temp;
    msi_temp s = std::next(msi.begin(),2);
    while(s!=msi.end()) s = msi.erase(s);
    print(msi.begin(),msi.end());
    std::cout<<'\n';
    // 2.6
    /*std::cout<<"after reading: \n";
    for(int i =0 ;i<10;i++){
        read(msi);
    }*/

    std::cout<<'\n';
    print(msi.begin(),msi.end());
    // 2.8
    int sum = 0;
    sum = std::accumulate(msi.begin(),msi.end(),sum,map_add<int>());
    std::cout<<"sum of reading: "<< sum << '\n';
    // 2.9
    std::map<int,std::string> mis;
    // 2.10
    for(s = msi.begin(); s!=msi.end();s++){
        mis[s->second] = s->first;
    }
    // 2.11
    print(mis.begin(),mis.end());
    std::cout<<'\n';
}