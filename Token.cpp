#include "Token.h"
#include "sstream"

Token::Token(TokenType type, std::string description, int line) {
    this->type = type;
    this->description = description;
    this->line = line;
}

std::string Token::TokenConverter(TokenType type) {
    switch(type) {
    case TokenType::COLON:
        return "COLON";;
    case TokenType::COLON_DASH:
        return "COLON_DASH";
    default:
        return "UNDEFINED";
    }
}

std::string Token::toString() {
    std::stringstream out;

    out << "(" << TokenConverter(type) << "," << " \" " << description << " \" " << "," << line << ")";
    
    return out.str();
}