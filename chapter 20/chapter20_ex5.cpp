#include <iostream>
#include <vector>

template<class T>
std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
    T element;
    while(is >> element){
        v.push_back(element);
    }

    while(is.fail() && !is.eof()){
        is.clear();
        std::string temp;
        is >> temp;
    }
    
    return is;   
}

template<>
std::istream& operator>>(std::istream& is, std::vector<std::string>& v)
{
    std::string element;
    while(true){
        is >> element;
        if(element == "quit"){
            break;
        }
        v.push_back(element);
        
    }
    return is;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    for(int i=0; i<v.size(); i++){
        os << v[i] << " ";
    }
    return os;
}

int main()
{
    std::vector<int> vi;
    std::vector<double> vd;
    std::vector<std::string> vs;

    std::cout << "Enter vector of doubles: ";
    std::cin >> vd;
    std::cout << "Enter vector of integers: ";
    std::cin >> vi;
    std::cout << "Enter vector of strings: ";
    std::cin >> vs;

    std::cout << vd << "\n" << vi << "\n" << vs << "\n";

    return 0;
}