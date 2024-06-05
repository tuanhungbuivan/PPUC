#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main() {
    // Create a window
    Fl_Window window(600, 400, "Simple Window");
    
    // Create a label
    Fl_Box box(20, 40, 560, 320, "Hello, FLTK!");

    // Show the window
    window.show();

    // Run the FLTK event loop
    return Fl::run();
}
