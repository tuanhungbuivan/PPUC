#include <iostream>
#include <vector>

// drill 4
void print_array10(std::ostream& os, int* a)
{
    for(int i=0;i<10;i++){
        os << a[i] << " ";
    }
    os << std::endl;
}

// drill 7
void print_array(int* a, int n)
{
    for(int i=0;i<n;i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void print_vec(std::vector<int> v, int n)
{
    for(int i=0;i<n;i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // drill 1
    int *a1 = new int[10];

    // drill 2

    for(int i=0; i<10;i++){
        std::cout << a1[i] << " ";
    }
    std::cout << std::endl;

    // drill 3
    delete[] a1;

    // drill 5
    int *a2 = new int[10];
    for(int i=0;i<10;i++){
        a2[i] = 101 + i;
    }
    print_array10(std::cout,a2);
    delete[] a2;

    // drill 6
    int *a3 = new int[11];
    for(int i=0;i<11;i++){
        a3[i] = 101 + i;
    }
    for(int i=0;i<11;i++){
        std::cout << a3[i] << " ";
    }
    std::cout << std::endl;
    delete[] a3;

    // drill 8
    int *a4 = new int[20];
    for(int i=0;i<20;i++){
        a4[i] = 101+i;
    }
    print_array(a4,20);
    delete[] a4;

    // drill 10
    std::vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(101+i);
    }
    print_vec(v1,10);

    return 0;
}