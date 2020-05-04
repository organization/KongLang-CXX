#pragma once

class StdInput : public Token {
public:
    StdInput() : Token() {
        tokenType = TokenType::STD_INPUT;
    }
};