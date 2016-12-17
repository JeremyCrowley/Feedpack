/* author: Jeremy Crowley */
/* file: nyquist.h */


#ifndef NYQUIST_H
#define NYQUIST_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "datatypes.h"

float sAtZero(complex_t *zeros, int numZeros, complex_t *poles, int numPoles);

float sToInfty(complex_t *zeros, int numZeros, complex_t *poles, int numPoles);

#endif /* NYQUIST_H */