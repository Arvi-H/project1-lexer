#ifndef RULES_AUTOMATON_H
#define RULES_AUTOMATON_H

#include "Automaton.h"

class RulesAutomaton : public Automaton {
public:
    RulesAutomaton() : Automaton(TokenType::RULES) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
};

#endif // RULES_AUTOMATON_H


