#pragma once

class Two : public Token {
public:
    Two() : Token() {
        tokenType = TokenType::TWO;
    }
};