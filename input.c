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

complex_t* getRoots(char* polynomial)
{
	complex_t *roots;
	roots = NULL;

	int i, j, k;
	int rootCount = 0;
	i = 0;
	j = 0;
	k = 0;

	// count the number of roots
	while(polynomial[i] != '\0')
	{
		if(polynomial[i] == 's')
		{
			rootCount++;
		}
		i++;
	}

	printf("complex size: %lu\n", sizeof(complex_t));
	printf("root count: %d\n", rootCount);
	printf("size count: %lu\n", sizeof(complex_t)*rootCount);

	// isn't allocating enough memory?? always is 8 bytes
	roots = calloc(rootCount, sizeof(complex_t));

	printf("complex size: %lu\n", sizeof(roots));

	// still needs to compensate for a roots at 0
	for(i = 0; i < rootCount;)
	{
		if(polynomial[j] == 's')
		{
			while(polynomial[k] != ')' && polynomial[k] != '/')
			{
				if(isdigit(polynomial[k]))
				{
					roots[i].real = - atoi(&polynomial[k]);
				}
				k++;
			}
			i++;
		}
		j++;
	}

	return roots;
}
