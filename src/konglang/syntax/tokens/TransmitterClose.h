#pragma once

class TransmitterClose : public Token {
public:
    TransmitterClose() : Token() {
        tokenType = TokenType::TRANSMITTER_CLOSE;
    }
};