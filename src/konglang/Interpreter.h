#pragma once

#include "syntax/Token.h"
#include <string>
#include <vector>

std::vector<Token>&& tokenize(std::string&& input);
bool interpret(std::string&&);
