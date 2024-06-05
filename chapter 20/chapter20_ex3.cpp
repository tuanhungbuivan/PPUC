#include <iostream>

std::string* get_word()
{
    std::string *word = new std::string;
    std::cin >> *word;

    return word;
}

bool pali(const std::string& s)
{
    int first = 0;
    int last = s.length()-1;
    while(first < last){
        if(s[first]!=s[last]){
            return false;
        }
        first++;
        last--;
    }
    return true;
}

void fct() {
    std::string* jack_word = get_word();

    bool jack_pali = pali(*jack_word);
    if(jack_pali){
        std::cout << *jack_word << " is a palindrome\n";
    }else{
        std::cout << *jack_word << " is not a palindrome\n";
    }

}



int main()
{
    fct();
    return 0;
}