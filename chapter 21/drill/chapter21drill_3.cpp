#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>

template<typename T>
class less_then{
public: 
    less_then(T val) : v(val){ }
    bool operator()(T x) const { return x < v; }
private:
    T v;
};

int main()
{
    // 3.1
    const std::string fname = "file_3.txt";
    std::ifstream ifs(fname.c_str());
    if(!ifs) std::cout<<"error cant read file \n";
    
    std::vector<double> vd;
    double d;
    while(ifs>>d) vd.push_back(d);

    // 3.2
    for(int i=0;i<16;i++){
        std::cout<<vd[i]<<" ";
    }
    std::cout<<'\n';

    // 3.3
    std::vector<int> vi(vd.size());
    std::copy(vd.begin(),vd.end(),vi.begin());

    // 3.4
    for(int i=0;i<16;i++){
        std::cout<<std::setw(8)<<vd[i]<<"   "<<vi[i]<<'\n';
    }
    std::cout<<'\n';

    // 3.5
    double sum_vd = 0;
    sum_vd = std::accumulate(vd.begin(),vd.end(),sum_vd);
    std::cout<<"Sum of vd: "<< sum_vd<<'\n'<<'\n';

    // 3.6
    int sum_vi = 0;
    sum_vi = std::accumulate(vi.begin(),vi.end(),sum_vi);
    double diff = sum_vd - sum_vi;
    std::cout<<"Difference between sum_vi - sum_vd: "<<diff<<'\n'<<'\n';

    // 3.7
    std::reverse(vd.begin(),vd.end());
    for(int i=0;i<16;i++){
        std::cout<<vd[i]<<" ";
    }
    std::cout<<'\n'<<'\n';
    
    // 3.8
    double mean_vd = sum_vd / vd.size();
    std::cout<<"Mean value of vd: "<<mean_vd<<'\n'<<'\n';

    // 3.9
    std::vector<double> vd2(std::count_if(vd.begin(),vd.end(),less_then<double>(mean_vd)));
    std::copy_if(vd.begin(),vd.end(),vd2.begin(),less_then<double>(mean_vd));

    // 3.10
    std::sort(vd2.begin(),vd2.end());
    for(int i=0;i<vd2.size();i++){
        std::cout<<vd2[i]<<" ";
    }

    return 0;
}