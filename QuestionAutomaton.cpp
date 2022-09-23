#include "QuestionAutomaton.h"

void QuestionAutomaton::S0(const std::string& input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
}
