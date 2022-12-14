#pragma once
#include "TokenType.hpp"
#include <any>
#include <string>

namespace Lox {
struct Token {
  Token();
  Token(TokenType type, std::string lexeme, int line);
  Token(TokenType type, std::string lexeme, std::any literal, int line);

  Token(const Token &);
  Token &operator=(const Token &);

  Token(Token &&) noexcept;
  Token &operator=(Token &&) noexcept;

  auto getType() const -> TokenType { return type; }
  const std::string &getLexeme() const { return lexeme; }
  const std::any &getLiteral() const { return literal; }
  auto getLine() const -> int { return line; }

  std::string toString() const;
  std::string literalToString() const;

private:
  TokenType type;
  std::string lexeme;
  std::any literal;
  int line;
};
}; // namespace Lox