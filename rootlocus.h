/* author: Jeremy Crowley */
/* file: rootlocus.h */


#ifndef ROOTLOCUS_H
#define ROOTLOCUS_H

#include <stdlib.h>

/* data type for a complex number */
struct ComplexNumber
{
	float real;
	float im;
};

typedef struct ComplexNumber complex_t;


/* returns the sum of the roots from an array of complex numbers (zeros or poles) */
float SumRoots(complex_t *roots, int numRoots);

/* returns the centroid of the rootlocus given the zeros and poles */
float FindCentroid(complex_t *zeros, int numZeros, complex_t *poles, int numPoles);

/* writes angle of asymptotes to array */
void FindAsymptotes(float centroid, int numZeros, int numPoles, float angleArray[numPoles-numZeros]);


#endif
