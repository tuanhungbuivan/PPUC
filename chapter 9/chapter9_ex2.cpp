#include <iostream>
#include <vector>

// ex 2

class Name_pairs{
public:
    void read_names();
    void read_ages();
    void print() const;
    void sort();
    const std::vector<std::string>& get_name() const {return name;}
    const std::vector<double>& get_age() const {return age;}
private:
    std::vector<std::string> name;
    std::vector<double> age;
};

void Name_pairs::read_names()
{
    std::string names;
    std::cout<<"Enter names, enter quit to quit: ";
    while(std::cin>>names && names!="quit"){
        for(int i=0;i<name.size();i++){
            if(name[i] == names){
                std::cout<<"\nName exists already: "<<names;
                break;
            }
        }
        name.push_back(names);
    }
    std::cout<<'\n';
}

void Name_pairs::read_ages()
{
    std::vector<double>();
    for(int i=0;i<name.size();i++){
        std::cout<<"Age of: "<<name[i]<<" is: ";
        double x;
        std::cin>>x;
        age.push_back(x);
        std::cout<<'\n';
    }
}

void Name_pairs::print() const
{
    if(name.size() !=  age.size()){
        std::cout <<"Sizes dont match";
        return;
    }

    for(int i=0;i<name.size();i++){
        std::cout<<name[i]<<" is "<<age[i]<<'\n';
    }
    std::cout<<'\n';
}

void Name_pairs::sort()
{
    if(name.size() !=  age.size()){
        std::cout <<"Sizes dont match";
        return;
    }
    std::vector<std::string> pre_name = name;
    std::vector<double> pre_age = age;
    std::sort(name.begin(),name.end());

    for(int i=0;i<name.size();i++){
        for(int j=0;j<name.size();j++){
            if(name[i] == pre_name[j]){
                age[i] = pre_age[j];
            }
        }
    }
}

// ex 3

std::ostream& operator<<(std::ostream& os,const Name_pairs& np)
{
    if(np.get_name().size() != np.get_age().size()){
        std::cout<<"Sizes dont match\n";
    }

    for(int i=0;i<np.get_name().size();i++){
        os << np.get_name()[i] <<" age is " << np.get_age()[i] << '\n';
    }
    return os;
}

bool operator==(const Name_pairs& a, const Name_pairs& b)
{
    if (a.get_name().size()!=b.get_name().size() || a.get_age().size() != b.get_age().size())
        return false;

    for (int i = 0; i<a.get_name().size(); ++i) {
        if (a.get_name()[i] != b.get_name()[i])
            return false;
    }

    for (int i = 0; i<a.get_age().size(); ++i) {
        if (a.get_age()[i] != b.get_age()[i])
            return false;
    }
    return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
    return !(a==b);
}

int main()
{
    Name_pairs ex2;
    ex2.read_names();
    ex2.read_ages();
    //ex2.print();
    //ex2.sort();
    //ex2.print();

    Name_pairs ex3;
    ex3.read_names();
    ex3.read_ages();

    std::cout << "Ex2 names and ages: \n" << ex2;
    std::cout << "\nEx3 names and ages: \n" << ex3;

    if(ex2 == ex3) std::cout << "Identical\n";
    if(ex2 != ex3) std::cout << "Different\n";

    return 0;
}