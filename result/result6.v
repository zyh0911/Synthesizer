// Benchmark "./case/newcase6" written by ABC on Fri Dec 22 21:29:37 2023

module \./case/newcase6  ( 
    pi0, pi1, pi2, pi3, pi4,
    po0  );
  input  pi0, pi1, pi2, pi3, pi4;
  output po0;
  wire new_n7, new_n8, new_n9, new_n10, new_n11, new_n12;
  INV1  g0(.a(pi0), .O(new_n7));
  NAND2 g1(.a(pi2), .b(pi1), .O(new_n8));
  INV1  g2(.a(new_n8), .O(new_n9));
  NAND2 g3(.a(new_n9), .b(new_n7), .O(new_n10));
  INV1  g4(.a(pi3), .O(new_n11));
  NAND2 g5(.a(new_n9), .b(new_n11), .O(new_n12));
  NAND2 g6(.a(new_n12), .b(new_n10), .O(po0));
endmodule


