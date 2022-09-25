#include "StringAutomaton.h"

#include <iostream>
#include <sstream>


using namespace std;

void StringAutomaton::S0(const std::string& input) {
    if (input[inputRead] == '\'') {
        inputRead++;
        S1(input);  
    } else {
        Serr();
    }
}


void StringAutomaton::S1(const std::string& input) {
    if (inputRead >= input.size()) {
        // terminateString = true;
        return;
    } else if (input[inputRead] == '\'') {
        inputRead++;
        S2(input);
    } else {
        inputRead++;
        S1(input);
    }
}

void StringAutomaton::S2(const std::string& input) {
    if (inputRead >= input.size()) {
        // terminateString = true;
        return;
    } else if (input[inputRead] == '\'') {
        inputRead++;
        S1(input);
    } else {
        return;
    }
}

