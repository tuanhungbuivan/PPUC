#include <regex>
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream in("drill_file.txt");
    if(!in) std::cerr<<"No file\n";

    //const std::string pat_string = "\w{2}\s*\d{5}(-\d{4})?";
    //std::regex pat{pat_string};
    std::regex pat{ R"(\w{2}\s*\d{5}(-\d{4})?)" };
    //std::cout<<"Post code pattern: " <<  pat_string << '\n';

    int lineno = 0;
    for(std::string line; std::getline(in,line);){
        ++lineno;
        std::smatch matches;
        if(regex_search(line,matches,pat)){
            std::cout << lineno << ": "<<matches[0] << '\n';
            if(1<matches.size() && matches[1].matched){
                std::cout<<"\t: "<<matches[1]<<'\n';
            }
        }
    }
}