/* author: Jeremy Crowley */
/* file: input.c */


#include "input.h"

char slash = '/';

char* getNumerator(char *transfer)
{
	int slashIndex;
	char *slashPointer;
	char *numerator;

	slashPointer = strstr(transfer, &slash);
	slashIndex = slashPointer - transfer;
	numerator = malloc(sizeof(char)*slashIndex);

	strncpy(numerator, transfer, slashIndex);
	return numerator;
}

char* getDenominator(char *transfer)
{
	char *slashPointer;
	char *den;
	char *denominator;

	slashPointer = strchr(transfer, slash);
	den = slashPointer + 1;
	denominator = malloc(sizeof(den));

	strcpy(denominator, den);
	return denominator;
}

int getNumRoots(char* polynomial)
{
	int rootCount = 0;
	int i = 0;

	// count the number of roots
	while(polynomial[i] != '\0')
	{
		if(polynomial[i] == 's')
		{
			rootCount++;
		}
		i++;
	}

	return rootCount;
}

complex_t* getRoots(char* polynomial, int rootCount)
{
	complex_t *roots;
	roots = NULL;

	int i = 0, j = 0, k = 0;

	roots = malloc(sizeof(complex_t) * rootCount);

	// still needs to compensate for a roots at 0 and double digit roots
	for(i = 0; i < rootCount;)
	{
		if(polynomial[j] == 's')
		{
			k = j;
			while(polynomial[k] != ')' && polynomial[k] != '/')
			{
				if(isdigit(polynomial[k]))
				{
					// need some for loop concatenating all the char digits
					// to change to integer to get multi digit roots
					roots[i].real = -(float)atoi(&polynomial[k]);

					printf("%f\n", roots[i].real);
				}
				k++;
			}
			i++;
		}
		j++;
	}

	return roots;
}
