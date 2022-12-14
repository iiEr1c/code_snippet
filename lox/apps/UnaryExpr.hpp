#pragma once
#include "Expr.hpp"
#include "ExprVisitor.hpp"
#include "Token.hpp"
#include <memory>

namespace Lox {
struct UnaryExpr : public Expr {
  explicit UnaryExpr(Token op, std::unique_ptr<Expr> right);
  std::any accept(ExprVisitor<std::any> &visitor) const override;

  const Token &getOp() const { return op; }
  const Expr &getRightExpr() const { return *right; }

private:
  Token op;
  std::unique_ptr<Expr> right;
};
}; // namespace Lox