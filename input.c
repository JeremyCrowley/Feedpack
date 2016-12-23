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

char* getZeros(char* numerator)
{
	char *zeros;
	zeros = NULL;

	int i, j;
	int zeroCount = 0;
	i = 0;
	j = 0;


	while(numerator[i] != '\0')
	{
		printf("num: %c: ", numerator[i]);
		if(numerator[i] == 's')
		{
			zeroCount++;
		}
		i++;
	}

	zeros = malloc(sizeof(char)*zeroCount);

	for(i = 0; i < zeroCount; i++)
	{
		if(numerator[i] == 's')
		{
			while(numerator[j] != ')' || numerator[j] != '/')
			{
				if(isdigit(numerator[i]))
				{
					zeros[i] = - numerator[i];
				}

				j++;
			}
		}
	}

	return zeros;
}

char* getPoles(char* denominator)
{
	char *poles;
	poles = NULL;



	return poles;
}