#pragma once

class AssignRight : public Token {
public:
    AssignRight() : Token() {
        tokenType = TokenType::ASSIGN_RIGHT;
    }
};