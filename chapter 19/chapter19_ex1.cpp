#include <iostream>
#include <vector>

template <typename T>
void f(std::vector<T>& v1, std::vector<T>& v2)
{
    for(int i=0;i<v1.size();i++){
        v1[i] += v2[i];
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    for(int i=0;i<v.size();i++){
        os << v[i] << " ";
    }
    os << '\n';
    return os;
}

int main()
{
    std::vector<int> v1;
    std::vector<int> v2;

    for(int i=0;i<10;i++){
        v1.push_back(i+1);
        v2.push_back(i*2);
    }

    std::cout << "Vector v1: " << v1;
    std::cout << "Vector v2: " << v2;
    f(v1,v2);

    std::cout << "Vector v1 after f(v1,v2): " << v1;

    return 0;
}