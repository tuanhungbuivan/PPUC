#include <iostream>

class Money{
public:
    Money(long int dollars = 0, int cents = 0){
        this->cents = dollars * 100L + cents; 
    }

    long int dollars(){
        return cents / 100;
    }

    int cents_amount(){
        return cents % 100;
    }

    Money operator+(const Money& other) const{
        long int total_cents = cents + other.cents;
        return Money(total_cents / 100, total_cents % 100);
    }

    Money operator-(const Money& other) const{
        long int total_cents = cents - other.cents;
        return Money(total_cents / 100, total_cents % 100);
    }

    Money operator*(double factor) const{
        long int total_cents = static_cast<long int>(cents * factor);
        return Money(total_cents / 100, total_cents % 100);
    }

    Money operator/(double divisor) const{
        if(divisor == 0){
            std::cerr << "Error cant divide by 0";
            exit(EXIT_FAILURE);
        }

        long int total_cents =  static_cast<long int>(cents / divisor);
        return Money(total_cents / 100, total_cents % 100);
    }

    void rounder(){
        int remains = cents % 100;
        if(remains >= 50){
            cents += (100 - remains);
        }else{
            cents += remains;
        }
    }

    void display(){
        std::cout << "(" << dollars() << " . " << (cents_amount() < 10 ? "0" : "") << cents_amount() << ")" << std::endl;
    }
private:
    long int cents;
};

int main()
{
    Money amount1(123, 45);
    Money amount2(67, 89);

    Money sum = amount1 + amount2;
    Money difference = amount1 - amount2;
    Money product = amount1 * 1.5; // Multiply by a factor
    Money quotient = amount1 / 2; // Divide by a divisor

    std::cout << "Amount 1: ";
    amount1.display();
    std::cout << std::endl;

    std::cout << "Amount 2: ";
    amount2.display();
    std::cout << std::endl;

    std::cout << "Sum: ";
    sum.display();
    std::cout << std::endl;

    std::cout << "Difference: ";
    difference.display();
    std::cout << std::endl;

    std::cout << "Product: ";
    product.display();
    std::cout << std::endl;

    std::cout << "Quotient: ";
    quotient.display();
    std::cout << std::endl;

    return 0;
}