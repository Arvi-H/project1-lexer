#include "IDAutomaton.h"

void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[inputRead])) {
        inputRead++;
        S1(input);
    }  
}

void IDAutomaton::S1(const std::string& input) {
    if (isalpha(input[inputRead]) || isdigit(input[inputRead])) {
        inputRead++;
        S1(input);
    }
}
