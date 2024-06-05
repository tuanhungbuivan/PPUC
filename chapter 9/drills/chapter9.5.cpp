#include <iostream>
#include "Chrono.h"

int main()
{
    using Chrono::Date;
    using Chrono::Month;

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