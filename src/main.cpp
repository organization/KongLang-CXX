#include <iostream>
#include "konglang/Interpreter.h"

int main() {
    auto v = parse("(2 - 2) { 2 / 2");
    for (auto a : v) {
        switch (a.tokenType) {
            case TokenType::SENDER_OPEN:
                std::cout << "SENDER_OPEN" << std::endl;
                break;
            case TokenType::SENDER_CLOSE:
                std::cout << "SENDER_CLOSE" << std::endl;
                break;
            case TokenType::RECEIVER_OPEN:
                std::cout << "RECEIVER_OPEN" << std::endl;
                break;
            case TokenType::RECEIVER_CLOSE:
                std::cout << "RECEIVER_CLOSE" << std::endl;
                break;
            case TokenType::ASSIGN_LEFT:
                std::cout << "ASSIGN_LEFT" << std::endl;
                break;
            case TokenType::ASSIGN_RIGHT:
                std::cout << "ASSIGN_RIGHT" << std::endl;
                break;
            case TokenType::TWO:
                std::cout << "TWO" << std::endl;
                break;
            case TokenType::ADD:
                std::cout << "ADD" << std::endl;
                break;
            case TokenType::SUBTRACT:
                std::cout << "SUBTRACT" << std::endl;
                break;
            case TokenType::MULTIPLY:
                std::cout << "MULTIPLY" << std::endl;
                break;
            case TokenType::DIVIDE:
                std::cout << "DIVIDE" << std::endl;
                break;
            case TokenType::LOOP_OPEN:
                std::cout << "LOOP_OPEN" << std::endl;
                break;
            case TokenType::LOOP_CLOSE:
                std::cout << "LOOP_CLOSE" << std::endl;
                break;
            case TokenType::STD_INPUT:
                std::cout << "STD_INPUT" << std::endl;
                break;
            case TokenType::STD_OUTPUT:
                std::cout << "STD_OUTPUT" << std::endl;
                break;
        }
    }
}