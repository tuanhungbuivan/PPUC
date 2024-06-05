#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

typedef std::vector<std::string>::const_iterator Line_iter;

class Message {
    Line_iter first;
    Line_iter last;
public:
    Message(Line_iter p1, Line_iter p2) :first(p1), last(p2) { }
    Line_iter begin() const { return first; }
    Line_iter end() const { return last; }
};

std::ostream& operator<<(std::ostream& os, const Message& m)
{
    for (Line_iter p = m.begin(); p!=m.end(); ++p)
        os << *p << '\n';
    return os;
}

typedef std::vector<Message>::const_iterator Mess_iter;

struct Mail_file {  // a Mail_file holds all the lines froma file and simplifies
                    // access to messages
    std::string name;            // file name
    std::vector<std::string> lines;   // the lines in order
    std::vector<Message> m;      // Messages in order;

    Mail_file(const std::string& n); // read file n into lines

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

Mail_file::Mail_file(const std::string& n) :name(n)
{
    std::ifstream in(n.c_str());
    if(!in){
        std::cerr << "Error cant open file '\n";
        exit(EXIT_FAILURE);
    }

    std::string s;
    while(getline(in,s)) lines.push_back(s);

    Line_iter first = lines.begin();
    for(Line_iter p = lines.begin(); p != lines.end(); ++p){
        if(*p == "----"){
            m.push_back(Message(first,p));
            first = p+1;
        }
    }
}

int is_prefix(const std::string& s, const std::string& p)
{
    int n = p.size();
    if(std::string(s,0,n) == p) return n;
    return 0;
}

bool find_from_addr(const Message* m, std::string& s)
{
    for(Line_iter p = m->begin(); p != m->end(); ++p){
        if(int n = is_prefix(*p, "From: ")){
            s = std::string(*p,n);
            return true;
        }
    }
    return false;
}

std::string find_subject(const Message* m)
{
    for (Line_iter p = m->begin(); p!=m->end(); ++p)
        if (int n = is_prefix(*p,"Subject: ")) {
            return std::string(*p,n);
        }
    return "";
}

int main()
{
    Mail_file mfile("my_mail_file.txt");

    std::multimap<std::string, const Message*> sender;
    for(Mess_iter p = mfile.begin(); p != mfile.end(); ++p){
        const Message& m = *p;
        std::string s;
        if(find_from_addr(&m, s)){
            sender.insert(std::make_pair(s, &m));
        }
    }

    std::multimap<std::string, const Message*> subjects;
    for(Mess_iter p = mfile.begin(); p != mfile.end(); ++p){
        const Message& m = *p;
        std::string s = find_subject(&m);
        if(s != "" ){
            subjects.insert(std::make_pair(s, &m));
        }
    }

    std::cout << "Enter subject: ";
    std::string subject;
    getline(std::cin,subject);
    
    auto range = subjects.equal_range(subject);
    if (range.first == range.second) {
        std::cout << "No messages with subject: " << subject << "\n";
    } else {
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << *(it->second) << "\n";
        }
    }

    return 0;

}