#include <iostream>
#include <vector>

template<typename T, typename U>
typename std::common_type<T,U>::type f(std::vector<T>& vt, std::vector<U>& vu)
{
    typename std::common_type<T,U>::type sum = 0;
    for (int i = 0; i<vt.size(); ++i) {
            sum += vt[i]*vu[i];
    }
    return sum;
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
    std::vector<double> v2;

    for(int i=0;i<10;i++){
        v1.push_back(i+1);
        v2.push_back(i*1.5);
    }

    std::cout << "Vector v1: " << v1;
    std::cout << "Vector v2: " << v2;
    f(v1,v2);

    std::cout << "Vector v1 after f(v1,v2): " << v1;

    return 0;
}