#pragma once

class LoopClose : public Token {
public:
    LoopClose() : Token() {
        tokenType = TokenType::LOOP_CLOSE;
    }
};
