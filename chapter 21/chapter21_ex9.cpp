#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>

//---------------------------------------------------------------------------------------------------

class Date{
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(1970) { } 
    Date(int d, int m, int y) : day(d), month(m), year(y) { }

    int get_day() const { return day; }
    int get_month() const { return month; };
    int get_year() const { return year; }

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
    
};

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.get_day() << " / " << date.get_month() << " / " << date.get_year();

    return os;
}

std::istream& operator>>(std::istream& is, Date& date)
{
    char sep;
    is >> date.day >> sep >> date.month >> sep >> date.year;
    return is;
}

//---------------------------------------------------------------------------------------------------

class Purchase{
private:
    std::string name;
    double unit_price;
    int count;

public:
    Purchase() : name(""), unit_price(0.0), count(0) { }
    Purchase(const std::string& n, double up, int c)
        : name(n), unit_price(up), count(c) { }

    std::string get_name() const { return name; }
    double get_unit_price() const { return unit_price; }
    int get_count() const { return count; }

    friend std::ostream& operator<<(std::ostream& os, const Purchase& purchase);
    friend std::istream& operator>>(std::istream& is, Purchase& purchase);
};

std::ostream& operator<<(std::ostream& os, const Purchase& purchase)
{
    os << purchase.get_name() << " - " << purchase.get_unit_price() << " - " << purchase.get_count();
    return os;
}

std::istream& operator>>(std::istream& is, Purchase& purchase)
{
    is >> purchase.name >> purchase.unit_price >> purchase.count;
    return is;
}

//---------------------------------------------------------------------------------------------------

class Order{
private:
    std::string name;
    std::string address;
    Date date;
    std::vector<Purchase> purchases;

public:
    Order() : name(), address(), date(), purchases() { }
    Order(const std::string& n, const std::string& a, const Date& d, const std::vector<Purchase>& p)
        : name(n), address(a), date(d), purchases(p) { }

    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
    Date get_date() const { return date; }
    int n_purchases() const { return purchases.size(); }
    Purchase get_purchase(int i) const { return purchases[i]; }

    friend std::ostream& operator<<(std::ostream& os, const Order& order);
    friend std::istream& operator>>(std::istream& is, Order& order);
};

std::ostream& operator<<(std::ostream& os, const Order& order)
{
    os << "Order for " << order.get_name() << "\nAddress: " << order.get_address()
       << "\nDate: " << order.get_date() << "\nPurchases:\n";
    for (int i = 0; i < order.n_purchases(); ++i) {
        os << "  " << order.get_purchase(i) << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Order& order)
{
    std::getline(is >> std::ws, order.name);  // Read name
    std::getline(is, order.address);          // Read address
    is >> order.date;                         // Read date

    int num_purchases;
    is >> num_purchases;                      // Read number of purchases
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character after num_purchases

    order.purchases.resize(num_purchases);    // Resize the purchases vector
    for (int i = 0; i < num_purchases; ++i) {
        is >> order.purchases[i];             // Read each purchase
    }

    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline after the last purchase
    return is;
}

void read_orders(const std::string& filename, std::vector<Order>& orders)
{
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cerr << "Error: can't open file " << filename << '\n';
        std::exit(EXIT_FAILURE);
    }

    Order order;
    while (ifs >> order) {
        orders.push_back(order);
        ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ensure to skip to the next line after each order
    }
}

void write_orders(const std::string& filename, const std::vector<Order>& orders)
{
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Error: can't open file " << filename << '\n';
        std::exit(EXIT_FAILURE);
    }

    for (const auto& order : orders) {
        ofs << order;
        ofs << '\n';
    }
}

bool compare_by_name(const Order& a, const Order& b)
{
    return a.get_name() < b.get_name();
}

bool compare_by_address(const Order& a, const Order& b)
{
    return a.get_address() < b.get_address();
}

void print_orders(const std::vector<Order>& orders)
{
    for (const auto& order : orders) {
        std::cout << order << std::endl;
    }
}

void print_orders(const std::list<Order>& orders)
{
    for (const auto& order : orders) {
        std::cout << order << std::endl;
    }
}

double compute_total_value_v(const std::vector<Order>& orders) {
    double total_value = 0.0;
    for (const auto& order : orders) {
        for (int i = 0; i < order.n_purchases(); ++i) {
            const Purchase& purchase = order.get_purchase(i);
            total_value += purchase.get_unit_price() * purchase.get_count();
        }
    }
    return total_value;
}

double compute_total_value_l(const std::list<Order>& orders) {
    double total_value = 0.0;
    for (const auto& order : orders) {
        for (int i = 0; i < order.n_purchases(); ++i) {
            const Purchase& purchase = order.get_purchase(i);
            total_value += purchase.get_unit_price() * purchase.get_count();
        }
    }
    return total_value;
}

int main() 
{
    // Read orders from file
    std::vector<Order> orders1;
    read_orders("orders1.txt", orders1);

    std::cout << "Orders from orders1.txt:\n";
    print_orders(orders1);

    // Sort orders by name and write to file
    std::sort(orders1.begin(), orders1.end(), compare_by_name);
    write_orders("sorted_by_name.txt", orders1);

    // Read orders from another file into a list
    std::list<Order> orders2;
    std::ifstream ifs2("orders2.txt");
    if (!ifs2) {
        std::cerr << "Error: can't open file orders2.txt\n";
        std::exit(EXIT_FAILURE);
    }

    Order order;
    while (ifs2 >> order) {
        orders2.push_back(order);
        ifs2.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Orders from orders2.txt:\n";
    print_orders(orders2);

    // Sort orders by address and write to file
    orders2.sort(compare_by_address);
    std::ofstream ofs2("sorted_by_address.txt");
    if (!ofs2) {
        std::cerr << "Error: can't open file sorted_by_address.txt\n";
        std::exit(EXIT_FAILURE);
    }

    for (const auto& order : orders2) {
        ofs2 << order;
        ofs2 << '\n';
    }

    // Compute total value
    double total_value = compute_total_value_v(orders1) + compute_total_value_l(orders2);
    std::cout << "Total value of orders: $" << total_value << std::endl;

    return 0;
}