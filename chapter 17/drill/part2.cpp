#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    // drill 1
    int a1 = 7;
    int *p1 = &a1;

    // drill 2
    std::cout << *p1 << '\t' << p1 << '\n';

    // drill 3
    int *p2 = new int[7];
    for(int i=0;i<7;i++){
        p2[i] = pow(2,i);
    }

    // drill 4
    std::cout << *p2 << '\n';
    for(int i=0;i<7;i++){
        std::cout << p2[i] << " "; 
    }
    std::cout << '\n';
    
    // drill 5
    int* p3 = p2;

    // drill 6
    p1 = p2;

    // drill 7
    p3 = p2;

    // drill 8
    std::cout << "p1: " << p1 << '\t' << *p1 << '\n';
    std::cout << "p2: " << p2 << '\t' << *p2 << '\n';
    std::cout << "p3: " << p3 << '\t' << *p3 << '\n';

    // drill 9
    delete[] p2;
    p3 = 0;

    // drill 10
    p1 = new int[10];
    for(int i=0;i<10;i++){
        p1[i] = pow(2,i);
    }

    // drill 11
    p2 = new int[10];

    // drill 12
    p2 = p1;
    for(int i=0;i<10;i++){
        std::cout <<  p2[i] << " ";
    }
    std::cout << '\n';

    // drill 13;
    std::vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(pow(2,i));
    }
    std::vector<int> v2 = v1;
    for(int i=0;i<10;i++){
        std::cout << v2[i] << " ";
    }   
    std::cout << '\n'; 
    return 0;
}