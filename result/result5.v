// Benchmark "./case/newcase5" written by ABC on Fri Dec 22 21:28:44 2023

module \./case/newcase5  ( 
    pi0, pi1,
    po0  );
  input  pi0, pi1;
  output po0;
  NOR2  g0(.a(pi1), .b(pi0), .O(po0));
endmodule


