#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <algorithm>

template<class Iter, class T>
int custom_count(Iter first, Iter last, const T& val)
{
    int counter = 0;
    while(first != last){
        if(*first == val){
            counter++;
        }
        first++;
    }
    return counter;
}

int main()
{
    std::vector<int> v;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);

    for(int i = 1; i <= 100; ++i){
        v.push_back(distrib(gen));
    }

    for(auto p = v.begin(); p != v.end(); ++p){
        std::cout << *p << " ";
    }
    std::cout << '\n';

    int val;

    while(std::cin >> val){
        if(val == -1) break;
        int ctr = custom_count(v.begin(), v.end(), val);

        std::cout << "number " << val << " appeared: " << ctr << " time" <<(ctr!=1 ? "s " : " ") << '\n';
    }

    return 0;
}