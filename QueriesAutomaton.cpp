#include "QueriesAutomaton.h"

void QueriesAutomaton::S0(const std::string& input) {
    if (input[inputRead] == 'Q') {
        inputRead++;
        S1(input);
    }
}

void QueriesAutomaton::S1(const std::string& input) {
    if (input[inputRead] == 'u') {
        inputRead++;
        S2(input);
    }
}

void QueriesAutomaton::S2(const std::string& input) {
    if (input[inputRead] == 'e') {
        inputRead++;
        S3(input);
    }
}

void QueriesAutomaton::S3(const std::string& input) {
    if (input[inputRead] == 'r') {
        inputRead++;
        S4(input);
    }
}

void QueriesAutomaton::S4(const std::string& input) {
    if (input[inputRead] == 'i') {
        inputRead++;
        S5(input);
    }
}

void QueriesAutomaton::S5(const std::string& input) {
    if (input[inputRead] == 'e') {
        inputRead++;
        S6(input);
    }
}

void QueriesAutomaton::S6(const std::string& input) {
    if (input[inputRead] == 's') {
        inputRead++;
    }
}
