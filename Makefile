CXX?=g++
CXXFLAGS+=-O3 -g -std=c++11 -DUSE_MY_LIBM
EXXFLAGS+=-O0 -g -std=c++11 -DUSE_MY_LIBM
SSEFLAGS?=-msse4.2
AVXFLAGS?=-mavx
FMAFLAGS?=-mfma -mavx2

all:noa_bench sse_bench avx_bench fma_bench

#no_arch
noa_bench:
	$(CXX) $(CXXFLAGS) -c branred.cpp sincos.cpp exp.cpp
	$(CXX) $(EXXFLAGS) -c bench.cpp
	$(CXX) bench.o branred.o sincos.o exp.o -o $@.exe

sse_bench:
	$(CXX) $(CXXFLAGS) $(SSEFLAGS) -c branred.cpp sincos.cpp exp.cpp
	$(CXX) $(EXXFLAGS) -c bench.cpp
	$(CXX) bench.o branred.o sincos.o exp.o -o $@.exe

avx_bench:
	$(CXX) $(CXXFLAGS) $(AVXFLAGS) -c branred.cpp sincos.cpp exp.cpp
	$(CXX) $(EXXFLAGS) -c bench.cpp
	$(CXX) bench.o branred.o sincos.o exp.o -o $@.exe

fma_bench:
	$(CXX) $(CXXFLAGS) $(FMAFLAGS) -c branred.cpp sincos.cpp exp.cpp
	$(CXX) $(EXXFLAGS) -c bench.cpp
	$(CXX) bench.o branred.o sincos.o exp.o -o $@.exe

clean:
	rm *.exe
