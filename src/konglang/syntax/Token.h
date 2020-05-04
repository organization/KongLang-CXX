#pragma once

enum class TokenType {
    TRANSMITTER_OPEN,
    TRANSMITTER_CLOSE,
    RECEIVER_OPEN,
    RECEIVER_CLOSE,
    ASSIGN_LEFT,
    ASSIGN_RIGHT,

    TWO,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,

    LOOP_OPEN,
    LOOP_CLOSE,

    STD_INPUT,
    STD_OUTPUT
};

class Token {
public:
    TokenType tokenType;
};

#include "tokens/AssignLeft.h"
#include "tokens/AssignRight.h"
#include "tokens/ReceiverClose.h"
#include "tokens/ReceiverOpen.h"
#include "tokens/TransmitterClose.h"
#include "tokens/TransmitterOpen.h"

#include "tokens/Two.h"
#include "tokens/Add.h"
#include "tokens/Divide.h"
#include "tokens/Multiply.h"
#include "tokens/Subtract.h"

#include "tokens/LoopOpen.h"
#include "tokens/LoopClose.h"

#include "tokens/StdInput.h"
#include "tokens/StdOutput.h"