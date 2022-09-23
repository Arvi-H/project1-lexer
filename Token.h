#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    QUESTION,
    RIGHT_PAREN,
    LEFT_PAREN,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    UNDEFINED, 
    ENDFILE
};

class Token {
private:
    TokenType type;
    std::string description;
    int line;

public:
    Token(TokenType type, std::string description, int line);

    std::string TokenConverter(TokenType type);
    std::string toString();
};

#endif // TOKEN_H