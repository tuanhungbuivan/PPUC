#include <iostream>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

using Line = vector<char>; // a line is a vector of characters

class Text_iterator {
    list<Line>::iterator ln;
    Line::iterator pos;
public:
    // start the iterator at line ll's character position pp:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
        :ln(ll), pos(pp) { }

    list<Line>::iterator get_line() { return ln; }
    Line::iterator get_pos() { return pos; }

    char& operator*() { return *pos; }
    Text_iterator& operator++();

    bool operator==(const Text_iterator& other) const
        { return ln==other.ln && pos==other.pos; }
    bool operator!=(const Text_iterator& other) const
        { return !(*this==other); }
};

template<class Iter> 
bool match(Iter first, Iter last, const string& s)
{
    string::const_iterator si = s.begin();
    while (first!=last && si!=s.end()) {
        if (*first!=*si) return false;
        ++first;
        ++si;
    }
    return true;
}

Text_iterator& Text_iterator::operator++()
{
    ++pos;                      // proceed to next character
    if (pos==(*ln).end()) {
        ++ln;                   // proceed to next line
        pos = (*ln).begin();    // bad if ln==line.end(); so make sure it isn't
    }
    return *this;
}

template<class Iter, class T> 
Iter find(Iter first, Iter last, const T& val)
{
    Iter p = first;
    while (p != last) {
        if (*p==val) return p;
        ++p;
    }
    return p;
}

Text_iterator find_txt(Text_iterator first, Text_iterator last, const string& s)
{
    if (s.size()==0) return last;   // can't find an empty string
    char first_char = s[0];
    while (true) {
        Text_iterator p = ::find(first,last,first_char);
        if (p==last || match(p,last,s)) return p;
        first = ++p;    // look at the next character
    }
}

// ---------------------------------------------------------------------------------------

struct Document {
    list<Line> line; // a document is a list of lines 
    Document() { line.push_back(Line{}); }

    Text_iterator begin()   // first character of first line
        { return Text_iterator(line.begin(),(*line.begin()).begin()); }
    Text_iterator end()     // one beyond the last character of the last line
    {
        list<Line>::iterator last = line.end();
        --last;             // we know that the document is not empty
        return Text_iterator(last,(*last).end());
    }

    void find_replace(Text_iterator first, Text_iterator last,
        const string& find_str, const string& repl_str);
};

istream& operator>>(istream& is, Document& d)
{
    char ch;
    while (is.get(ch)) {
        d.line.back().push_back(ch);    // add the character
        if (ch=='\n')
            d.line.push_back(Line());   // add another line
    }
    if (d.line.back().size()) d.line.push_back(Line()); // add final empty line
    return is;
}

void print(Document& d, Text_iterator p) 
{
    for (Text_iterator iter = p; iter != d.end(); ++iter) {
        cout << *iter;
    }
}

void erase_line(Document& d, int n) 
{
    if (n<0 || d.line.size()-1<=n) return;
    auto p = d.line.begin(); 
    advance(p,n); 
    d.line.erase(p);
}

template<typename Iter>
void advance(Iter& p, int n) // requires Forward_iterator
{
    while (n > 0) { ++p; --n; } 
}

// ex 6 
void Document::find_replace(Text_iterator first, Text_iterator last,
    const string& find_str, const string& repl_str)
{
        while(true){
            first = find_txt(first, last, find_str);
            if(first == last) break;

            // Replace find_str with repl_str
            auto line_iter = first.get_line();
            auto pos_iter = first.get_pos();
            pos_iter = (*line_iter).erase(pos_iter, pos_iter + find_str.size());
            pos_iter = (*line_iter).insert(pos_iter, repl_str.begin(), repl_str.end());

            // Move the iterator to the position after the replaced text
            first = Text_iterator(line_iter, pos_iter + repl_str.size());
        }
}

// ex 8
int count_char(Document& d)
{
    Text_iterator iter = d.begin();
    int count = 0;
    while(iter != d.end()){
        ++iter;
        count++;
    }
    return count;
}

// ex 9a count words as whitespace separated sequence of characters
int word_count1(Document& d)
{
    Text_iterator iter = d.begin();
    int count = 0;
    bool words = false;

    while(iter != d.end()){
        if(isspace(*iter) || ispunct(*iter)){
            if(words){
                count++;
                words = false;
            }
        }else{
            words = true;
        }
        ++iter;
    }

    return count;
}

// ex 9b count words a sequence of consecutive alphabetic characters;
int word_count2(Document& d)
{
    Text_iterator iter = d.begin();
    int count = 0;
    bool words = false;

    while(iter != d.end()){
        if(isalnum(*iter)){
            words = true;
        }else{
            if(words){
                count++;
                words = false;
            }
        }
        ++iter;
    }

    return count;
}

int main()
{
    string ifname = "ifs20_6in.txt";
    ifstream ifs(ifname.c_str());
    if (!ifs){
        std::cerr << "Error cant open file'\n";
        exit(EXIT_FAILURE);
    }
    Document my_doc;
    ifs >> my_doc;
    print(my_doc,my_doc.begin());

    string find_str = "old";
    string repl_str = "new";
    my_doc.find_replace(my_doc.begin(), my_doc.end(), find_str, repl_str);

    cout << "\n\nAfter replacement:\n";
    print(my_doc, my_doc.begin());

    int count = count_char(my_doc);
    std::cout << "\n\nNumber of characters in documents: " << count << '\n';

    int count9a = word_count1(my_doc);
    std::cout << "\n\nCount number of words in documents (method 9a): " << count9a << '\n';

    int count9b = word_count2(my_doc);
    std::cout << "\n\nNumber of words in documents (method 9a): " << count9b << '\n';

    return 0;
}