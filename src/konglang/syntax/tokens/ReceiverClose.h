#pragma once

class ReceiverClose : public Token {
public:
    ReceiverClose() : Token() {
        tokenType = TokenType::RECEIVER_CLOSE;
    }
};