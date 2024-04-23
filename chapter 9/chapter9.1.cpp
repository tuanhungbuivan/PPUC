#include <iostream>
#include <ostream>

struct Date{
    /* data */
    int y;
    int m;
    int d;
};

void init_day(Date& dd, int y, int m, int d)
{
    if(d < 1 || d > 31) {std::cout<<"Invalid day \n"; return;}
    if(m < 1 || m > 12) {std::cout<<"Invalid month \n"; return;}
    
    dd.d = d;
    dd.m = m;
    dd.y = y;
}

void add_day(Date& dd, int n)
{
    dd.d += n;

    if( dd.d > 31 ) {dd.m++; dd.d -= 31;}
    if( dd.d < 1 )  {dd.m--; dd.d += 31;}

    if( dd.m > 12)  {dd.y++; dd.m -= 12;}
    if( dd.m < 1)   {dd.y--; dd.m += 12;}
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}


int main()
{
    Date today;
    init_day(today, 2024, 03, 20);
    std::cout<<today<<'\n';

    Date tomorrow(today);
    add_day(tomorrow,1);
    std::cout<<tomorrow<<'\n';

    Date test;
    init_day(test, 2024, 12 ,31);
    add_day(test,6);
    std::cout<<test<<'\n';
    add_day(test, -6);
    std::cout<<test<<'\n';

    init_day(test, 2025, 1 ,5);
    add_day(test,-6);
    std::cout<<test<<'\n';
    add_day(test, +6);
    std::cout<<test<<'\n';

    Date test_invalid;
    init_day(test_invalid, 2024, 5, -10);

    return 0;
}