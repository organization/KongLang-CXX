#pragma once

class Multiply : public Token {
public:
    Multiply() : Token() {
        tokenType = TokenType::MULTIPLY;
    }
};