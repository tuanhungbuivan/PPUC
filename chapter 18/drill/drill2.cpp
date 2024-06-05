#include <iostream>
#include <vector>

std::vector<int> gv = {1,2,4,8,16,32,64,128,256,512};

void f(std::vector<int> v)
{
    std::vector<int> lv;
    lv = v;

    for(int i=0;i<lv.size();i++){
        std::cout << lv[i] << " ";
    }
    std::cout << '\n';

    std::vector<int> lv2(v);
    for(int i=0;i<lv2.size();i++){
        std::cout << lv2[i] << " ";
    }
    std::cout << '\n';
}

int main()
{
    //f(gv);
    
    std::vector<int> vv;
    vv.push_back(1);
    for(int i=1;i<10;i++){
        vv.push_back((i+1)*vv[i-1]);
    }

    f(vv);

    return 0;
}