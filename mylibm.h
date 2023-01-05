#ifndef MYLIBM_H
#define MYLIBM_H

#include <complex>

#if !defined(__INTEL_COMPILER) && defined(USE_MY_LIBM)

namespace my_libm {

double
__exp (double x);

double
__cos (double x);

double
__sin (double x);

void
__sincos (double x, double *sinx, double *cosx);

std::complex<double>
__cexp (const std::complex<double> &x);

};

#else

#include <cmath>

namespace my_libm {

inline double
__exp (double x) { return std::exp(x); };

inline double
__cos (double x) { return std::cos(x); };

inline double
__sin (double x) { return std::sin(x); };

inline void
__sincos (double x, double *sinx, double *cosx) { sincos(x, sinx, cosx); };

inline std::complex<double>
__cexp (const std::complex<double> &x) { return std::exp(x); }

};

#endif

#endif
