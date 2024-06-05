#include <iostream>

class Int{
public:
    Int () : value(0) { }
    Int (int v) : value(v) { }

    Int(const Int& other) : value(other.value) { }

    Int& operator=(const Int& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    Int operator+(const Int& other) const{
        return Int(value + other.value);
    }
    Int operator-(const Int& other) const{
        return Int(value - other.value);
    }
    Int operator/(const Int& other) const{
        if(other.value == 0){
            std::cerr << "Error cant be divided by 0\n";
            exit(EXIT_FAILURE);
        }
        return Int(value / other.value);
    }
    Int operator*(const Int& other) const{
        return Int(value * other.value);
    }

    friend std::istream& operator>>(std::istream& is, Int& obj){
        is >> obj.value;

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Int& obj){
        os << obj.value << '\t';

        return os;
    }

    int getvalue() const{
        return value;
    }

private:
    int value;
};

int main()
{
    Int a(5), b(3);
    
    // Test arithmetic operators
    Int c = a + b;
    Int d = a - b;
    Int e = a * b;
    Int f;
    try {
        f = a / b;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test I/O operators
    std::cout << "Enter an integer value for g: ";
    Int g;
    std::cin >> g;

    // Print results
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = a + b = " << c << std::endl;
    std::cout << "d = a - b = " << d << std::endl;
    std::cout << "e = a * b = " << e << std::endl;
    std::cout << "f = a / b = " << f << std::endl;
    std::cout << "g = " << g << std::endl;

    // Test assignment and copy constructor
    Int h = g;
    std::cout << "h (copy of g) = " << h << std::endl;

    Int i;
    i = a;
    std::cout << "i (assigned from a) = " << i << std::endl;
}