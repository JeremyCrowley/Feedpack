/* author: Jeremy Crowley */
/* file: nyquist.h */


#ifndef NYQUIST_H
#define NYQUIST_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/* data type for a complex number */
struct ComplexNumber
{
	int multiplicity;
	float real;
	float imag;
};

typedef struct ComplexNumber complex_t;


float sAtZero(complex_t *zeros, int numZeros, complex_t *poles, int numPoles);

float sToInfty(complex_t *zeros, int numZeros, complex_t *poles, int numPoles);

#endif /* NYQUIST_H */