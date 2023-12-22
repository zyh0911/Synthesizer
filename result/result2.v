// Benchmark "./case/newcase2" written by ABC on Fri Dec 22 21:26:21 2023

module \./case/newcase2  ( 
    pi0, pi1,
    po0  );
  input  pi0, pi1;
  output po0;
  wire new_n4, new_n5;
  INV1  g0(.a(pi0), .O(new_n4));
  NAND2 g1(.a(pi1), .b(pi0), .O(new_n5));
  NAND2 g2(.a(new_n5), .b(new_n4), .O(po0));
endmodule


