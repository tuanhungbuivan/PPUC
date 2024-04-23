#include <iostream>
#include <ostream>

enum class Month{
    jan  = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator+(const Month& m, int n) {
    int r = static_cast<int>(m) + n;
    r %= 12;
    if (r == 0) r = 12;
    return static_cast<Month>(r);
}

Month operator-(const Month& m, int n) { return (m+(-n)); }
Month& operator+=(Month& m, int n) { m = m + n; return m; }

class Date{
public:
    class Invalid{};
    Date(int yy, Month m, int dd);
    void add_day(int d);
    int day()   const {return d;}
    Month month() const {return m;}
    int year()  const {return y;}
private:
    int y, d;
    Month m;
    bool is_valid();
};

Date::Date(int yy, Month mm, int dd)
        :y(yy), m(mm), d(dd)
{
    if (!is_valid()) throw Invalid();
}

bool Date::is_valid() {
    if (d < 1 || d > 31) return false;
    if (static_cast<int>(m) < 1 || static_cast<int>(m) > 12) return false;
    return true;
}

void Date::add_day(int n)
{
    int n_d = n % 31;          // days out of months, to increase
    int n_m = (n / 31) % 12;   // months out of years, to increase
    int n_y = n / (31*12);     // years to increase

    d += n_d;

    if( d > 31 ) {n_m++; d -= 31;}
    if( d < 1 )  {n_m--; d += 31;}

    if (static_cast<int>(Month::dec) < (static_cast<int>(m) + n_m)) n_y++;
    if (static_cast<int>(Month::jan) > (static_cast<int>(m) + n_m)) n_y--;


    m += n_m;
    y += n_y;

}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << static_cast<int>(d.month())
              << ',' << d.day() << ')';
}


int main()
{

    Date today(2024, Month::mar, 20);
    std::cout<<today<<'\n';

    Date tomorrow(today);
    tomorrow.add_day(1);
    std::cout<<tomorrow<<'\n';

    Date test(2024, Month::dec ,31);
    test.add_day(6);
    std::cout<<test<<'\n';
    test.add_day(-6);
    std::cout<<test<<'\n';

    test = Date(2025, Month::jan ,5);
    test.add_day(-6);
    std::cout<<test<<'\n';
    test.add_day(+6);
    std::cout<<test<<'\n';

    Date test_invali(2024, Month::jun, -10);

    return 0;
}