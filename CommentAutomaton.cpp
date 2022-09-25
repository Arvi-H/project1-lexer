#include "CommentAutomaton.h"

#include <iostream>
#include <sstream>

using namespace std;

void CommentAutomaton::S0(const std::string& input) {
    if (input.at(inputRead) == '#') {
        inputRead++;
        S1(input);
    } 
}

void CommentAutomaton::S1(const std::string& input) {
     if (input.at(inputRead) != '|') { 
        inputRead++;
        S2(input);
     } else if (input.at(inputRead) == '|') {
        multiline = true;
        inputRead++;
        S3(input);
     }
} 

void CommentAutomaton::S2(const std::string& input) { 
    if (input.at(inputRead) != '\n') { 
        inputRead++;
        S2(input);
    } else {
        return;
    }
}

void CommentAutomaton::S3(const std::string& input) { 
    if (inputRead >= input.size()) { 
        return;
    } else if (input.at(inputRead) != '|') {
        if (input.at(inputRead) == '\n') {
            multilineInc++;
        }

        inputRead++;
        S3(input);
    } else if (input.at(inputRead) == '|') {
        inputRead++;
        S4(input);
    }

    if (input.at(0) == '\n') {
        inputRead++; 
    }
}

void CommentAutomaton::S4(const std::string& input) { 
    if (input.at(inputRead) == '#') {
        inputRead++;
        return;
    } else if (input.at(inputRead) == '|') {
        inputRead++;
        S3(input);
    } 
}