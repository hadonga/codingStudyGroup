#include "iostream"
#include <fstream>
#include <string>

int input_file_stream_example(){

    std::ifstream ifs("data.txt");
    if (ifs.is_open()){
        std::string line;
        std::getline(ifs, line);
        std::cout << "Read from the file: " << line << '\n';
    }
    ifs.close();
    return 0;
}

int main(){

    std::cout << "hello CS106L!";
    std::string student_input;
    std::cin >> student_input;

    //create a file called "data.txt"
    std::ofstream fout("data.txt");
    fout << "im writing to this file";
    fout.close();
    // std::ifstream fin("data.txt");
    // std::string first_word;

    // fin >> student_input;
    std::cout<< student_input <<'\n';

    input_file_stream_example();
}
