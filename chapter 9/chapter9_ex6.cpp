#include <iostream> 
#include <string>
#include <regex>

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

    bool operator==(const Book& other) const {
        return isbn == other.isbn;
    }

    bool operator!=(const Book& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Book& book)
    {
        os << "\nBook Title: " << book.title;
        os << "\nBook Author: "<< book.author;
        os << "\nBook ISBN: " << book.isbn;

        return os;
    }

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
    Book mybook1("1-234-3345-X", "john cena","kanye west","2024");
    Book mybook2("1-234-3347-X", "cristiano ronaldo","ranbdom author","2023");

    std::cout << "\nBook1  " << mybook1 << std::endl;
    std::cout << "\nBook2  " << mybook2 << std::endl;
    

    std::cout << "\nAre the books with the same ISBN? " << (mybook1 == mybook2 ? "Yes" : "No") << '\n';
    std::cout << "Are the books with different ISBNs? " << (mybook1 != mybook2 ? "Yes" : "No") << '\n';

    return 0;
}