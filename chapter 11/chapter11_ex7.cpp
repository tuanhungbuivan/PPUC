#include <iostream>
#include <vector>
#include <string>

void convert(std::string& a)
{

    for(int i=0;i<a.length();i++){
        a[i] = tolower(a[i]);
    }

    std::vector<std::pair<std::string, std::string>> contractions = {
        {"don't" , "do not"},
        {"can't" , "can not"}
        
    };

    for(size_t i=0; i<a.length();){
        for(const auto& contraction : contractions){
            if(a.compare(i, contraction.first.length(), contraction.first) == 0){
                a.replace(i, contraction.first.length(), contraction.second);

                i += contraction.second.length();
                break;
            }
        }
        i++;
    }
}

int main()
{

    std::string a ="I can't believe why people don't like C++";

    convert(a);

    std::cout << a << std::endl;
    return 0;
}