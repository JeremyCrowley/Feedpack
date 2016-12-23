/* author: Jeremy Crowley */
/* file: input.h */


#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "datatypes.h"


char* getNumerator(char *transfer);

char* getDenominator(char *transfer);

char* getZeros(char* numerator);

char* getPoles(char* denominator);







#endif /* INPUT_H */
