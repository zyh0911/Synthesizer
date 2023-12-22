// Benchmark "./case/newcase1" written by ABC on Fri Dec 22 21:23:09 2023

module \./case/newcase1  ( 
    pi0, pi1,
    po0  );
  input  pi0, pi1;
  output po0;
  wire new_n4;
  INV1  g0(.a(pi0), .O(new_n4));
  NOR2  g1(.a(pi1), .b(new_n4), .O(po0));
endmodule


