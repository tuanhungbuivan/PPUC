#include <iostream>

void ex1()
{
    int v=1;
    for(int i=0;i<sizeof(v)*8;i++){
        std::cout<<v<<' ';
        v<<=1;
    }
    std::cout<<'\n';
}

void ex2()
{
    unsigned int v1=1;
    for(int i=0;i<sizeof(v1)*8;i++){
        std::cout<<v1<<' ';
        v1<<=1;
    }
    std::cout<<'\n';
}


void ex3_4()
{   
    //  using hex literals define short unsigned int
    // a) every bit set
    // b) the lowest least significant bit set
    // c) the highest most significant bit set
    // d) the lowest byte set
    // e) the highest byte set
    // f) every second bit set and the lowest bit 1
    // g) every6 second bit set and the lowest bit 0

    // print

    short unsigned int a = 0xFFFF;
    short unsigned int b = 0x0001;
    short unsigned int c = 0x8000;
    short unsigned int d = 0x00FF;
    short unsigned int e = 0xFF00;
    short unsigned int f = 0xAAAA;
    short unsigned int g = 0x5553;
    std::cout << "Lowest least significant bit set: 0x" << std::hex << b << std::endl;
    std::cout << "Highest most significant bit set: 0x" << std::hex << c << std::endl;
    std::cout << "Lowest byte set: 0x" << std::hex << d << std::endl;
    std::cout << "Highest byte set: 0x" << std::hex << e << std::endl;
    std::cout << "Every second bit set and the lowest bit 1: 0x" << std::hex << f << std::endl;
    std::cout << "Every second bit set and the lowest bit 0: 0x" << std::hex << g << std::endl; 
}

void ex5()
{
    short unsigned int sui = 0;
    short unsigned int a = ~0;
    short unsigned int b = 1;
    short unsigned int c = 1 << 15;
    short unsigned int d = 1;
    d = (1 | 1 << 1);
    d |= d << 2;
    d |= d << 4;
    short unsigned int e = ~d;
    short unsigned int f = 1;
    f |= f << 2;
    f |= f << 4;
    f |= f << 8;
    short unsigned int g = ~f;
    std::cout << "Every bit set: 0x" << std::hex << a << std::endl;
    std::cout << "Lowest least significant bit set: 0x" << std::hex << b << std::endl;
    std::cout << "Highest most significant bit set: 0x" << std::hex << c << std::endl;
    std::cout << "Lowest byte set: 0x" << std::hex << d << std::endl;
    std::cout << "Highest byte set: 0x" << std::hex << e << std::endl;
    std::cout << "Every second bit set and the lowest bit 1: 0x" << std::hex << f << std::endl;
    std::cout << "Every second bit set and the lowest bit 0: 0x" << std::hex << g << std::endl; 
}

int main()
{
    // drill 1
    ex1();

    // drill 2
    ex2();

    // drill 3 and 4

    ex3_4();

    // drill 5
    ex5();

    return 0;
}