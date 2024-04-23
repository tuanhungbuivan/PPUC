#include <iostream>
#include <vector>
#include <list>
#include <fstream>

struct Item{
    std::string name;
    int iid;
    double value;

    Item() :name(), iid(0), value(0){ }
    Item(std::string n, int i, double v) :name(n), iid(i), value(v){ }
};

std::istream& operator>>(std::istream& is, Item& it)
{
    std::string name;
    int iid;
    double val;
    is >> name >> iid >> val;
    if(!is) return is;
    it = Item(name,iid,val);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Item& it)
{
    os << it.name << " " << it.iid << " " << it.value;
    return os;
}

struct Comp_by_name{
    bool operator()(const Item&a, const Item& b) const
    {
        return a.name<b.name;
    }
};

struct Comp_by_iid{
    bool operator()(const Item&a, const Item& b) const
    {
        return a.iid<b.iid;
    }
};

struct Comp_by_value{
    bool operator()(const Item&a, const Item& b) const
    {
        return a.value>b.value;
    }
};

class Find_name{
private:
    std::string name;
public:
    Find_name(const std::string& s) : name(s){ }
    bool operator()(const Item& it) const
    {
        return it.name == name;
    }
};

class Find_iid{
private:
    int iid;
public:
    Find_iid(const int& s) : iid(s){ }
    bool operator()(const Item& it) const
    {
        return it.iid == iid;
    }
};

template<typename iter>
void print(iter first,iter last)
{
    while(first != last){
        std::cout<<*first<<'\n';
        ++first;
    }
}

void drill1()
{
    std::cout<<"Drill 1\n";
    std::vector<Item> vi;
    const std::string ifname = "file.txt";

    std::cout<<"Fill vi with 10 items from file: "<<ifname<<'\n';
    std::ifstream ifs(ifname.c_str());
    if(!ifs) std::cout<<"can't open file: "<<ifname<<'\n';
    Item i;
    while(ifs>>i) vi.insert(vi.begin(),i);

    //print(vi.begin(),vi.end());
    // 1.2 sort by name 
    std::cout<<"sort by name: \n";
    sort(vi.begin(),vi.end(),Comp_by_name());
    print(vi.begin(),vi.end());
    std::cout<<'\n';

    // 1.3 sort by iid
    std::cout<<"sort by iid: \n"; 
    sort(vi.begin(),vi.end(),Comp_by_iid());
    print(vi.begin(),vi.end());
    std::cout<<'\n';

    // 1.4 sort by value in decreasing order 
    std::cout<<"sort by value: \n";
    sort(vi.begin(),vi.end(),Comp_by_value());
    print(vi.begin(),vi.end());
    std::cout<<'\n';

    // 1.5 Insert 2 items
    std::cout<<"insert 2 items : \n";
    vi.insert(vi.end(),Item("horse shoe",99,12.34));
    vi.insert(vi.end(),Item("Canon S400",9988,499.95));
    print(vi.begin(),vi.end());
    std::cout<<'\n';

    // 1.6 Remove 2 items by name
    std::cout<<"remove 2 items identified by name : \n";
    std::vector<Item>::iterator vi_temp1 = find_if(vi.begin(),vi.end(),Find_name("horse shoe"));
    std::vector<Item>::iterator vi_temp2 = find_if(vi.begin(),vi.end(),Find_name("A"));
    vi.erase(vi_temp1);
    vi.erase(vi_temp2);
    print(vi.begin(),vi.end());

    // 1.7 Remove 2 items by id
    std::cout<<"remove 2 items identified by name : \n";
    std::vector<Item>::iterator vi_temp3 = find_if(vi.begin(),vi.end(),Find_iid(6));
    std::vector<Item>::iterator vi_temp4 = find_if(vi.begin(),vi.end(),Find_iid(8));
    vi.erase(vi_temp3);
    vi.erase(vi_temp4);
    print(vi.begin(),vi.end());

}

void drill1_2()
{
    std::cout<<"Drill 1.2\n";
    std::list<Item> li;
    const std::string ifname = "file.txt";

    std::cout<<"Fill vi with 10 items from file: "<<ifname<<'\n';
    std::ifstream ifs(ifname.c_str());
    if(!ifs) std::cout<<"can't open file: "<<ifname<<'\n';
    Item i;
    while(ifs>>i) li.insert(li.begin(),i);

    //print(vi.begin(),vi.end());
    // 1.2 sort by name 
    std::cout<<"sort by name: \n";
    li.sort(Comp_by_name());
    print(li.begin(),li.end());
    std::cout<<'\n';

    // 1.3 sort by iid
    std::cout<<"sort by iid: \n"; 
    li.sort(Comp_by_iid());
    print(li.begin(),li.end());
    std::cout<<'\n';

    // 1.4 sort by value in decreasing order 
    std::cout<<"sort by value: \n";
    li.sort(Comp_by_value());
    print(li.begin(),li.end());
    std::cout<<'\n';

    // 1.5 Insert 2 items
    std::cout<<"insert 2 items : \n";
    li.insert(li.end(),Item("horse shoe",99,12.34));
    li.insert(li.end(),Item("Canon S400",9988,499.95));
    print(li.begin(),li.end());
    std::cout<<'\n';

    // 1.6 Remove 2 items by name
    std::cout<<"remove 2 items identified by name : \n";
    std::list<Item>::iterator vi_temp1 = find_if(li.begin(),li.end(),Find_name("horse shoe"));
    std::list<Item>::iterator vi_temp2 = find_if(li.begin(),li.end(),Find_name("A"));
    li.erase(vi_temp1);
    li.erase(vi_temp2);
    print(li.begin(),li.end());

    // 1.7 Remove 2 items by id
    std::cout<<"remove 2 items identified by name : \n";
    std::list<Item>::iterator vi_temp3 = find_if(li.begin(),li.end(),Find_iid(6));
    std::list<Item>::iterator vi_temp4 = find_if(li.begin(),li.end(),Find_iid(8));
    li.erase(vi_temp3);
    li.erase(vi_temp4);
    print(li.begin(),li.end());
}

void drill3()
{
    
}

int main()
{
    //drill1();
    //drill1_2();
    drill3();
    
    return 0;
}