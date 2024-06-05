#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <algorithm>

template<class Iter, class T>
int custom_count_if(Iter first, Iter last, T p)
{
    int counter = 0;
    while(first != last){
        if(p(*first)){
            counter++;
        }
        first++;
    }
    return counter;
}

// Predicate class to check if a value is greater than a given value
template<class T>
class greater {
private:
    T val;

public:
    greater(T val) : val(val) {}
    bool operator()(const T& value) const { return value > val; }
};

// Predicate class to check if a value is lesser than a given value
template<class T>
class lesser {
private:
    T val;

public:
    lesser(T val) : val(val) {}
    bool operator()(const T& value) const { return value < val; }
};

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
        int ctr = custom_count_if(v.begin(), v.end(), greater<int>(val));

        std::cout << "number " << val << " appeared: " << ctr << " time" <<(ctr!=1 ? "s " : " ") << '\n';
    }

    return 0;
}