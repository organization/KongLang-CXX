#pragma once

class SenderOpen : public Token {
public:
    SenderOpen() : Token() {
        tokenType = TokenType::SENDER_OPEN;
    }
};