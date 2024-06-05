#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void isvowel(std::string& str)
{
    str.erase(std::remove_if(str.begin(),str.end(),[](char c){
        return std::tolower(c) == 'a' || std::tolower(c) == 'e' || std::tolower(c) == 'i' ||
               std::tolower(c) == 'o' || std::tolower(c) == 'u';
    }),str.end());
}

void removevowels(const std::string& name)
{

    std::ifstream ifs(name);
    if (!ifs.is_open()){
        std::cerr << "Cant open file";
        return;
    }

    std::string content, line;
    while(std::getline(ifs,line)){
        content += line +'\n';
    }

    isvowel(content);

    ifs.close();

    std::string name1 = "ofs_3.txt";
    std::ofstream ofs(name1);

    ofs << content;
    ofs.close();

}

int main()
{
    std::string name = "ifs_3.txt";

    removevowels(name);
}