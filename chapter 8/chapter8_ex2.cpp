#include <iostream>
#include <vector>

// ex 2 3 4 
void print(const std::string& label,const std::vector<int> &v)
{
    std::cout << label << '\n';
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
}

void fibonacci(int x, int y, std::vector<int>& v, int n)
{
    if(n < 1) {
        std::cout <<"error should be more than 1 number\n";
        return;
    }
    if(n == 1) return;
    v.push_back(x);
    v.push_back(y);

    for(int i = 2; i < n; i++){
        v.push_back(v[i-2] + v[i-1]);
    }

}

void find_fb()
{
    bool is = false;
    int x = 0;
    int y = 1;
    int temp = 0;
    int max = INT_MAX;

    while( temp < max ){
        temp = x + y;
        x = y;
        y = temp;
    }

    std::cout << max << " " << temp << '\n';
}

int main()
{
    int x = 0;
    int y = 1;
    int n = 10;
    std::vector<int> v;
    std::string label = "fibonacci";
    
    fibonacci(x,y,v,n);

    print(label,v);

    find_fb();
    
    return 0;
}