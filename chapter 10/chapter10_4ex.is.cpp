//  Modify the store_temp.cpp program from exercise 2 to include a temperature
//  suffix c for Celsius or f for Fahrenheit temperatures. Then modify the
//  temp_stats.cpp program to test each temperature, converting the Celsius
//  readings to Fahrenheit before putting them into the vector.

#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <ctime>
#include <algorithm>

const std::string if_name{"file10.4.1.txt"};
constexpr size_t no_reading{50};
constexpr int min_hour {0};
constexpr int max_hour{23};
constexpr int min_temp{-150};
constexpr int max_temp{150};

constexpr int fahrenheit{0};
constexpr int celsius{1};
constexpr char fahrenehit_suffix{'f'};
constexpr char celsius_suffix{'c'};

struct Reading{
    int hour;
    double temperature;
};

double ctof(double c) // Converts Fahrenheit to Celsius
{
    if (c < -273.15) {std::cout<<"error temperature too low, more than possible \n"; return 0;}
    return c*9.0/5+32; 
}

std::istream& operator>>(std::istream& is, Reading& rhs)
{
    int hour(0);
    double temperature(0);
    char unit('f');

    is >> hour >> temperature >> unit;

    if(is.eof()) return is;
    
    if((hour > max_hour) || (hour < min_hour) 
    || (unit != fahrenehit_suffix) && (unit != celsius_suffix)){
        is.clear(std::ios_base::badbit);
        return is;
    }

    if(unit == celsius_suffix ) temperature = ctof(temperature);
    if ((temperature < min_temp) || (temperature > max_temp)) {
        is.clear(std::ios_base::failbit);
        return is;
    }

    rhs = Reading{hour, temperature};

    return is;
}

std::ostream& operator<<(std::ostream& os, const Reading& r)
{
    os<<"Hour: "<< r.hour << " , Temperature: "<< r.temperature;
    return os;
}

void get_reading(std::vector<Reading>& v, const std::string& file)
{
    std::ifstream ist(file);
    if(!ist) {std::cout<<"cant read file \n"; return;}
    ist.exceptions(ist.exceptions()| std::ios_base::badbit);

    for(Reading r; ist >> r;){
        v.push_back(r);
    }

    if(ist.eof()) ist.clear();
    if(ist.fail()) {std::cout<<"Not well formated file \n"; return; }
}

double reading_mean(std::vector<Reading>& v)
{
    double sum = 0;
    for(Reading n : v){
        sum += n.temperature;
    }
    return sum/v.size();
}

double reading_mediana(std::vector<Reading>& v)
{

    std::vector<double> temp;
    
    for(Reading r : v){
        temp.push_back(r.temperature);
    }

    std::sort(temp.begin(),temp.end());
    if(temp.size()%2 == 1) return temp[temp.size()/2];

    return temp[temp.size()/2 - 1];

}

void print(std::vector<Reading>& v)
{
    for(Reading r : v) std::cout << r << std::endl;
}

int main()
{
    std::vector<Reading> v;

    get_reading(v, if_name);

    //print(v);

    std::cout << "Got " << v.size() << " temperature readings from file "
         << if_name << ".\n";
    std::cout << "Temperature mean: " << reading_mean(v) << '\n';
    std::cout << "Temperature median: " << reading_mediana(v) << '\n';
    return 0;
}