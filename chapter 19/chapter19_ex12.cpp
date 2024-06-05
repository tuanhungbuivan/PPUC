#include <iostream>
#include <string>
#include <fstream>

class File_handle{
private:
    std::fstream file;

public:
    explicit File_handle(const std::string& filename) { 
        file.open(filename,  std::ios::in || std::ios::out || std::ios::app);
        if(!file.is_open()){
            std::cerr << "Error wrong filename \n";
            exit(EXIT_FAILURE);
        }
    }

    ~File_handle(){
        if(file.is_open()){
            file.close();
        }
    }

    void write(const std::string& data){
        if(file.is_open()){
            file << data << std::endl;
        }else{
            throw std::ios_base::failure("File is not open");
        }
    }

    void read(){
        if(file.is_open()){
            std::string lines;
            while(std::getline(file,lines)){
                std::cout << lines << std::endl;
            }
            file.clear();
            file.seekg(0); // Rewind to the beginning of the file for future reads
        }else{
            throw std::ios_base::failure("File is not open");
        }
    }

    bool is_open() const {
        return file.is_open();
    }
};

int main() {
    try {
        File_handle fh("example.txt");
        
        if (fh.is_open()) {
            fh.write("This is a test line.");
            fh.write("Another line.");
            fh.read();
        }
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}