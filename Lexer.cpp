#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include <iostream>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;

    // While there are more characters to tokenize
    while (input.size() > 0) {
        int maxRead = 0;
        maxAutomata = automata[0];
        
        // You need to handle whitespace in between tokens
        if(isspace(input.at(0))) {
            if (input.at(0) == '\n') {
                lineNumber++; // continue
            }

            input.erase(0,1); // remove whitespace
        } 
        
    // Here is the parallel part of the algorithm

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

        // Update `input` by removing characters read to create Token
            tokens.push_back(newToken);
            input.erase(0, maxRead);

        
        // add end of file token to all tokens
        newToken = new Token(TokenType::ENDFILE, "", lineNumber);
        tokens.push_back(newToken);
    }
    
}
   
void Lexer::printToken() {
    int totalTokens = tokens.size();
    while (!tokens.empty()) {
        std::cout << tokens.front()->toString() << std::endl;
        tokens.erase(tokens.begin());
    }
    std::cout << "Total Tokens = " << totalTokens;
}