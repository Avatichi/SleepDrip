#ifndef __LINREG_H__
#define __LINREG_H__

#include <stdlib.h>
#include <math.h>
#include <stddef.h>


#define REAL double

int linreg(int n, const REAL x[], const REAL y[], REAL *m, REAL *b, REAL *r);

#endif /* __LINREG_H__ */
