#pragma once

class AssignLeft : public Token {
public:
    AssignLeft() : Token() {
        tokenType = TokenType::ASSIGN_LEFT;
    }
};