# Verilog Parser and synthesizer
MICS6000H project 2

使用c++写一个简单的parser，能够为下列verilog语法的语句建立AST：
~(a&b)
!(c || d)
a&b&c | (a&b&!d) | (a&b&~e)