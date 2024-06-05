#include <iostream>
#include <vector>

std::vector<int> str_length(const std::vector<std::string>& s)
{
    std::vector<int> length;
    for(int i=0;i<s.size();i++){
        length.push_back(s[i].size());
    }

    return length;
}

std::string longest(const std::vector<std::string>& s)
{
    std::string ans;
    int max = 0;
    for(int i=0;i<s.size();i++){
        if(s[i].size() > max) {
            max = s[i].size();
            ans = s[i];
        }
    }
    return ans;
}

std::string shortest(const std::vector<std::string>& s)
{
    std::string ans;
    int min = INT_MAX;
    for(int i=0;i<s.size();i++){
        if(s[i].size() < min) {
            min = s[i].size();
            ans = s[i];
        }
    }
    return ans;
}

int main()
{
    std::vector<std::string> words;

    words.push_back("my");
    words.push_back("name");
    words.push_back("aint");
    words.push_back("marcin");

    for(int i=0;i<words.size();i++){
        std::cout<<words[i]<<" ";
    }
    std::cout<<'\n';

    std::vector<int> length = str_length(words);

    /*for(int i=0;i<length.size();i++){ 
        std::cout<<words[i]<<": "<<length[i]<<'\n';
    }*/
    
    std::cout<<"\nLongest: "<< longest(words) <<"\nShortest: "<< shortest(words);
}