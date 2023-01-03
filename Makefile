CXX?=g++
CXXFLAGS+=-O3 -g -std=c++11 -DUSE_MY_LIBM
SSEFLAGS?=-msse4.2
AVXFLAGS?=-mavx
FMAFLAGS?=-mfma -mavx2

all:noa_bench sse_bench avx_bench fma_bench

#no_arch
noa_bench:
	$(CXX) $(CXXFLAGS) bench.cpp branred.cpp sincos.cpp exp.cpp -o $@.exe

sse_bench:
	$(CXX) $(CXXFLAGS) $(SSEFLAGS) bench.cpp branred.cpp sincos.cpp exp.cpp -o $@.exe

avx_bench:
	$(CXX) $(CXXFLAGS) $(AVXFLAGS) bench.cpp branred.cpp sincos.cpp exp.cpp -o $@.exe 

fma_bench:
	$(CXX) $(CXXFLAGS) $(FMAFLAGS) bench.cpp branred.cpp sincos.cpp exp.cpp -o $@.exe 

clean:
	rm *.exe
