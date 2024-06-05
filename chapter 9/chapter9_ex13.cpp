#include <iostream>

class Rational{
public:
    Rational(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if(denominator == 0){
            std::cerr << "Error denominator cannot be zero " << std::endl;
            exit(EXIT_FAILURE);
        }
        simplify();
    }

    void simplify()
    {
        int gcd = getGCD(numerator,denominator);
        numerator /= gcd;
        denominator /= gcd; 
    }

    int getGCD(int a, int b)
    {
        if(b == 0){
            return a;
        }
        return getGCD(b, a%b);
    }

    Rational operator+(const Rational& other) const{
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num,den);
    }

    Rational operator-(const Rational& other) const{
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num,den);
    }

    Rational operator*(const Rational& other) const{
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Rational(num,den);
    }

    Rational operator/(const Rational& other) const{
        if(other.denominator == 0){
            std::cerr << "Denominator cant be 0 " << std::endl;
            exit(EXIT_FAILURE);
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Rational(num,den);
    }

    bool operator==(const Rational& other) const{
        return (numerator == other.numerator && denominator == other.denominator);
    }

    bool operator!=(const Rational& other) const{
        return (numerator != other.numerator || denominator != other.denominator);
    }

    // Function to convert rational number to double
    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

    void display() const {
        std::cout << numerator << "/" << denominator;
    }

private:
    int numerator; 
    int denominator; 
};

int main()
{
    Rational r1(5, 6);
    Rational r2(2, 3);

    Rational addition = r1 + r2;
    Rational subtraction = r1 - r2;
    Rational multiplication = r1 * r2;
    Rational division = r1 / r2;

    std::cout << "Addition: ";
    addition.display();
    std::cout << std::endl;

    std::cout << "Subtraction: ";
    subtraction.display();
    std::cout << std::endl;

    std::cout << "Multiplication: ";
    multiplication.display();
    std::cout << std::endl;

    std::cout << "Division: ";
    division.display();
    std::cout << std::endl;

    std::cout << "Equality: ";
    std::cout << (r1 == r2 ? "True" : "False") << std::endl;

    std::cout << "Conversion to double: " << r1.toDouble() << std::endl;

    return 0;
}