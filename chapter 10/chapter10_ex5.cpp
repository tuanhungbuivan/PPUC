//  Close the ofstream and then open an ifstream for mydata.txt. Read the data
//  from mydata.txt and store it in a new vector called processed_points.

#include <iostream>
#include <fstream>
#include <vector>

class Point {
public:
    Point(double x, double y);
    Point();
    double x() const { return m_x; }
    double y() const { return m_y; }
private:
    double m_x;
    double m_y;
};

Point::Point(double x, double y)
: m_x{x}, m_y{y} {  };

Point::Point()
: m_x{0}, m_y{0} {  };

std::istream& operator>>(std::istream& is, Point& p)
{
    double x, y;
    char ch1, ch2, ch3;

    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (is && ch1 == '(' && ch2 == ',' && ch3 == ')')
        p = Point(x, y);
    else 
        is.clear(std::ios_base::failbit);
    
    return is;
}

std::ostream& operator<<(std::ostream& os,std::vector<Point>& vp)
{
    for (Point p : vp)
        os << '(' << p.x() << ", " << p.y() << ')' << '\n';

    return os;
}

constexpr int no_points{7};
const std::string of_name = "mydata.txt";
const std::string if_name = "mydata.txt";

void fill_from_file(std::vector<Point>& points, const std::string& name)
{
    std::ifstream ist{name};
    if (!ist) {
        std::cerr << "Error cant read file";
        return;
    }
    for (Point p; ist >> p;)
        points.push_back(p);
}

int main()
{
    std::vector<Point> original_points;

    std::cout << "Write " << no_points << " points as pairs of coordinates with" 
         << " format (x,y):\n";

    while (original_points.size() < no_points) {
        Point p;
        if (std::cin >> p) {
            original_points.push_back(p);
        }
        else {
            std::cout << "That's not a point!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << "You've entered those points:\n" << original_points;

    std::cout << "Writing to file " << of_name << " ...\n";
    std::ofstream ost{of_name};
    if (!ost){
        std::cerr << "Error cant open file ";
        return 0;
    }
    ost << original_points;
    ost.close();

    std::cout << "Reading point from file " << if_name << " ...\n";
    std::vector<Point> processed_points;
    fill_from_file(processed_points, if_name);

    std::cout << processed_points;   // Test if we read something
    
    return 0;
}
