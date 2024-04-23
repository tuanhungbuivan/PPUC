#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

class Variable {
public:
    std::string name;
    double value;
	bool var;	// variable (true) or constant (false)
    Variable (std::string n, double v, bool va = true) :name(n), value(v), var(va) { }
};

std::vector<Variable> var_table;

double get_value(std::string s)
{
    for(int i = 0;i<var_table.size();i++){
         if(var_table[i].name == s) return var_table[i].value; 
    }

    std::cout<<"get: undefiined variable "<< s << '\n';
    return 0;
}

void set_value(std::string s, double d)
{
    for(int i = 0;i<var_table.size();i++){
        if(var_table[i].name == s){
                if (var_table[i].var == false ){ std::cout<< s <<" is a constant\n"; return;}
            var_table[i].value = d;
            return ;
        }
    }
    std::cout<<"set: undefined variable "<< s << '\n';
    return ;
}

bool is_declared(std::string var)
{
    for(int i=0;i<var_table.size();i++){
        if(var_table[i].name == var ) return true;
    }
    return false;
}

double define_name(std::string var, double val)
{
    if (is_declared(var)) {
        std::cout<<var<<" declared twice \n";
        return 0;
    }
    var_table.push_back(Variable(var,val));
    return val;
}


class Token{
public:
    char kind;
    double value;
    std::string name;
    Token (char ch): kind(ch), value(0) { }
    Token (char ch, double val): kind(ch), value(val) { }
    Token (char ch, std::string n): kind(ch), name(n) { }
};

class Token_stream{
public:
    Token_stream();
    Token get();
    void putback(Token t);
    void ignore(char c);
private:
    bool full;
    Token buffer;
};


const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';
const char con = 'C';
const std::string prompt = "> ";
const std::string result = "= ";
const std::string deckley = "let";


Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

void Token_stream::putback(Token t)
{
    if(full)
    {
        std::cout<<"its full\n";
        return;
    }
    buffer = t;
    full = true;
}

void Token_stream::ignore(char c)
{
    if(full && c == buffer.kind){
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while(std::cin>>ch){
        if(ch==c) return;
    }
}

Token Token_stream::get()
{
    if (full){
        full = false;
        return buffer;
    }

    char ch;
    std::cin>>ch;

    switch(ch){
        case ';': case 'q': case '%':
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);

        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                std::cin.putback(ch);
                double val;
                std::cin>>val;
                return Token('8',val);
            }

        default:
            if(isalpha(ch)){
                std::string s;
                s += ch;
                while(std::cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
                std::cin.putback(ch);
                if(s == deckley ) return Token(let);
                return Token(name,s);
            }

            if(isspace(ch)){
                if(ch == '\n') return Token(print);
                break;
            }
            std::cout<<"Bad Token\n";
            return 0;
    }
}

Token_stream ts;

double expression();
double term();

double primary()
{
    Token t = ts.get();
    switch(t.kind){
    case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') {
                std::cout<<" ')' expected \n"; 
                return 0;
            }
            return d;
        }
    case '8':
        return t.value;
    case name:
        {
            // exercise 02
            Token t2 = ts.get();
            if (t2.kind == '=') {
                set_value(t.name, expression());
            } else {
                ts.putback(t2);
                return get_value(t.name);
            }
        }
    case '-':
        return - primary();
    case '+':
        return primary();
    default:
        std::cout<<"primary expected \n";
        return 0;
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}



double declaration()
{
    Token t = ts.get();
    if (t.kind != name) {std::cout<<"name expected in declaration \n";  return 0;}
    std::string var_name = t.name;

    Token t2 = ts.get();
    if(t2.kind != '=') {std::cout<<"= missing in declaration of "<< var_name<<'\n'; return 0;}

    double d = expression();
    define_name(var_name,d);
    return d;

}

double statement()
{
    Token t =ts.get();
    switch(t.kind){
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}


void calculate()
{
    double val = 0;
    while(std::cin)
    {   
        std::cout<< prompt;
        Token t = ts.get();
        while(t.kind == print) t=ts.get();
        if (t.kind == quit) return;
        //if (t.kind == ';') std::cout<<"="<<val<< '\n';
        ts.putback(t);
        std::cout<<result<<statement()<<'\n';
        
        //val = expression();
    }

    clean_up_mess();

}

int main()
{
    calculate();
    return 0;
}

double term()
{
    double left = primary();
    Token t = ts.get();

    while(true){
        switch(t.kind){
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {
                double d = primary();
                if(d == 0) {
                    std::cout<<"Can't divide by zero \n"; 
                    return 0; 
                }
                left /= d;
                t = ts.get();
                break;
            }
        case '%':
            {
                double d = primary();
                //int i1 = narrow_cast<int>(left);
                //int i2 = narrow_cast<int>(primary());
                if(d==0) {std::cout<<"divide by zero \n"; return 0;}
                left = fmod(left,d);
                t = ts.get();
                break;
            }
        default:
            ts.putback(t);
            return left;
        }
    }
    return left;
}

double expression()
{
    double left = term();
    Token t = ts.get();

    while(true){
        switch(t.kind){
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
    return left;
}








