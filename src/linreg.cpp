#include "../include/linreg.h"

#include <stdio.h>


SLOPE_TYPE sqr(SLOPE_TYPE x) {
    return x * x;
}

int linreg(int n, const DATA_TYPE x[], const TIME_TYPE y[], SLOPE_TYPE* m, SLOPE_TYPE* b, SLOPE_TYPE* r)
{
	SLOPE_TYPE   sumx = 0.0;                      /* sum of x     */
	SLOPE_TYPE   sumx2 = 0.0;                     /* sum of x**2  */
	SLOPE_TYPE   sumxy = 0.0;                     /* sum of x * y */
	SLOPE_TYPE   sumy = 0.0;                      /* sum of y     */
	SLOPE_TYPE   sumy2 = 0.0;                     /* sum of y**2  */

	for (int i = 0; i < n; i++) { 
		sumx  += (SLOPE_TYPE)x[i];
		sumx2 += sqr((SLOPE_TYPE)x[i]);
		sumxy += x[i] * (SLOPE_TYPE)y[i];
		sumy  += (SLOPE_TYPE)y[i];
		sumy2 += sqr((SLOPE_TYPE)y[i]);
	} 

	SLOPE_TYPE denom = (n * sumx2 - sqr(sumx));
	if (denom == 0) {
		// singular matrix. can't solve the problem.
		*m = 0;
		*b = 0;
		if (r) *r = 0;
			return 1;
	}

	*m = (n * sumxy  -  sumx * sumy) / denom;
	*b = (sumy * sumx2  -  sumx * sumxy) / denom;
	if (r != NULL) {
		*r = (sumxy - sumx * sumy / n) /    /* compute correlation coeff */
				sqrt((sumx2 - sqr(sumx) / n) * (sumy2 - sqr(sumy)/n));
	}

	// Serial.print("intercept: ");
	// Serial.println(*b);

	// Serial.print("slope: ");
	// Serial.println(*m);
	
	// Serial.print("CC: ");
	// Serial.println(*m / 80 * -1);

	// Serial.print("corralation coefficient: ");
	// Serial.println(*r);

	return 0;
}

SLOPE_TYPE slope(const TIME_TYPE *x, const DATA_TYPE* y, int len)
{
	int i = 0;
	TIME_TYPE sumx = 0;
	DATA_TYPE sumy = 0;
	SLOPE_TYPE avgX;
    SLOPE_TYPE avgY;
	SLOPE_TYPE numerator = 0.0;
    SLOPE_TYPE denominator = 0.0;
	if (len == 0){
		return 0;
	}
	for (i = 0; i < len; i++) {
		sumx += x[i];
		sumy += y[i];
	}

    avgX = sumx / len;
    avgY = sumy / len;

    for(size_t i=0; i < len; ++i){
        numerator += (x[i] - avgX) * (y[i] - avgY);
        denominator += (x[i] - avgX) * (x[i] - avgX);
    }

    if(denominator == 0.0){
        return 0;
    }

    return numerator / denominator;
}