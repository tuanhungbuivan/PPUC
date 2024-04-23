//  Write a program that creates a file of data in the form of the temperature
//  Reading type defined in §10.5. For testing, fill the file with at least 50
//  "temperature readings". Call this program store_temps.cpp and the file it
//  creates raw_temps.txt.

#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <ctime>

const std::string of_name{"file10.2.txt"};
constexpr size_t no_reading{50};
constexpr int min_hour {0};
constexpr int max_hour{23};
constexpr double min_temp{-100};
constexpr double max_temp{150};

struct Reading{
    int hour;
    double temperature;
    //Reading(int h, double t) : hour(h) , temperature(t) {}
};

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

    for(size_t i = 0; i < no_reading; i++){
        ost << random_numbers(numbers) << '\n';
    }
}

int main()
{
    write(of_name);
    std::cout << no_reading << " temperatures where written into file: "
        << of_name << '\n'; 

    return 0;
}