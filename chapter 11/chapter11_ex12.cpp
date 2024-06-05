#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

void reverse(std::string& s)
{
    for(int i=0;i<s.size()/2;i++){
        std::swap(s[i],s[s.size()-i-1]);
    }
}

void reverse1(std::vector<std::string>& s){
    for(int i = 0;i<s.size()/2;i++){
        std::swap(s[i],s[s.size()-i-1]);
    }
}

void ex12()
{
    std::ifstream ifs("ifs_12.txt");
    if(!ifs){
        std::cerr << "Error cant open file '\n";
        return;
    }
    
    std::string words;
    while(ifs >> words){
        reverse(words);
        std::cout << words << " ";
    }
    std::cout << '\n';

    ifs.close();
}

void ex13()
{
    std::ifstream ifs("ifs_12.txt");
    if(!ifs){
        std::cerr << "Error cant open file '\n";
        return;
    }
    
    std::string words;
    std::vector<std::string> ans;
    while(ifs >> words){
        ans.push_back(words);
    }

    reverse1(ans);
    for(int i=0;i<ans.size();i++){
        std::cout << ans[i] << " ";
    }
    ifs.close();
}

int main()
{
    ex12();
    ex13();

    return 0;
}