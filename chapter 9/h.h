#ifndef H_H
#define H_H

#include <iostream>
#include <string>
#include <regex>

namespace Lib{

    class Book{
    public:
        enum class Genre{
            FINCTION,
            NON_FINCTION,
            MYSTERY,
            SCIENCE_FICTION,
            ACTION,
            FANTASY,
            HISTORICAL,
            OTHER
        };
        

        Book(const std::string& isbn, const std::string& title, const std::string& author, const std::string& copyright_date, Genre genre)
            :isbn(isbn), title(title), author(author), copyright_date(copyright_date), ischeckedout(false), genre(genre) { }

        std::string getISBN() const { return isbn; }
        std::string getTitle() const { return title; }
        std::string getAuthor() const { return author; }
        std::string getCopyrightDate() const { return copyright_date; }
        bool getIsCheckedOut() const { return ischeckedout; }
        Genre getGenre() const { return genre; }

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
        Genre genre;

        bool isValidISBN(const std::string& isbn) const {
            // Regular expression for ISBN format: n-n-n-x
            std::regex pattern("\\d{1,}-\\d{1,}-\\d{1,}-[A-Za-z]");
            return std::regex_match(isbn, pattern);
        }
    };
}
    #endif