#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

typedef std::vector<std::string>::const_iterator Line_iter;

class Message{
    Line_iter first;
    Line_iter last;
public:
    Message(Line_iter p1, Line_iter p2) :first(p1), last(p2) { }
    Line_iter begin() const {return first;}
    Line_iter end() const {return last;}
};

std::ostream& operator<<(std::ostream& os, const Message& m)
{
    for(Line_iter p = m.begin(); p != m.end(); ++p){
        os << *p <<'\n';
    }
    return os;
}

typedef std::vector<Message>::const_iterator Mess_iter;

struct Mail_file{
    std::string name;
    std::vector<std::string> lines;
    std::vector<Message> m;

    Mail_file(const std::string& n);

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

/*
Mail_file::Mail_file(const std::string& n) :name(n)
{
    std::ifstream in(n.c_str());
    if(!in){
        std::cerr << "Failed to open file: " << n << '\n';
        exit(1);
    }

    std::string s;
    while (getline(in,s)) lines.push_back(s);

    Line_iter first = lines.begin();
    for(Line_iter p = lines.begin(); p != lines.end(); ++p){
        if(*p == "----"){
            m.push_back(Message(first, p));
            first = p + 1;
        }
    }

    // Add debug output to check the number of messages read from the file
    std::cout << "Number of messages: " << m.size() << '\n';
}*/

Mail_file::Mail_file(const std::string& n)
{
    std::ifstream in{n};
    if (!in) {
        std::cerr << "Failed to open file: " << n << '\n';
        exit(1);
    }

    std::string line;
    std::vector<std::string> messageLines;

    while (getline(in, line)) {
        if (line == "----") {
            if (!messageLines.empty()) {
                m.push_back(Message(messageLines.begin(), messageLines.end()));
                messageLines.clear();
            }
        } else {
            messageLines.push_back(line);
        }
    }

    // Add the last message if there are remaining lines
    if (!messageLines.empty()) {
        m.push_back(Message(messageLines.begin(), messageLines.end()));
    }

    // Add debug output to check the number of messages read from the file
    std::cout << "Number of messages: " << m.size() << '\n';
}



int is_prefix(const std::string& s, const std::string& p)
{
    int n = p.size();
    if(std::string(s,0,n) == p) return n;
    return 0;
}

bool find_from_addr(const Message& m, std::string& s)
{
    for(const auto& x : m){
        if(int n = is_prefix(x, "From: ")){
            s = std::string(x,n);
            return true;
        }
    }
    return false;
}

std::string find_subject(const Message& m)
{
    for(const auto& x :m){
        if(int n = is_prefix(x,"Subject: ")) return std::string(x,n);
    }
    return "";
}

int main()
{
    Mail_file mfile("my_mail_file.txt");

    std::multimap<std::string, const Message*> sender;
    for(Mess_iter p = mfile.begin(); p!=mfile.end(); ++p){
        const Message& m = *p;
        std::string s;
        if(find_from_addr(m,s)){
            std::cout << "Found sender: " << s << '\n';
            sender.insert(make_pair(s,&m));
        }
    }
    
    auto pp = sender.equal_range("mjones@machine.example");
    for(auto p = pp.first; p != pp.second; ++p){
        std::cout<<find_subject(*p->second)<<'\n';
    }
    /*
    std::cout<<"Enter name: ";
    std::string name;
    getline(std::cin,name);

    typedef std::multimap<std::string, const Message*>::const_iterator m_iter;
    std::pair<m_iter,m_iter> ppp = sender.equal_range(name);
    //auto ppp = sender.equal_range(name);
    for(m_iter p = ppp.first; p!=ppp.second; ++p){
        std::cout<<find_subject(*(p->second))<<'\n';
    }
    */ 
    return 0;
}