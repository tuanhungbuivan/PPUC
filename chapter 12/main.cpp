#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    using namespace Graph_lib;
    Point tl {100, 100};        // top left corner of window

    Simple_window win {tl, 600, 400, "My window"};

    Polygon poly;                   // a polygon; a Polygon is a kind of Shape
    poly.add(Point{300, 200});      // three points make a triangle
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});

    poly.set_color(Color::red);

    win.attach (poly);
    win.wait_for_button();
   
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}
