
// Generated from C:/Users/admin/Desktop/USTGZ/LOgic/ass1/src/Verilog.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "VerilogVisitor.h"


namespace verilog {

/**
 * This class provides an empty implementation of VerilogVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  VerilogBaseVisitor : public VerilogVisitor {
public:

  virtual std::any visitStartRule(VerilogParser::StartRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(VerilogParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdExpr(VerilogParser::IdExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulDivModExpr(VerilogParser::MulDivModExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantExpr(VerilogParser::ConstantExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpr(VerilogParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationalExpr(VerilogParser::RelationalExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenExpr(VerilogParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSubExpr(VerilogParser::AddSubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(VerilogParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(VerilogParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace verilog
