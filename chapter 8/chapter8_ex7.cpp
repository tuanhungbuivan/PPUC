#include <iostream>
#include <vector>
#include <algorithm>

int find_index(std::vector<std::string> name, std::string copy_name )
{
    for(int i = 0; i < name.size(); i++ ){
        if(name[i] == copy_name)
            return i;
    }

    return 0;
}

int main()
{
    std::vector<std::string> name;
    std::vector<double> age;

    name.push_back("marcin0");
    name.push_back("arcin1");
    name.push_back("rcin2");
    name.push_back("cin3");
    name.push_back("in4");

    for(int i = 0; i < 5; i++){
        age.push_back(i*5);
    }

    for(int i = 0; i < 5; i++){
        std::cout << name[i] << " " << age[i] << '\n';
    }
    std::vector<std::string> copy_name = name;
    std::vector<double> copy_age = age;

    sort(name.begin(),name.end());

    for(int i = 0; i < 5; i++){
        age[i] = copy_age[find_index(copy_name,name[i])];
    }
    std::cout << "\nAfter sorting: \n";
    for(int i = 0; i < 5; i++){
        std::cout << name[i] << " " << age[i] << '\n';
    }
    
    

}