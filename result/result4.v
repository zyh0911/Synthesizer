// Benchmark "./case/newcase4" written by ABC on Fri Dec 22 21:28:16 2023

module \./case/newcase4  ( 
    pi0, pi1,
    po0  );
  input  pi0, pi1;
  output po0;
  wire new_n4;
  NAND2 g0(.a(pi1), .b(pi0), .O(new_n4));
  INV1  g1(.a(new_n4), .O(po0));
endmodule


