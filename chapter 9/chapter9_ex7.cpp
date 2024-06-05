#include "lib.h"
// ex 7 create an enumerated type for the Book class called Genre
// ex 8 create a Patron class
// ex 9 create a library class inlcude vectors of books and patrons, struct called transaction


using namespace Lib;

/*
void ex()
{   
    
    Book mybook1("1-234-3345-X", "John Cena", "Kanye West", "2024", Book::Genre::ACTION);
    Book mybook2("1-234-3347-X", "Cristiano Ronaldo", "Random Author", "2023", Book::Genre::FANTASY);

    std::cout << "\nBook1: " << mybook1 << std::endl;
    std::cout << "\nBook2: " << mybook2 << std::endl;

    std::cout << "\nAre the books with the same ISBN? " << (mybook1 == mybook2 ? "Yes" : "No") << '\n';
    std::cout << "Are the books with different ISBNs? " << (mybook1 != mybook2 ? "Yes" : "No") << '\n';
}

void ex8()
{   
    Patron mypatron1("Marcin", 100, 50.0);
    Patron mypatron2("Michal", 200, 20.0);

    std::cout << "\nPatron1: " << mypatron1 << std::endl;
    std::cout << "\nPatron2: " << mypatron2 << std::endl;

    mypatron1.set_fees(20);
    mypatron2.set_fees(10);

    std::cout << "\nPatron1 after paying back 20 fees: " << mypatron1 << std::endl;
    std::cout << "\nPatron2 after paying back 10 fees: " << mypatron2 << std::endl;

}
*/

void ex9()
{
    Library my_lib;

    Book mybook1("1-234-3345-X", "John Cena", "Kanye West", "2024", Book::Genre::ACTION);
    Book mybook2("1-234-3347-X", "Cristiano Ronaldo", "Random Author", "2023", Book::Genre::FANTASY);

    my_lib.add_book(mybook1);
    my_lib.add_book(mybook2);

    std::cout << "Books in the library:\n ";
    std::vector<Book> books = my_lib.get_books();
    for (const auto& book : books) {
        std::cout << book << '\n';
    }
}


int main()
{
    //ex();
    //ex8();
    ex9();

    return 0;
}


