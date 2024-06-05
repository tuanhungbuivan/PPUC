#include <ostream>
#include "Chrono.h"

namespace Chrono{

Month operator+(const Month& m, int n) {
    int r = static_cast<int>(m) + n;
    r %= 12;
    if (r == 0) r = 12;
    return static_cast<Month>(r);
}

Month operator-(const Month& m, int n) { return (m+(-n)); }
Month& operator+=(Month& m, int n) { m = m + n; return m; }

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

}