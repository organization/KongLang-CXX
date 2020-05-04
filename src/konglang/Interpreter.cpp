#include "Interpreter.h"

#include <memory>
#include <unordered_map>

#include "syntax/exceptions/InvalidSyntaxError.h"

void parseNumberLiteral(std::string& input, std::string::size_type& i, std::vector<Token>& tokens, bool isInput) {
    while (i < input.size() - 1) {
        switch (input[++i]) {
            case 0x20:
            case 0x0a:
            case 0x0b:
            case 0x0c:
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
                if (!isInput) {
                    throw InvalidSyntaxError(std::string("Invalid character: ") + input[i]);
                }
                i--;
                return;
            case ')':
                if (isInput) {
                    throw InvalidSyntaxError(std::string("Invalid character: ") + input[i]);
                }
                i--;
                return;
            default:
                throw InvalidSyntaxError(std::string("Invalid character: ") + input[i]);
        }
    }
}

std::vector<Token>&& parse(std::string&& input) {
    std::vector<Token> tokens;

    size_t senderCount = 0;
    size_t receiverCount = 0;
    size_t loopCount = 0;

    for (std::string::size_type i = 0; i < input.size(); i++) {
        switch (input[i]) {
            case ' ':
                continue;
            case '<':
                senderCount++;
                tokens.emplace_back(SenderOpen());
                parseNumberLiteral(input, i, tokens, true);
                break;
            case '>':
                if (senderCount <= 0) {
                    throw InvalidSyntaxError("Unexpected character '>' (expected: '<' )");
                }
                senderCount--;
                tokens.emplace_back(SenderClose());
                break;
            case '(':
                receiverCount++;
                tokens.emplace_back(ReceiverOpen());
                parseNumberLiteral(input, i, tokens, false);
                break;
            case ')':
                if (receiverCount <= 0) {
                    throw InvalidSyntaxError("Unexpected character ')' (expected: '(' )");
                }
                receiverCount--;
                tokens.emplace_back(SenderClose());
                break;
            case '}':
                tokens.emplace_back(AssignRight());
                break;
            case '{':
                tokens.emplace_back(AssignLeft());
                break;
            case '[':
                if (0 < i - 2 && input[i - 2] == '>') {
                    loopCount++;
                    tokens.emplace_back(LoopOpen());
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
            default:
                throw InvalidSyntaxError(std::string("Invalid character: ") + input[i]);
        }
    }

    if (receiverCount) {
        throw InvalidSyntaxError("The receiver was not closed properly");
    } else if (senderCount) {
        throw InvalidSyntaxError("The sender was not closed properly");
    } else if (loopCount) {
        throw InvalidSyntaxError("The loop was not closed properly");
    }

    return std::move(tokens);
}

bool interpret(std::string&& input) {
    std::unordered_map<int64_t, int64_t> virtualMemory;
    std::vector<Token> parsedToken = parse(std::move(input));

    return true;
}
