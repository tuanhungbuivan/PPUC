#include <iostream>

int ga[10] = {1,2,4,8,16,32,64,128,256,512};

void f(int a[],int n)
{
    int la[10];
    for(int i=0;i<n;i++){
        la[i] = a[i];
    }

    for(int i=0;i<n;i++){
        std::cout << la[i] << " ";
    }    
    std::cout << '\n';

    int* p = new int[n];
    for(int i=0;i<n;i++){
        p[i] = a[i];
    }
    for(int i=0;i<n;i++){
        std::cout << p[i] << " ";
    }    
    std::cout << '\n';

    delete[] p;
}

int main()
{
    f(ga,10);
    
    return 0;
}