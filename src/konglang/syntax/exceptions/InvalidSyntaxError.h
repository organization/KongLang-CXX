#pragma once

class InvalidSyntaxError : public std::runtime_error {
public:
    explicit InvalidSyntaxError(const std::string& cause) : runtime_error(cause) {};
};
