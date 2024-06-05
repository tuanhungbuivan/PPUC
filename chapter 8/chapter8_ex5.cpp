#include <iostream>
#include <vector>

void rev1(std::vector<int> v)
{
    std::vector<int> v1;

    for(int i = v.size()-1; i >= 0; i--){
        v1.push_back(v[i]);
    }

    for(int i = 0; i < v1.size(); i++){
        std::cout << v1[i] << " ";
    }
    std::cout << '\n';
}

void rev2(std::vector<int>& v)
{
    for(int i = 0; i < v.size()/2; i++){
        std::swap(v[i],v[v.size()-i-1]);
    }

    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
}

int main()
{

    std::vector<int> v;
    for(int i = 0; i < 6;i ++){
        v.push_back(i+1);
    }

    rev1(v);
    rev2(v);
}