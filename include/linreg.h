#ifndef __LINREG_H__
#define __LINREG_H__

#include <stdlib.h>
#include <math.h>
#include <stddef.h>

#include "config.h"

int linreg(int n, const DATA_TYPE x[], const TIME_TYPE y[], SLOPE_TYPE* m, SLOPE_TYPE* b, SLOPE_TYPE* r);
SLOPE_TYPE slope(const TIME_TYPE *x, const DATA_TYPE* y, int len);

int linreg(int n, const REAL x[], const REAL y[], REAL *m, REAL *b, REAL *r);

#endif /* __LINREG_H__ */
