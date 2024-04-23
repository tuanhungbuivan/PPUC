#ifndef CHRONO_H
#define CHRONO_H

namespace Chrono{



enum class Month{
    jan  = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

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

std::ostream& operator<<(std::ostream& os, const Date& d);

}

#endif // CHRONO_H