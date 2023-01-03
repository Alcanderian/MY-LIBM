#include <iostream>
#include <chrono>
#include <cmath>
#include "mylibm.h"

template <typename T>
bool check_array_error(T* input, T* ref, uint64_t len, T eps)
{
    for (uint64_t i = 0; i < len; ++i) {
        double err = double(input[i] - ref[i]);
        if (std::abs(err / ref[i]) > eps && std::abs(err) > eps) {
            std::cerr << "error[" << i << "]=" << input[i] << " ref:" << ref[i];
            return false;
        }
    }
    std::cerr << "pass";
    return true;
}

void bench_sincos(int argc, char**argv) {
    int len = 5000;
    double da[len];
    double ds1[len*2];
    double ds2[len*2];

    for (int i = 0; i < len; ++i) {
        da[i] = i * 0.1;
    }
    
    for (int i = 0; i < len; ++i) {
        sincos(da[i], ds1 + i * 2 + 0, ds1 + i * 2 + 1);
        my_libm::__sincos(da[i], ds2 + i * 2 + 0, ds2 + i * 2 + 1);
    }

    int warm = 100;
    int loop = 10000;
    if (argc > 1) {
        warm = atoi(argv[1]);
    }
    if (argc > 2) {
        loop = atoi(argv[2]);
    }

    auto ker1 = [&](int iter) {
        for (int ii = 0; ii < iter; ++ii)
            for (int i = 0; i < len; ++i) {
                sincos(da[i], ds1 + i * 2 + 0, ds1 + i * 2 + 1);
            }
    };

    auto ker2 = [&](int iter) {
        for (int ii = 0; ii < iter; ++ii)
            for (int i = 0; i < len; ++i) {
                my_libm::__sincos(da[i], ds2 + i * 2 + 0, ds2 + i * 2 + 1);
            }
    };

    ker1(warm);
    ker2(warm);

    {
        ker1(warm);
        auto t0 = std::chrono::high_resolution_clock::now();
        ker1(loop);
        auto t1 = std::chrono::high_resolution_clock::now();
        auto ms = (t1 - t0).count() / 1e6;
        std::cerr << "sincos std = " << ms << " ms" << std::endl;
    }

    {
        ker2(warm);
        auto t0 = std::chrono::high_resolution_clock::now();
        ker2(loop);
        auto t1 = std::chrono::high_resolution_clock::now();
        auto ms = (t1 - t0).count() / 1e6;
        std::cerr << "sincos myl = " << ms << " ms" << std::endl;
    }

    check_array_error(ds2, ds1, len*2, 1e-15);
    std::cerr << std::endl;
}

void bench_exp(int argc, char**argv) {
    int len = 10000;
    double da[len];
    double ds1[len];
    double ds2[len];

    for (int i = 0; i < len; ++i) {
        da[i] = i * 0.1;
    }
    
    for (int i = 0; i < len; ++i) {
        ds1[i] = exp(da[i]);
        ds2[i] = my_libm::__exp(da[i]);
    }

    int warm = 100;
    int loop = 10000;
    if (argc > 1) {
        warm = atoi(argv[1]);
    }
    if (argc > 2) {
        loop = atoi(argv[2]);
    }

    auto ker1 = [&](int iter) {
        for (int ii = 0; ii < iter; ++ii)
            for (int i = 0; i < len; ++i) {
                ds1[i] = exp(da[i]);
            }
    };

    auto ker2 = [&](int iter) {
        for (int ii = 0; ii < iter; ++ii)
            for (int i = 0; i < len; ++i) {
                ds2[i] = my_libm::__exp(da[i]);
            }
    };

    ker1(warm);
    ker2(warm);

    {
        ker1(warm);
        auto t0 = std::chrono::high_resolution_clock::now();
        ker1(loop);
        auto t1 = std::chrono::high_resolution_clock::now();
        auto ms = (t1 - t0).count() / 1e6;
        std::cerr << "exp std = " << ms << " ms" << std::endl;
    }

    {
        ker2(warm);
        auto t0 = std::chrono::high_resolution_clock::now();
        ker2(loop);
        auto t1 = std::chrono::high_resolution_clock::now();
        auto ms = (t1 - t0).count() / 1e6;
        std::cerr << "exp myl = " << ms << " ms" << std::endl;
    }

    check_array_error(ds2, ds1, len, 1e-15);
    std::cerr << std::endl;
}

int main(int argc, char**argv) {
    bench_sincos(argc, argv);
    bench_exp(argc, argv);
    return 0;
}
