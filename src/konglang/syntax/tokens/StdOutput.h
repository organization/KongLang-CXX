#pragma once

class StdOutput : public Token {
public:
    StdOutput() : Token() {
        tokenType = TokenType::STD_OUTPUT;
    }
};