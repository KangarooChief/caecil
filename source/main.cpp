#include <iostream>
#include <lex.hpp>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include <vector>

int main()
{
    spdlog::set_level(spdlog::level::debug);
    std::vector<Token> tokens = getTokens();

    std::cout << std::format("Found {} tokens", tokens.size()) << std::endl;

    for (Token t : tokens)
    {
        switch (t.type)
        {
        case (TokenType::id):
            std::cout << "id: " + std::get<std::string>(t.data) << std::endl;
            break;
        case (TokenType::number):
            std::cout << std::format("number: {}", std::get<double>(t.data)) << std::endl;
            break;
        case (TokenType::other):
            std::cout << "other: " + std::get<std::string>(t.data) << std::endl;
            break;
        case (TokenType::function):
            std::cout << "function" << std::endl;
            break;
        case (TokenType::eof):
            std::cout << "eof" << std::endl;
            break;
        }
    }
}
