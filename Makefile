CXX?=g++
CXXFLAGS+=-O3 -std=c++11 -DUSE_MY_LIBM
EXXFLAGS+=-O1 -std=c++11 -DUSE_MY_LIBM
SSEFLAGS?=-msse4.2
AVXFLAGS?=-mavx
FMAFLAGS?=-mfma -mavx2

all:noa_bench sse_bench avx_bench fma_bench

MATH_SRC=branred.cpp sincos.cpp exp.cpp cexp.cpp
MATH_OBJ=$(MATH_SRC:.cpp=.o)

#no_arch
noa_bench:
	$(CXX) $(CXXFLAGS) -c $(MATH_SRC)
	$(CXX) $(EXXFLAGS) -c bench.cpp
	$(CXX) bench.o $(MATH_OBJ) -o $@.exe

sse_bench:
	$(CXX) $(CXXFLAGS) $(SSEFLAGS) -c $(MATH_SRC)
	$(CXX) $(EXXFLAGS) -c bench.cpp
	$(CXX) bench.o $(MATH_OBJ) -o $@.exe

avx_bench:
	$(CXX) $(CXXFLAGS) $(AVXFLAGS) -c $(MATH_SRC)
	$(CXX) $(EXXFLAGS) -c bench.cpp
	$(CXX) bench.o $(MATH_OBJ) -o $@.exe

fma_bench:
	$(CXX) $(CXXFLAGS) $(FMAFLAGS) -c $(MATH_SRC)
	$(CXX) $(EXXFLAGS) -c bench.cpp
	$(CXX) bench.o $(MATH_OBJ) -o $@.exe

clean:
	rm *.o
	rm *.exe
