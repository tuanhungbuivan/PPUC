#include <iostream>
#include <sstream>
#include <iomanip>


int main()
{
    std::cout << "Enter integers in any combination of octal, decimal, or hexadecimal using 0, 0x, or no prefix for the base." << std::endl;
    std::cout << "Enter 'q' to quit." << std::endl;

    std::string input;
    while (true) {
        std::cout << "Enter an integer: ";
        std::getline(std::cin, input);

        if (input == "q") {
            break;
        }

        std::istringstream iss(input);
        int value;
        if(input.substr(0,2) == "0x"){
            iss >> std::hex >> value;
            std::cout << input << " hexadecimal converts to " << std::dec << value << '\n';
        }else if(input[0] == '0'){
            iss.clear();
            iss >> std::oct >> value;
            std::cout << input << " octal converts to " << std::dec << value << '\n';
        }else if(iss >> value){
            iss.clear();
            std::cout << input << " octal converts to " << std::dec << value << '\n';
        }
    }
    return 0;
}