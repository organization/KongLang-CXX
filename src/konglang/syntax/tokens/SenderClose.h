#pragma once

class SenderClose : public Token {
public:
    SenderClose() : Token() {
        tokenType = TokenType::SENDER_CLOSE;
    }
};