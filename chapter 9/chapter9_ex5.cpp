#include <iostream> 
#include <string>
#include <regex>

// ex 5

class Book{
public:
    Book(const std::string& isbn, const std::string& title, const std::string& author, const std::string& copyright_date)
        :isbn(isbn), title(title), author(author), copyright_date(copyright_date), ischeckedout(false) { }

    std::string getISBN() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getCopyrightDate() const { return copyright_date; }
    bool getIsCheckedOut() const { return ischeckedout; }

    void checkout() {ischeckedout = true;}
    void checkin() {ischeckedout = false;}

private:
    std::string isbn;
    std::string title;
    std::string author;
    std::string copyright_date;
    bool ischeckedout;

    bool isValidISBN(const std::string& isbn) const {
        // Regular expression for ISBN format: n-n-n-x
        std::regex pattern("\\d{1,}-\\d{1,}-\\d{1,}-[A-Za-z]");
        return std::regex_match(isbn, pattern);
    }
};

int main()
{
    Book mybook("1-234-3345-X", "john cena","kanye west","2024");

    std::cout << mybook.getISBN() << '\n';
    std::cout << mybook.getTitle() << '\n';
    std::cout << mybook.getAuthor() << '\n';
    std::cout << mybook.getCopyrightDate() << '\n';

    mybook.checkout();
    std::cout << "Is my book checked out? " << (mybook.getIsCheckedOut() ? "Yes" : "No") << '\n';

    mybook.checkin();
    std::cout << "Is my book checked out? " << (mybook.getIsCheckedOut() ? "Yes" : "No") << '\n';

    return 0;
}