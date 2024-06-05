#include "lib.h"
#include <iostream>

namespace Lib {

    Book::Book(const std::string& isbn, const std::string& title, const std::string& author, const std::string& copyright_date, Genre genre)
        : isbn(isbn), title(title), author(author), copyright_date(copyright_date), ischeckedout(false), genre(genre) {}

    std::string Book::getISBN() const { return isbn; }
    std::string Book::getTitle() const { return title; }
    std::string Book::getAuthor() const { return author; }
    std::string Book::getCopyrightDate() const { return copyright_date; }
    bool Book::getIsCheckedOut() const { return ischeckedout; }
    Book::Genre Book::getGenre() const { return genre; }

    void Book::checkout() { ischeckedout = true; }
    void Book::checkin() { ischeckedout = false; }

    bool Book::operator==(const Book& other) const { return isbn == other.isbn; }
    bool Book::operator!=(const Book& other) const { return !(*this == other); }

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "\nBook Title: " << book.title;
        os << "\nBook Author: " << book.author;
        os << "\nBook ISBN: " << book.isbn;
        return os;
    }

    bool Book::isValidISBN(const std::string& isbn) const {
        // Regular expression for ISBN format: n-n-n-x
        std::regex pattern("\\d{1,}-\\d{1,}-\\d{1,}-[A-Za-z]");
        return std::regex_match(isbn, pattern);
    }

    Patron::Patron(const std::string& name, const int& card_number, const double& fees)
        : name(name), card_number(card_number), fees(fees) { }

    std::string Patron::get_name() const { return name; }
    int Patron::get_cardnum() const { return card_number; }
    double Patron::get_fees() const { return fees; }

    

    std::ostream& operator<<(std::ostream& os, const Patron& patron)
    {
        os << "\nName: " << patron.name;
        os << "\nCard Number: " << patron.card_number;
        os << "\nFees: " << patron.fees;

        return os;
    }
    
    void Patron::set_fees(double f)
    {
        fees = f;
    }
    
    bool owes_fees(const Patron& p)
    {
        return p.get_fees() > 0;
    }

    bool operator==(const Patron& p1, const Patron& p2)
    {
        return p1.get_cardnum() == p2.get_cardnum();
    }

    bool operator!=(const Patron& p1, const Patron& p2)
    {
        return !(p1 == p2);
    }

    std::vector<Lib::Book> Lib::Library::get_books() const {
            return books;
    }

}
