#include <iostream>
#include <vector>
#include <algorithm>

struct Vector_ex{
    Vector_ex();
    int mini;
    int maxi;
    double mean;
    int median;
};

Vector_ex::Vector_ex() 
    : mini(0), maxi(0), mean(0), median(0) { }

int maxv1(const std::vector<int>& v)
{
    int max = INT_MIN;

    for(int i=0;i<v.size();i++){
        if(v[i]>max){
            max = v[i];
        }
    }

    return max;
}

int minv1(const std::vector<int>& v)
{
    int min = INT_MAX;

    for(int i=0;i<v.size();i++){
        if(v[i]<min){
            min = v[i];
        }
    }

    return min;
}

double meanv1(const std::vector<int>& v)
{
    double sum = 0;
    for(int i=0;i<v.size();i++){
        sum += v[i];
    }

    return sum / v.size();
}

int medianv1(const std::vector<int>& v)
{
    std::vector<int> sorted_v = v; 
    std::sort(sorted_v.begin(), sorted_v.end());

    int size = sorted_v.size();
    if (size % 2 == 0) {
        // Even number of elements, return the average of the two middle elements
        return (sorted_v[size / 2 - 1] + sorted_v[size / 2]) / 2;
    } else {
        // Odd number of elements, return the middle element
        return sorted_v[size / 2];
    }
}

Vector_ex get_data(const std::vector<int>& v)
{
    Vector_ex vec_prop;
    vec_prop.mini = minv1(v);
    vec_prop.maxi = maxv1(v);
    vec_prop.mean = meanv1(v);
    vec_prop.median = medianv1(v);

    return vec_prop;
}

int main()
{
    std::vector<int> v;
    for(int i = 0; i < 10;i++){
        if(i % 2 == 0 ) v.push_back(i*2+3);
        else v.push_back(i*2+7);
    }

    Vector_ex vec_prop = get_data(v);

    for(int i=0;i<10;i++){
        std::cout<< v[i] <<" ";
    }

    std::cout <<"\nMin: " << vec_prop.mini <<"\nMax: "<< vec_prop.maxi <<"\nMean: " << vec_prop.mean <<"\nMeadian: "<< vec_prop.median<<'\n';


}