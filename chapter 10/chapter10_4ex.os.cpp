//  Modify the store_temp.cpp program from exercise 2 to include a temperature
//  suffix c for Celsius or f for Fahrenheit temperatures. Then modify the
//  temp_stats.cpp program to test each temperature, converting the Celsius
//  readings to Fahrenheit before putting them into the vector.

#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <ctime>

const std::string of_name{"file10.4.1.txt"};
constexpr size_t no_reading{50};
constexpr int min_hour {0};
constexpr int max_hour{23};
constexpr double min_temp{-100};
constexpr double max_temp{150};

constexpr int fahrenheit{0};
constexpr int celsius{1};
constexpr char fahrenehit_suffix{'f'};
constexpr char celsius_suffix{'c'};


struct Reading{
    int hour;
    double temperature;
    //Reading(int h, double t) : hour(h) , temperature(t) {}
};

double ftoc(double f) // Converts Fahrenheit to Celsius
{
    if (f < -459.67) {std::cout<<"error temperature too low, more than possible \n"; return 0;}
    return (f-32.0)*5/9;
}

std::ostream& operator<<(std::ostream& os, const Reading& rhs)
{
    os << rhs.hour << ' ' 
       << std::fixed << std::setprecision(2) << rhs.temperature;
    return os;
}

Reading random_numbers(std::default_random_engine& numbers)
{
    std::uniform_int_distribution<int> hour_dist(min_hour,max_hour);
    std::uniform_real_distribution<double> temp_dist(min_temp,max_temp);

    Reading new_reading;

    new_reading.hour = hour_dist(numbers);
    new_reading.temperature = temp_dist(numbers);

    return new_reading;
}

void write(const std::string& file)
{
    std::ofstream ost(file);
    if(!ost) { std::cout<<"cant read file \n"<<file; return;}

    std::default_random_engine numbers(std::time(nullptr));
    std::uniform_int_distribution<int> unit_dist(fahrenheit, celsius);

    for(size_t i = 0; i < no_reading; i++){
        int unit = unit_dist(numbers);
        Reading reading(random_numbers(numbers));

        ost << reading.hour << ' ';
        if (unit == fahrenheit)
            ost << std::fixed << std::setprecision(2)
                << reading.temperature << ' '<< fahrenehit_suffix << '\n';
        else
            ost << std::fixed << std::setprecision(2)
                << ftoc(reading.temperature) << ' '<< celsius_suffix << '\n';
    }
}

int main()
{
    write(of_name);
    std::cout << no_reading << " temperatures where written into file: "
        << of_name << '\n'; 

    return 0;
}