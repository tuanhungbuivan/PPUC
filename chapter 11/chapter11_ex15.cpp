#include <iostream>
#include <vector>
#include <fstream>
#include <map>

void ex15()
{
    std::ifstream ifs("ifs_15.txt");
    if(!ifs) {
        std::cerr << "Error cant open file\n";
        return; 
    }

    std::ofstream ofs("ofs_15.txt");
    if(!ofs) {
        std::cerr << "Error cant open file\n";
        return; 
    }

    ofs<< std::scientific << std::setprecision(8);

    double nums;
    int count = 0;
    while(ifs >> nums){
        ofs << std::setw(4) << nums;
        count++;
        if(count % 4 == 0){
            ofs << std::endl;
        } 
    }

    ifs.close();
    ofs.close();

}

void ex16()
{
    std::ifstream ifs("ifs_16.txt");
    if(!ifs) {
        std::cerr << "Error cant open file\n";
        return; 
    }

    int nums;
    std::vector<int> numbersv;
    std::map<int,int> numbersm;
    while(ifs >> nums){
        numbersv.push_back(nums);
    }

    for(int i : numbersv){
        numbersm[i]++;
    }

    for(auto& pairs : numbersm){
        std::cout << pairs.first ;
        if(pairs.second > 1){
            std::cout << "\t" << pairs.second;
        }

        std::cout <<std::endl;
    }
}

int main()
{
    ex15();
    ex16();

    return 0;
}