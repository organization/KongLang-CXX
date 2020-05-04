#pragma once

class ReceiverOpen : public Token {
public:
    ReceiverOpen() : Token() {
        tokenType = TokenType::RECEIVER_OPEN;
    }
};