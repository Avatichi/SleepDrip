#ifndef __LINREG_H__
#define __LINREG_H__

#include <stdlib.h>
#include <math.h>
#include <stddef.h>

#include "config.h"

int linreg(int n, const TIME_TYPE x[], const DATA_TYPE y[], SLOPE_TYPE* m, SLOPE_TYPE* b, SLOPE_TYPE* r);

#endif /* __LINREG_H__ */
