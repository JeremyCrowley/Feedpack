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

int getNumRoots(char* polynomial);

complex_t* getRoots(char* polynomial, int rootCount);








#endif /* INPUT_H */
