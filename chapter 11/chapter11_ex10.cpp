#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> ex10(const std::string& s)
{
    std::istringstream ss(s);
    std::string words;
    std::vector<std::string> ans;
    while(ss >> words){
        ans.push_back(words);
    }

    return ans;
}

bool substring(const std::string& s, const std::string& w)
{
    for(int i=0;i<s.size()-w.size();i++){
        int count = 0;
        for(int j=0;j<w.size();j++){
            if(s[i] == w[j]){
                count++;
            }else{
                count = 0;
            }
        }
        if(count == w.size()){
            return true;
        }
    }
    return false;
}

std::vector<std::string> ex11(const std::string& s, const std::string& w)
{
    std::istringstream ss(s);
    std::string words;
    std::vector<std::string> ans;
    while(ss >> words){
        if(substring(words,w)){
            ans.push_back(words);
        }
    }

    return ans;
}

void print(std::vector<std::string>& s){
    for(int i=0;i<s.size();i++){
        std::cout << s[i] << '\n';
    }
}

int main()
{
    std::string s = "mom is really annoying, i cant stand my at all";
    std::string w = "a";

    std::vector<std::string> ans = ex10(s);
    //print(ans);

    std::vector<std::string> ans1 = ex11(s,w);
    print(ans1);

    
    return 0;
}