#include <iostream>
#include <map>

class Money{
public:
    enum class Currency{
        USD,
        DKK,
        JPY,
        PLN
    };

    Money(double amount, Currency currency);

    double getAmount() const { return amount; }
    Currency getCurrency() const { return currency; }

    static double getConversionRate(Currency from, Currency to) {
        return conversion_table[from] / conversion_table[to];
    }

    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    Money operator*(double fractor) const;
    Money operator/(double divisor) const;

    friend std::ostream& operator<<(const std::ostream& os, const Money& money);

private:
    double amount;
    Currency currency;

    static std::map<Currency, double> conversion_table;
};

std::map<Money::Currency, double> Money::conversion_table{
    {Currency::USD, 1.0},
    {Currency::DKK, 0.2},
    {Currency::JPY, 0.01},
    {Currency::PLN, 0.25}
};

Money::Money(double amount, Currency currency) : amount(amount), currency(currency) { }

Money Money::operator+(const Money& other) const{
    if(currency != other.currency){
        std::cerr << "Error different currencies\n";
        return Money(0.0, currency);
    }

    return Money(amount + other.amount, currency);
}

Money Money::operator-(const Money& other) const{
    if(currency != other.currency){
        std::cerr << "Error different currencies\n";
        return Money(0.0, currency);
    }

    return Money(amount - other.amount, currency);
}

Money Money::operator*(double factor) const{
    return Money(amount * factor, currency);
}

Money Money::operator/(double divisor) const{
    if(divisor == 0){
        std::cerr << "Divisor cant be 0\n";
        return Money(0.0, currency);
    }

    return Money(amount / divisor, currency);
}

std::ostream& operator<<(std::ostream& os, const Money& money){
    os << money.getAmount() << " ";
    switch (money.getCurrency())
    {
    case Money::Currency::USD:
        os << "USD";
        break;
    case Money::Currency::DKK:
        os << "DKK";
        break;
    case Money::Currency::JPY:
        os << "JPY";
        break;
    case Money::Currency::PLN:
        os<< "PLN";
        break;
    }

    return os;
}

int main()
{
    Money money1(10.50, Money::Currency::USD);
    Money money2(20.75, Money::Currency::USD);
    Money money3(150, Money::Currency::DKK);
    Money money4(150, Money::Currency::JPY);
    Money money5(150, Money::Currency::PLN);

    std::cout << "Money 1: " << money1 << std::endl;
    std::cout << "Money 2: " << money2 << std::endl;
    std::cout << "Money 3: " << money3 << std::endl;
    std::cout << "Money 4: " << money4 << std::endl;
    std::cout << "Money 5: " << money5 << std::endl;

    Money sum = money1 + money2;
    std::cout << "Sum of money 1 and money 2: " << sum << std::endl;

    Money difference = money2 - money1;
    std::cout << "Difference of money 2 and money 1: " << difference << std::endl;

    Money converted1 = money3 * 0.15; // Convert DKK to USD using the conversion rate
    std::cout << "Converted money 3(DKK) to USD: " << converted1 << std::endl;

    Money converted2 = money4 * 0.01; // Convert JPY to USD using the conversion rate
    std::cout << "Converted money 4(JPY) to USD: " << converted2 << std::endl;

    Money converted3 = money5 * 0.25; // Convert PLN to USD using the conversion rate
    std::cout << "Converted money 5(PLN) to USD: " << converted3 << std::endl;

    return 0;
}