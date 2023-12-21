
// Generated from C:/Users/admin/Desktop/USTGZ/LOgic/ass1/src/Verilog.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "VerilogListener.h"


namespace verilog {

/**
 * This class provides an empty implementation of VerilogListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  VerilogBaseListener : public VerilogListener {
public:

  virtual void enterStartRule(VerilogParser::StartRuleContext * /*ctx*/) override { }
  virtual void exitStartRule(VerilogParser::StartRuleContext * /*ctx*/) override { }

  virtual void enterAndExpr(VerilogParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(VerilogParser::AndExprContext * /*ctx*/) override { }

  virtual void enterIdExpr(VerilogParser::IdExprContext * /*ctx*/) override { }
  virtual void exitIdExpr(VerilogParser::IdExprContext * /*ctx*/) override { }

  virtual void enterMulDivModExpr(VerilogParser::MulDivModExprContext * /*ctx*/) override { }
  virtual void exitMulDivModExpr(VerilogParser::MulDivModExprContext * /*ctx*/) override { }

  virtual void enterConstantExpr(VerilogParser::ConstantExprContext * /*ctx*/) override { }
  virtual void exitConstantExpr(VerilogParser::ConstantExprContext * /*ctx*/) override { }

  virtual void enterNotExpr(VerilogParser::NotExprContext * /*ctx*/) override { }
  virtual void exitNotExpr(VerilogParser::NotExprContext * /*ctx*/) override { }

  virtual void enterRelationalExpr(VerilogParser::RelationalExprContext * /*ctx*/) override { }
  virtual void exitRelationalExpr(VerilogParser::RelationalExprContext * /*ctx*/) override { }

  virtual void enterParenExpr(VerilogParser::ParenExprContext * /*ctx*/) override { }
  virtual void exitParenExpr(VerilogParser::ParenExprContext * /*ctx*/) override { }

  virtual void enterAddSubExpr(VerilogParser::AddSubExprContext * /*ctx*/) override { }
  virtual void exitAddSubExpr(VerilogParser::AddSubExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(VerilogParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(VerilogParser::OrExprContext * /*ctx*/) override { }

  virtual void enterConstant(VerilogParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(VerilogParser::ConstantContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace verilog
