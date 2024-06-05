#include <iostream>
#include <ostream>

class Date{
public:
    Date(int yy, int mm, int dd);
    void add_day(int d);
    int day()   const {return d;}
    int month() const {return m;}
    int year()  const {return y;}
private:
    int y, m, d;
};

Date::Date(int yy, int mm, int dd)
{

    
    if(dd < 1 || dd > 31) {std::cout<<"Invalid day \n"; return;}
    if(mm < 1 || mm > 12) {std::cout<<"Invalid month \n"; return;}
    
    d = dd;
    m = mm;
    y = yy;
}

void Date::add_day(int n)
{
    int n_d = n % 31;          // days out of months, to increase
    int n_m = (n / 31) % 12;   // months out of years, to increase
    int n_y = n / (31*12);     // years to increase

    y += n_y;
    m += n_m;
    d += n_d;


    if( d > 31 ) {m++; d -= 31;}
    if( d < 1 )  {m--; d += 31;}

    if( m > 12)  {y++; m -= 12;}
    if( m < 1)   {y--; m += 12;}
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}


int main()
{
    Date today(2024, 03, 20);
    std::cout<<today<<'\n';

    Date tomorrow(today);
    tomorrow.add_day(1);
    std::cout<<tomorrow<<'\n';

    Date test(2024, 12 ,31);
    test.add_day(6);
    std::cout<<test<<'\n';
    test.add_day(-6);
    std::cout<<test<<'\n';

    test = Date(2025, 1 ,5);
    test.add_day(-6);
    std::cout<<test<<'\n';
    test.add_day(+6);
    std::cout<<test<<'\n';

    Date test_invali(2024, 5, -10);

    return 0;
}