/* author: Jeremy Crowley */
/* file: nyquist.h */


#ifndef NYQUIST_H
#define NYQUIST_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "datatypes.h"

float sAtZero(polynomial_t numerator, polynomial_t denominator);

float sToInfty(polynomial_t numerator, polynomial_t denominator);

#endif /* NYQUIST_H */