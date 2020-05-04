#pragma once

class Add : public Token {
public:
    Add() : Token() {
        tokenType = TokenType::ADD;
    }
};