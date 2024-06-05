#include <iostream>
#include <cstring>

const char* findx(const char* s, const char* x, int& length)
{
    if(x == nullptr) return s;
    for(int i=0; s[i]; i++){
        if(s[i] == x[0]){
            int j=1;
            for(; x[j];j++){
                if(s[i+j] != x[j]) break;
            }
            if(x[j] == '\0') {
                length = j;
                return &s[i];
            }
        }
    }

    return nullptr;
}

int main()
{
    const char* ss = "finding first occurence of the C-style string x in s";
    const char* xx = "C-style";

    int length = 0;
    const char* sub = findx(ss,xx,length);
    if(!sub){
        std::cerr << "Error cant find\n";
        return 1;
    }else{
        for(int i=0;i<length;i++){
            std::cout << sub[i];
        }
        std::cout << '\n';
    }
    
    return 0;
}