# Verilog Parser and synthesizer
MICS6000H project 2

1. This project:
```
    mkdir build
    cd build 
    cmake ..
    make
    cd src
    ./src > case6.aag
```
2. AIGER:

https://github.com/arminbiere/aiger

```
    ./configure.sh 
    make
     ./aigtoaig case6.aag newcase6.aig
```

3. ABC:

https://github.com/berkeley-abc/abc

```
    .\abc
    read_aiger newcase6.aig
    b; rs; rs -K 6; b; rsz; rsz -K 6; b; rsz -K 5; b
    read_library cells.lib
    write_verilog result6.v
```
All the materials are provided, including the original input, generated ASCII format AIG files,
binary AIG files, cells.lib, and the final verilog netlist.

By using ABC's optimization techniques to reduce costs, and the AIG before and after optimization has been validated. All test cases have been tested and the results are correct.
