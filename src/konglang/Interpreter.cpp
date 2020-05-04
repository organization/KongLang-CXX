#include "Interpreter.h"

#include <memory>
#include <unordered_map>
#include <stack>

#include "syntax/exceptions/InvalidSyntaxError.h"

void parseNumberExpression(std::string& input, std::string::size_type& i, std::vector<Token>& tokens, bool isInput, bool isAddress) {
    while (i < input.size()) {
        switch (input[i]) {
            case ' ':
                i++;
                continue;
            case '-':
                tokens.emplace_back(Subtract());
                i++;
                continue;
            case '+':
                tokens.emplace_back(Add());
                i++;
                continue;
            case '/':
                tokens.emplace_back(Divide());
                i++;
                continue;
            case '*':
                tokens.emplace_back(Multiply());
                i++;
                continue;
            case '2':
                if (input[i - 1] == '2') {
                    throw InvalidSyntaxError(std::string("Invalid character: ") + input[i]);
                }
                tokens.emplace_back(Two());
                i++;
                continue;
            case '#':
                if (isInput)
                    tokens.emplace_back(StdInput());
                else
                    tokens.emplace_back(StdOutput());
                i++;
                continue;
            case '>':
                if (!isAddress && !isInput) {
                    throw InvalidSyntaxError(std::string("Invalid character: ") + input[i]);
                }
                i--;
                return;
            case ')':
                if (!isAddress && isInput) {
                    throw InvalidSyntaxError(std::string("Invalid character: ") + input[i]);
                }
                i--;
                return;
            case '{':
            case '}':
                if (isAddress) {
                    throw InvalidSyntaxError(std::string("Invalid character: ") + input[i]);
                }
                i--;
                return;
            default:
                throw InvalidSyntaxError(std::string("Invalid character: ") + input[i]);
        }
    }
}

std::vector<std::vector<Token>>&& tokenize(std::string&& input) {
    std::vector<std::vector<Token>> tokens;
    std::vector<Token> lineTokens;

    size_t transmitterCount = 0;
    bool usingTransmitter = true;
    size_t receiverCount = 0;
    bool usingReceiver = true;
    size_t loopCount = 0;

    for (std::string::size_type i = 0; i < input.size(); i++) {
        switch (input[i]) {
            case '\n':
                tokens.emplace_back(lineTokens);
                lineTokens.clear();
                usingReceiver = false;
                usingTransmitter = false;
                break;
            case ' ':
                continue;
            case '<':
                if (usingTransmitter) {
                    throw InvalidSyntaxError("Each command need to be separated by a newline character");
                }

                transmitterCount++;
                usingTransmitter = true;
                lineTokens.emplace_back(TransmitterOpen());
                parseNumberExpression(input, ++i, lineTokens, true, true);
                break;
            case '>':
                if (transmitterCount <= 0) {
                    throw InvalidSyntaxError("Unexpected character '>' (expected: '<' )");
                }
                transmitterCount--;
                lineTokens.emplace_back(TransmitterClose());
                break;
            case '(':
                if (usingReceiver) {
                    throw InvalidSyntaxError("Each command need to be separated by a newline character");
                }

                receiverCount++;
                usingReceiver = true;
                lineTokens.emplace_back(ReceiverOpen());
                parseNumberExpression(input, ++i, lineTokens, false, true);
                break;
            case ')':
                if (receiverCount <= 0) {
                    throw InvalidSyntaxError("Unexpected character ')' (expected: '(' )");
                }
                receiverCount--;
                lineTokens.emplace_back(ReceiverClose());
                break;
            case '}':
                lineTokens.emplace_back(AssignRight());
                break;
            case '{':
                lineTokens.emplace_back(AssignLeft());
                break;
            case '[':
                if (0 < i - 2 && input[i - 2] == '>') {
                    loopCount++;
                    lineTokens.emplace_back(LoopOpen());
                    break;
                } else {
                    throw InvalidSyntaxError("Unexpected character '[' (expected: '<Number>' )");
                }
            case ']':
                if (loopCount <= 0) {
                    throw InvalidSyntaxError("Unexpected character ']' (expected: '<Number> [' )");
                }
                loopCount--;
                break;
            case '-':
                lineTokens.emplace_back(Subtract());
                goto PARSE_NUMBER_EXPRESSION;
            case '+':
                lineTokens.emplace_back(Add());
                goto PARSE_NUMBER_EXPRESSION;
            case '/':
                lineTokens.emplace_back(Divide());
                goto PARSE_NUMBER_EXPRESSION;
            case '*':
                lineTokens.emplace_back(Multiply());
                goto PARSE_NUMBER_EXPRESSION;
            case '2':
                lineTokens.emplace_back(Two());
                PARSE_NUMBER_EXPRESSION:
                    parseNumberExpression(input, ++i, lineTokens, false, false);
                break;
            default:
                throw InvalidSyntaxError(std::string("Invalid character: ") + input[i]);
        }
    }

    if (receiverCount) {
        throw InvalidSyntaxError("The receiver was not closed properly");
    } else if (transmitterCount) {
        throw InvalidSyntaxError("The sender was not closed properly");
    } else if (loopCount) {
        throw InvalidSyntaxError("The loop was not closed properly");
    }

    return std::move(tokens);
}

void calculateNumberExpression(std::vector<Token>&& parsedToken) {

}

void parse(std::vector<std::vector<Token>>&& parsedTokensList) {
    std::unordered_map<int64_t, int64_t> virtualMemory;
    int64_t number;

    for (const auto& parsedTokens : parsedTokensList) {
        int64_t value = 0;
        for (size_t i = 0; i < parsedTokens.size(); i++) {
            switch (parsedTokens[i].tokenType) {
                case TokenType::TRANSMITTER_OPEN:
                    break;
                case TokenType::TRANSMITTER_CLOSE:
                    break;
                case TokenType::RECEIVER_OPEN:
                    break;
                case TokenType::RECEIVER_CLOSE:
                    break;
                case TokenType::ASSIGN_LEFT:
                    break;
                case TokenType::ASSIGN_RIGHT:
                    break;
                case TokenType::TWO:
                    break;
                case TokenType::ADD:
                    break;
                case TokenType::SUBTRACT:
                    break;
                case TokenType::MULTIPLY:
                    break;
                case TokenType::DIVIDE:
                    break;
                case TokenType::LOOP_OPEN:
                    break;
                case TokenType::LOOP_CLOSE:
                    break;
                case TokenType::STD_INPUT:
                    break;
                case TokenType::STD_OUTPUT:
                    break;
            }
        }
    }
}

void konglang::execute(std::string&& input) {
    auto parsedToken = tokenize(std::move(input));

    parse(std::move(parsedToken));
}
