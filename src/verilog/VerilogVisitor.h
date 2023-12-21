
// Generated from C:/Users/admin/Desktop/USTGZ/LOgic/ass1/src/Verilog.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "VerilogParser.h"


namespace verilog {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by VerilogParser.
 */
class  VerilogVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by VerilogParser.
   */
    virtual std::any visitStartRule(VerilogParser::StartRuleContext *context) = 0;

    virtual std::any visitAndExpr(VerilogParser::AndExprContext *context) = 0;

    virtual std::any visitIdExpr(VerilogParser::IdExprContext *context) = 0;

    virtual std::any visitMulDivModExpr(VerilogParser::MulDivModExprContext *context) = 0;

    virtual std::any visitConstantExpr(VerilogParser::ConstantExprContext *context) = 0;

    virtual std::any visitNotExpr(VerilogParser::NotExprContext *context) = 0;

    virtual std::any visitRelationalExpr(VerilogParser::RelationalExprContext *context) = 0;

    virtual std::any visitParenExpr(VerilogParser::ParenExprContext *context) = 0;

    virtual std::any visitAddSubExpr(VerilogParser::AddSubExprContext *context) = 0;

    virtual std::any visitOrExpr(VerilogParser::OrExprContext *context) = 0;

    virtual std::any visitConstant(VerilogParser::ConstantContext *context) = 0;


};

}  // namespace verilog
