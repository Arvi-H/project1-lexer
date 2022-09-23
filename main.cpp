#include "Lexer.h"
#include <fstream>
#include <sstream>

int main(int argc, char** argv) {
// File I/O
    std::ifstream input;
    std::stringstream in;

// Convert file to a string stream
    input.open(argv[1]);
    in << input.rdbuf();
    input.close();

// Convert string stream to a string
    std::string myFileString = in.str();

// Run Lexer
    Lexer* lexer = new Lexer();
    lexer->Run(myFileString);
    lexer->printToken();

    delete lexer;
    return 0;
}