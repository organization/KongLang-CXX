#pragma once

class Subtract : public Token {
public:
    Subtract() : Token() {
        tokenType = TokenType::SUBTRACT;
    }
};