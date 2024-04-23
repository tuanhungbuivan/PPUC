/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
*/

#include "chapter11.h"

/*
class Punct_stream {
public:
    Punct_stream(std::istream& is)
        : source{is}, sensitive{true}{ }
    
    void whitespace(const std::string& s) {white = s;}
    void add_white(char c) {white += c;}
    bool is_whitespace(char c);
    void case_sensitive(bool b){sensitive = b;}
    bool is_case_sensitive() {return sensitive;}

    Punct_stream& operator>>(std::string& s);
    operator bool();

private:
    std::istream& source;
    std::istringstream buffer;
    std::string white;
    bool sensitive;
};
*/

Punct_stream& Punct_stream::operator>>(std::string& s)
{
    while(true){
        while(!(buffer>>s)){
            if(buffer.bad() || source.eof()) return *this;
            buffer.clear();

            std::string line;
            std::getline(source,line);

            for(char& ch : line){
                if(is_whitespace(ch)) ch = ' ';
                else if (!sensitive) ch = std::tolower(ch);
            }

            buffer.str(line);

        }
        if (!is_whitespace(s.back())) return *this;
    }
    
    return *this;
}

bool Punct_stream::is_whitespace(char c)
{
    for(char w : white){
        if(c == w) return true;
    }
    return false;
}

Punct_stream::operator bool()
{
    return !(source.fail() || source.bad()) && source.good();
}

int main()
{
    Punct_stream ps(std::cin);
    ps.whitespace(";:,.?(){}<>/&$%!@#*");
    ps.case_sensitive(false);

    std::cout<<"please enter words: \n";
    std::vector<std::string> vs;
    std::string words;
    while(ps>>words){
        vs.push_back(words);
        if(words == "quit") break;
    }
        
    std::sort(vs.begin(),vs.end());
    for(int i = 0; i < vs.size(); i++){
        if(i==0 || vs[i] != vs[i+1]) std::cout<<vs[i]<<'\n';
    }

    return 0;
}




