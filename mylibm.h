#ifndef MYLIBM_H
#define MYLIBM_H

#if defined(__x86_64__) || defined(__i386__)

namespace my_libm {

double
__exp (double x);

double
__cos (double x);

double
__sin (double x);

void
__sincos (double x, double *sinx, double *cosx);

};

#else

#include <cmath>

namespace my_libm {

double
__exp (double x) { return exp(x); };

double
__cos (double x) { return cos(x); };

double
__sin (double x) { return sin(x); };

void
__sincos (double x, double *sinx, double *cosx) { sincos(x, sinx, cosx); };

};

#endif

#endif
