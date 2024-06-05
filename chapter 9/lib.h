#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include "Chrono.h"

namespace Lib {
    class Book {
    public:
        enum class Genre {
            FICTION,
            NON_FINCTION,
            MYSTERY,
            SCIENCE_FICTION,
            ACTION,
            FANTASY,
            HISTORICAL,
            OTHER
        };

        Book(const std::string& isbn, const std::string& title, const std::string& author, const std::string& copyright_date, Genre genre);

        std::string getISBN() const;
        std::string getTitle() const;
        std::string getAuthor() const;
        std::string getCopyrightDate() const;
        bool getIsCheckedOut() const;
        Genre getGenre() const;

        void checkout();
        void checkin();

        bool operator==(const Book& other) const;
        bool operator!=(const Book& other) const;

        friend std::ostream& operator<<(std::ostream& os, const Book& book);

    private:
        std::string isbn;
        std::string title;
        std::string author;
        std::string copyright_date;
        bool ischeckedout;
        Genre genre;

        bool isValidISBN(const std::string& isbn) const;
    };

    class Patron{
    public:
        Patron(const std::string& name, const int& card_number, const double& fees);
        //Patron();

        std::string get_name() const;
        int get_cardnum() const;
        double get_fees() const;

        void set_fees(double f);

        friend std::ostream& operator<<(std::ostream& os, const Patron& patron);

        

    private:
        std::string name;
        int card_number;
        double fees;
    };

    bool owes_fees(const Patron& p);
    bool operator==(const Patron& p1, const Patron& p2);
    bool operator!=(const Patron& p1, const Patron& p2);

    class Library {
    public:
        struct Transaction {
        
            Book book;
            Patron patron;
            Chrono::Date date;
        
            Transaction(const Book& b, const Patron& p, const Chrono::Date& d);
        };

        Library() {}

        void add_book(const Book& b) {
            books.push_back(b);
        }

        void add_patron(const Patron& p) {
            patrons.push_back(p);
        }

        void check_out(const Book& b, const Patron& p, const Chrono::Date& d) {
            // Check if both book and patron are in the library
            if (std::find(books.begin(), books.end(), b) == books.end()) {
                std::cout << "Error: Book not found in the library." << std::endl;
                return;
            }

            if (std::find(patrons.begin(), patrons.end(), p) == patrons.end()) {
                std::cout << "Error: Patron not found in the library." << std::endl;
                return;
            }

            // Check if the patron owes fees
            if (owes_fees(p)) {
                std::cout << "Error: Patron owes fees." << std::endl;
                return;
            }

            // Create transaction and add it to the vector
            transactions.push_back(Transaction(b, p, d));

            // Mark the book as checked out
            auto it = std::find(books.begin(), books.end(), b);
            it->checkout();
        }

        std::vector<std::string> get_patrons_with_fees() const {
            std::vector<std::string> debtors;
            for (const auto& patron : patrons) {
                if (owes_fees(patron)) {
                    debtors.push_back(patron.get_name());
                }
            }
            return debtors;
        }
        std::vector<Book> get_books() const;

        

    private:
        std::vector<Book> books;
        std::vector<Patron> patrons;
        std::vector<Transaction> transactions;
    };

    
}

#endif
