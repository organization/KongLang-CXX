#pragma once

class LoopOpen : public Token {
public:
    LoopOpen() : Token() {
        tokenType = TokenType::LOOP_OPEN;
    }
};