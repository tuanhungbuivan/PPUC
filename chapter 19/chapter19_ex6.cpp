#include <iostream>

template<class T>
class Number{
public:
    Number () : value(0) { }
    Number (T v) : value(v) { }

    Number(const Number& other) : value(other.value) { }

    Number& operator=(const Number& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    Number operator+(const Number& other) const{
        return Number(value + other.value);
    }
    Number operator-(const Number& other) const{
        return Number(value - other.value);
    }
    Number operator/(const Number& other) const{
        if(other.value == 0){
            std::cerr << "Error cant be divided by 0\n";
            exit(EXIT_FAILURE);
        }
        return Number(value / other.value);
    }
    Number operator*(const Number& other) const{
        return Number(value * other.value);
    }

    friend std::istream& operator>>(std::istream& is, Number& obj){
        is >> obj.value;

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Number& obj){
        os << obj.value << '\t';

        return os;
    }

    T getvalue() const{
        return value;
    }

    // Modulus operator (only enabled for integral types)
    template <typename U = T>
    typename std::enable_if<std::is_integral<U>::value, Number>::type
    operator%(const Number& other) const {
        if (other.value == 0) {
            throw std::runtime_error("Division by zero");
        }
        return Number(value % other.value);
    }

private:
    T value;
};

int main()
{
   // Testing with int
    Number<int> a(5), b(3);
    
    // Test arithmetic operators
    Number<int> c = a + b;
    Number<int> d = a - b;
    Number<int> e = a * b;
    Number<int> f;
    try {
        f = a / b;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test modulus operator
    Number<int> g;
    try {
        g = a % b;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test I/O operators
    std::cout << "Enter an integer value for h: ";
    Number<int> h;
    std::cin >> h;

    // Print results
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = a + b = " << c << std::endl;
    std::cout << "d = a - b = " << d << std::endl;
    std::cout << "e = a * b = " << e << std::endl;
    std::cout << "f = a / b = " << f << std::endl;
    std::cout << "g = a % b = " << g << std::endl;
    std::cout << "h = " << h << std::endl;

    // Test assignment and copy constructor
    Number<int> i = h;
    std::cout << "i (copy of h) = " << i << std::endl;

    Number<int> j;
    j = a;
    std::cout << "j (assigned from a) = " << j << std::endl;

    // Testing with double
    Number<double> x(5.5), y(2.2);

    // Test arithmetic operators
    Number<double> z = x + y;
    Number<double> w = x - y;
    Number<double> u = x * y;
    Number<double> v;
    try {
        v = x / y;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Print results for double
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = x + y = " << z << std::endl;
    std::cout << "w = x - y = " << w << std::endl;
    std::cout << "u = x * y = " << u << std::endl;
    std::cout << "v = x / y = " << v << std::endl;

    // Testing modulus with double (should not compile)
    // Number<double> m = x % y; // This line should cause a compile error

    return 0;
}