#pragma once

class ReceiverClose : Token {
    ReceiverClose() : Token() {
        tokenType = TokenType::RECEIVER_CLOSE;
    }
};