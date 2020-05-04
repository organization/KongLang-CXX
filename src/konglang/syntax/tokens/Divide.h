#pragma once

class Divide : public Token {
public:
    Divide() : Token() {
        tokenType = TokenType::DIVIDE;
    }
};