#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QuestionAutomaton.h"
#include "RightParenAutomaton.h"
#include "LeftParenAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include <iostream>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // Deallocate tokens memeory
    for (int i = 0; i < tokens.size(); i++) {
        delete tokens.at(i);
    }

    tokens.clear();

    // Deallocate automatas memeory
    for (int i = 0; i < automata.size(); i++) {
        delete automata.at(i);
    }

    automata.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QuestionAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;

    // While there are more characters to tokenize
    while (input.size() > 0) {
        int maxRead = 0;
        maxAutomata = automata.at(0);
        
        // You need to handle whitespace in between tokens
        while(isspace(input.at(0))) {
            if (input.at(0) == '\n') {
                lineNumber++; // continue
            }

            input.erase(0,1); // remove whitespace
        }  
        // Each automaton runs with the same input
            for (Automaton *automaton : automata) {
                int inputRead = automaton->Start(input);
                
                // Figure out the max automata
                if (inputRead > maxRead) {
                    maxRead = inputRead;
                    maxAutomata = automaton;
                } 
            }  
        
        // Here is the "Max" part of the algorithm
            if (maxRead > 0) {
                newToken = maxAutomata->CreateToken(input.substr(0, maxRead), lineNumber);
                lineNumber += maxAutomata->NewLinesRead();
        // No automaton accepted input
            } else {
                maxRead = 1;
                std::string test = input.substr(0, maxRead);
                newToken = new Token(TokenType::UNDEFINED, test, lineNumber);
            }

        // Update input by removing characters read to create Token
            tokens.push_back(newToken);
            input.erase(0, maxRead);

    }
    // End of File 
        newToken = new Token(TokenType::ENDFILE, "", lineNumber);
        tokens.push_back(newToken);
    
}
   
void Lexer::printTotalTokens() {
    int totalTokens = tokens.size();
    while (!tokens.empty()) {
        std::cout << tokens.front()->toString() << std::endl;
        tokens.erase(tokens.begin());
    }
    std::cout << "Total Tokens = " << totalTokens << std::endl;
}