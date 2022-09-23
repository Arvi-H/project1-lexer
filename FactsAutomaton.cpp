#include "FactsAutomaton.h"

void FactsAutomaton::S0(const std::string& input) {
    if (input[inputRead] == 'F') {
        inputRead++;
        S1(input);
    }
}

void FactsAutomaton::S1(const std::string& input) {
    if (input[inputRead] == 'a') {
        inputRead++;
        S2(input);
    }
}

void FactsAutomaton::S2(const std::string& input) {
    if (input[inputRead] == 'c') {
        inputRead++;
        S3(input);
    }
}

void FactsAutomaton::S3(const std::string& input) {
    if (input[inputRead] == 't') {
        inputRead++;
        S4(input);
    }
}

void FactsAutomaton::S4(const std::string& input) {
    if (input[inputRead] == 's') {
        inputRead++;
    }
}
