//  Write a program that reads the data from raw_temps.txt created in exercise
//  2 into a vector and then calculates the mean and median temperatures in
//  your data set. Call this program temp_stats.cpp.

#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <ctime>
#include <algorithm>

const std::string if_name{"file10.2.txt"};
constexpr size_t no_reading{50};
constexpr int min_hour {0};
constexpr int max_hour{23};
constexpr int min_temp{-50};
constexpr int max_temp{50};

struct Reading{
    int hour;
    double temperature;
};

std::istream& operator>>(std::istream& is, Reading& rhs)
{
    int hour(0);
    double temperature(0);

    is >> hour >> temperature;
    
    if((hour > max_hour) || (hour < min_hour) 
    || (temperature > max_temp) || (temperature < min_temp)){
        is.clear(std::ios_base::badbit);
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
    if(ist.fail()) {std::cout<<"not well formated file \n"; return; }
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

    print(v);

    std::cout << "Got " << v.size() << " temperature readings from file "
         << if_name << ".\n";
    std::cout << "Temperature mean: " << reading_mean(v) << '\n';
    std::cout << "Temperature median: " << reading_mediana(v) << '\n';
    return 0;
}