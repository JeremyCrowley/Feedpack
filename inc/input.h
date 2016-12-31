/* author: Jeremy Crowley */
/* file: input.h */


#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "datatypes.h"


char* getNumerator(char *transfer);

char* getDenominator(char *transfer);

int getNumRoots(char* polynomial);

int getNumUniqueRoots(complex_t *roots, int numRoots);

complex_t* getRoots(char* polynomial, int rootCount);

int isDuplicate(complex_t *roots, int numRoots, complex_t root);

void printPolynomial(complex_t *roots, int numRoots);








#endif /* INPUT_H */
