#include "roman.h"

Roman_int::Roman_int(int n) : val(n) { };

Roman_int::Roman_int() : val(0) { }

bool is_valid_char(char ch)
{
    return (ch == 'I' || ch == 'V' || ch == 'X' || ch == 'L' || ch == 'C' || ch == 'D' || ch == 'M');
}

Roman_int Roman_int::operator+(const Roman_int& other) const{
    return val + other.val;
}

Roman_int Roman_int::operator-(const Roman_int& other) const{
    return val - other.val;
}

Roman_int Roman_int::operator/(const Roman_int& other) const{
    if(other.val == 0){
        std::cerr << "Divisor cant be 0";
        exit(EXIT_FAILURE);
    }

    return val / other.val;
}

Roman_int Roman_int::operator*(const Roman_int& other) const{
    return val * other.val;
}

Roman_int Roman_int::operator%(const Roman_int& other) const{
    return val % other.val;
}

bool Roman_int::operator==(const Roman_int& other) const{
    return val == other.val;
}

bool Roman_int::operator!=(const Roman_int& other) const{
    return val != other.val;
}

bool Roman_int::operator>(const Roman_int& other) const{
    return val > other.val;
}

bool Roman_int::operator<(const Roman_int& other) const{
    return val < other.val;
}

bool Roman_int::operator>=(const Roman_int& other) const{
    return val >= other.val;
}

bool Roman_int::operator<=(const Roman_int& other) const{
    return val <= other.val;
}

// return value of single letter Roman numeral
int get_value(char ch){
    switch (ch) {
    case N:
        return 0;
    case I:
        return 1;
    case V:
        return 5;
    case X:
        return 10;
    case L:
        return 50;
    case C:
        return 100;
    case D:
        return 500;
    case M:
        return 1000;
    default:
        std::cerr << "Error illegal value\n";
        break;
    }
}

// test if letter has been repeated too often
bool counter_illegal(int counter, char ch){
    switch (ch) {
    case N: case V: case L: case D:
        return counter > 1;
    case I: case X: case C: case M:
        return counter > 3;
    default:
        std::cerr<<"Error to many repeated\n";
        break;
    }   
}

// test if string is valid roman numeral, calculate its value
int roman_int_to_int(const std::string& s)
{
    std::unordered_map<char,int> roman_values = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int prev_val = 0;

    for(char c : s){
        int current_value = roman_values[c];
        result += roman_values[c];

        if(prev_val < current_value){
            result -= 2 * prev_val;
        }

        prev_val = current_value;
    }

    return result;
}


std::ostream& operator<<(std::ostream& os, const Roman_int& r)
{
    os << "Roman " << r.as_int() << " equals " << r.as_int() << '\n';
    return os;
}

int Roman_int::as_int() const{
    return val;
}

int main()
{
    Roman_int r0(0);
    Roman_int r1(1);
    Roman_int r4(4);
    Roman_int r5(5);
    Roman_int r8(8);
    Roman_int r9(9);
    Roman_int r10(10);
    Roman_int r48(48);
    Roman_int r81(81);
    Roman_int r99(99);
    Roman_int r105(105);
    Roman_int r2014(2014);
    Roman_int r_negative(-2014);
    Roman_int r1499(1499);

    //std::cout << Roman_int (0) ;

    std::cout << "Roman to int XXII: " << roman_int_to_int("XXII") << '\n';
    std::cout << "Roman to int XXI + CIV: " << roman_int_to_int("XXII")  + roman_int_to_int("CIV")<< '\n';
    
    std::cout << r0;
    std::cout << r1;
    std::cout << r4;
    std::cout << r5;
    std::cout << r8;
    std::cout << r9;
    std::cout << r10;
    std::cout << r48;
    std::cout << r81;
    std::cout << r99;
    std::cout << r105;
    std::cout << r2014;
    std::cout << r_negative;
    std::cout << r1499;
    std::cout<<'\n';
    
    std::cout << "Roman " << r1 << " + " << r4 << " = " << r1 + r4 << std::endl;
    std::cout << "Roman " << r10 << " * " << r48 << " = " << r10 * r48 << std::endl;
    std::cout << "Roman " << r105 << " - " << r2014 << " = " << r105 - r2014 << std::endl;
    std::cout << "-" << r4 << " * " << r5 << " = " << r4 * r5 << std::endl;
    std::cout << "Roman " << r1499 << " / " << r5 << " = " << r1499 / r5 << std::endl;
    
    return 0;
}