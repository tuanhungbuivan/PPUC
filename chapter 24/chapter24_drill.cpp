#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>

#include "Matrix.h"
#include "MatrixO.h"

using namespace Numeric_lib;

void ex4()
{
    std::cout<<"\nEnter number that gonna be sqrt: ";
    double x;
    std::cin>>x;
    while(std::cin>>x){
        errno = 0;
        double x2 = sqrt(x);
        if(errno == EDOM) std::cerr << "sqrt() not defined \n";
        else std::cout << "sqrt( " << x << " ) is " << x2 << '\n';
    }
    
}

void ex5()
{
    std::cin.clear();
    std::cin.ignore();

    std::cout<<"Input 10 floating points: ";
    Matrix<double> m(10);
    double d;
    for(int i=0;i<10;i++){
        std::cin >> d;
        m[i] = d;
    }
    std::cout << "Matrix m(10): " << m << '\n';
}

void ex6()
{
    std::cout << "\nMultiplication table\n";
    int n, m;
    std::cout << "Enter n and then m \n";
    std::cin >> n  >> m;
    Matrix<int,2> mt(n,m);
    for (Index i = 0; i<mt.dim1(); ++i) {
        for (Index j = 0; j<mt.dim2(); ++j) {
            mt(i,j) = (i+1)*(j+1);
            std::cout << std::setw(5) << mt(i,j);
        }
        std::cout << '\n';
    }
}

void ex7()
{
    Matrix<std::complex<double>> m(10);
    //std::complex<double> c1(3.0, 4.0);
    //std::cout << "Real part: " << c1.real() << ", Imaginary part: " << c1.imag() << std::endl;
    std::cout<<"Enter 10 complex numbers: ";
    std::complex<double> x;
    for(int i=0;i<10;i++){
        std::cin>>x;
        m[i] = x;
    }

    std::complex<double> s;
    for(Index i=0;i<m.size();i++){
        s += m[i];
    }
    std::cout<<"\nSum of 10 complex numbers: "<<s<<'\n';
}

void ex8()
{
    Matrix<int,2> m(2,3);

    std::cout<<"Enter 6 numbers: ";
    int x;
    for(int i=0;i<m.dim1();i++){
        for(int j=0;j<m.dim2();j++){
            std::cin>>x;
            m(i,j) = x;
        }
    }
    std::cout<< m << '\n';
}

int main()
{
    // drill 1
    std::cout<<"sizeof: \n";
    std::cout<<"Char: " << sizeof(char) << '\n';
    std::cout<<"Short: " << sizeof(short) << '\n';
    std::cout<<"Int: " << sizeof(int) << '\n';
    std::cout<<"Long: " << sizeof(long) << '\n';
    std::cout<<"Float: " << sizeof(float) << '\n';
    std::cout<<"Double: " << sizeof(double) << '\n';
    std::cout<<"Int*: " << sizeof(int*) << '\n';
    std::cout<<"Double*: " << sizeof(double*) << '\n';

    // drill 2
    std::cout<<"\nsizeof Matrix: \n";
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);
    std::cout<<"Matrix<int> a(10): " << sizeof(a) << '\n';
    std::cout<<"Matrix<int> b(100): " << sizeof(b) << '\n';
    std::cout<<"Matrix<double> c(10): " << sizeof(c) << '\n';
    std::cout<<"Matrix<int,2> d(10,10): " << sizeof(d) << '\n';
    std::cout<<"Matrix<int,3> e(10,10,10): " << sizeof(e) << '\n';

    // drill 3
    std::cout << "\nNumber of elements: \n";
    std::cout << "a: " << a.size() << '\n';
    std::cout << "b: " << b.size() << '\n';
    std::cout << "c: " << c.size() << '\n';
    std::cout << "d: " << d.size() << '\n';
    std::cout << "e: " << e.size() << '\n';

    // drill 4
    //ex4();

    // drill 5
    //ex5();

    // drill 6
    //ex6();

    // drill 7
    //ex7();

    // drill 8
    ex8();

    return 0;
}