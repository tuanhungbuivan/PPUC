#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

class Roman_int{
public:
    Roman_int(int n);
    Roman_int();

    int as_int() const;

    friend std::ostream& operator<<(std::ostream& os, const Roman_int& r);
    friend std::ostream& operator>>(std::ostream& is, Roman_int& r);

    Roman_int operator+(const Roman_int& other) const;
    Roman_int operator-(const Roman_int& other) const;
    Roman_int operator/(const Roman_int& other) const;
    Roman_int operator*(const Roman_int& other) const;
    Roman_int operator%(const Roman_int& other) const;

    bool operator==(const Roman_int& other) const;
    bool operator!=(const Roman_int& other) const;
    bool operator>(const Roman_int& other) const;
    bool operator<(const Roman_int& other) const;
    bool operator>=(const Roman_int& other) const;
    bool operator<=(const Roman_int& other) const;

private:
    int val;
};

const char N = 'N';
const char I = 'I';
const char V = 'V';
const char X = 'X';
const char L = 'L';
const char C = 'C';
const char D = 'D';
const char M = 'M';

bool is_valid_char(char ch);

// return value of single letter Roman numeral
int get_value(char ch);

// test if letter has been repeated too often
bool counter_illegal(int counter, char ch);

// test if string is valid roman numeral, calculate its value
int roman_int_to_int(const std::string& s);

// return value of single letter Roman numeral
int get_value(char ch);

// test if letter has been repeated too often
bool counter_illegal(int counter, char ch);

// test if string is valid roman numeral, calculate its value
int roman_int_to_int(const std::string& s);