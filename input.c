/* author: Jeremy Crowley */
/* file: input.c */


#include "input.h"

char slash = '/';

void getNumerator(char *transfer, char *numerator)
{
	int slashIndex;
	char *slashPointer;

	slashPointer = strstr(transfer, &slash);
	slashIndex = slashPointer - transfer;
	numerator = malloc(sizeof(char)*slashIndex);
	strncpy(numerator, transfer, slashIndex);
}

void getDenominator(char *transfer, char *denominator)
{
	char *slashPointer;
	char *den;

	slashPointer = strchr(transfer, slash);
	den = slashPointer + 1;
	denominator = malloc(sizeof(den));
	strcpy(denominator, den);
}