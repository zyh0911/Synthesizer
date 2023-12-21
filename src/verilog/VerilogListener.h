
// Generated from C:/Users/admin/Desktop/USTGZ/LOgic/ass1/src/Verilog.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "VerilogParser.h"


namespace verilog {

/**
 * This interface defines an abstract listener for a parse tree produced by VerilogParser.
 */
class  VerilogListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStartRule(VerilogParser::StartRuleContext *ctx) = 0;
  virtual void exitStartRule(VerilogParser::StartRuleContext *ctx) = 0;

  virtual void enterAndExpr(VerilogParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(VerilogParser::AndExprContext *ctx) = 0;

  virtual void enterIdExpr(VerilogParser::IdExprContext *ctx) = 0;
  virtual void exitIdExpr(VerilogParser::IdExprContext *ctx) = 0;

  virtual void enterMulDivModExpr(VerilogParser::MulDivModExprContext *ctx) = 0;
  virtual void exitMulDivModExpr(VerilogParser::MulDivModExprContext *ctx) = 0;

  virtual void enterConstantExpr(VerilogParser::ConstantExprContext *ctx) = 0;
  virtual void exitConstantExpr(VerilogParser::ConstantExprContext *ctx) = 0;

  virtual void enterNotExpr(VerilogParser::NotExprContext *ctx) = 0;
  virtual void exitNotExpr(VerilogParser::NotExprContext *ctx) = 0;

  virtual void enterRelationalExpr(VerilogParser::RelationalExprContext *ctx) = 0;
  virtual void exitRelationalExpr(VerilogParser::RelationalExprContext *ctx) = 0;

  virtual void enterParenExpr(VerilogParser::ParenExprContext *ctx) = 0;
  virtual void exitParenExpr(VerilogParser::ParenExprContext *ctx) = 0;

  virtual void enterAddSubExpr(VerilogParser::AddSubExprContext *ctx) = 0;
  virtual void exitAddSubExpr(VerilogParser::AddSubExprContext *ctx) = 0;

  virtual void enterOrExpr(VerilogParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(VerilogParser::OrExprContext *ctx) = 0;

  virtual void enterConstant(VerilogParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(VerilogParser::ConstantContext *ctx) = 0;


};

}  // namespace verilog
