# extract some math func from glibc with c++
NOTE: intel compiler will get the wrong result

### test on intel 10980XE, gcc 7.5, glibc 2.27
```
./fma_bench.exe 
sincos std = 1166.43 ms, lat = 23.3287 ns
sincos myl = 546.622 ms, lat = 10.9324 ns
PASS
exp std = 939.45 ms, lat = 9.3945 ns
exp myl = 281.452 ms, lat = 2.81452 ns
PASS
cexp std = 750.521 ms, lat = 37.5261 ns
cexp myl = 345.674 ms, lat = 17.2837 ns
PASS

./noa_bench.exe 
sincos std = 1143.35 ms, lat = 22.8669 ns
sincos myl = 743.276 ms, lat = 14.8655 ns
PASS
exp std = 939.144 ms, lat = 9.39144 ns
exp myl = 407.83 ms, lat = 4.0783 ns
PASS
cexp std = 725.646 ms, lat = 36.2823 ns
cexp myl = 438.499 ms, lat = 21.9249 ns
PASS

./sse_bench.exe 
sincos std = 1145.62 ms, lat = 22.9125 ns
sincos myl = 741.004 ms, lat = 14.8201 ns
PASS
exp std = 936.729 ms, lat = 9.36729 ns
exp myl = 407.21 ms, lat = 4.0721 ns
PASS
cexp std = 724.537 ms, lat = 36.2268 ns
cexp myl = 435.684 ms, lat = 21.7842 ns
PASS
```
### test on intel 10980XE, gcc 7.5, glibc 2.36
```
./fma_bench.exe 
sincos std = 794.988 ms, lat = 15.8998 ns
sincos myl = 552.658 ms, lat = 11.0532 ns
PASS
exp std = 681.724 ms, lat = 6.81724 ns
exp myl = 282.468 ms, lat = 2.82468 ns
PASS
cexp std = 481.956 ms, lat = 24.0978 ns
cexp myl = 338.73 ms, lat = 16.9365 ns
PASS

./noa_bench.exe 
sincos std = 813.393 ms, lat = 16.2679 ns
sincos myl = 746.036 ms, lat = 14.9207 ns
PASS
exp std = 687.124 ms, lat = 6.87124 ns
exp myl = 408.509 ms, lat = 4.08509 ns
PASS
cexp std = 483.642 ms, lat = 24.1821 ns
cexp myl = 436.061 ms, lat = 21.8031 ns
PASS

sse_bench.exe 
sincos std = 815.12 ms, lat = 16.3024 ns
sincos myl = 749.115 ms, lat = 14.9823 ns
PASS
exp std = 685.547 ms, lat = 6.85547 ns
exp myl = 407.369 ms, lat = 4.07369 ns
PASS
cexp std = 487.592 ms, lat = 24.3796 ns
cexp myl = 435.563 ms, lat = 21.7782 ns
PASS
```
### test on intel 10980XE, intel compiler 2021
```
./noa_bench.exe 
sincos std = 458.454 ms, lat = 9.16908 ns
sincos myl = 466.991 ms, lat = 9.33982 ns
PASS
exp std = 748.914 ms, lat = 7.48914 ns
exp myl = 744.207 ms, lat = 7.44207 ns
PASS
cexp std = 358.482 ms, lat = 17.9241 ns
cexp myl = 353.821 ms, lat = 17.6911 ns
PASS
```
### test on an ARM device, gcc 7.5
```
./noa_bench.exe
sincos std = 2850.76 ms, lat = 57.0152 ns
sincos myl = 1732.82 ms, lat = 34.6563 ns
PASS
exp std = 2126.26 ms, lat = 21.2626 ns
exp myl = 958.889 ms, lat = 9.58889 ns
PASS
cexp std = 1767.54 ms, lat = 88.3769 ns
cexp myl = 1022.17 ms, lat = 51.1087 ns
PASS
```
