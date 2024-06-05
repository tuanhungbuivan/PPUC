#include <iostream>
#include <vector>

// ex 9, 10

double max(std::vector<double> v)
{
    double max = INT_MIN;
    for(int i = 0; i<v.size();i++){
        if(max < v[i]){
            max = v[i];
        }
    }
    return max;
}

double comptueIndex(const std::vector<double>& price, const std::vector<double>& weight)
{
    if(weight.size() != price.size()) return -1;

    double index = 0;

    for(int i = 0; i < price.size(); i++){
        index += price[i] * weight[i];
    }

    return index;
}

int main()
{
    std::vector<double> price {1.2 , 10.5, 12.4};
    std::vector<double> weight {4.3, 8.9, 12.3};

    double index =  comptueIndex(price,weight);

    std::cout << index << '\n';

    double max_price = max(price);
    std::cout << max_price << '\n';
    return 0;
}