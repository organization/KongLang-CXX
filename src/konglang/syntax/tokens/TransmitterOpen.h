#pragma once

class TransmitterOpen : public Token {
public:
    TransmitterOpen() : Token() {
        tokenType = TokenType::TRANSMITTER_OPEN;
    }
};