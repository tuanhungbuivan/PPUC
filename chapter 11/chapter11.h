#ifndef PUNCT_STREAM_H
#define PUNCT_STREAM_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

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

#endif // PUNCT_STREAM_H

