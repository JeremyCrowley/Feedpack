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

int getNumUniqueRoots(complex_t *roots, int numRoots)
{
	int uniqueRootCount = 0;
	int i, j;

	bool duplicateFlag = false;

	for(i = 0; i < numRoots; i++)
	{

		// iterate backwards to check for duplicate
		for(j = i-1; j >= 0; j--)
		{
			if(roots[i].real == roots[j].real)
			{
				duplicateFlag = true;	
			}
			
		}

		if(duplicateFlag == false)
		{
			uniqueRootCount++;
		}

		duplicateFlag = false;
	}
	return uniqueRootCount;
}

complex_t* getRoots(char* polynomial, int rootCount)
{
	int i = 0, j = 0, k = 0, l = 0;

	complex_t *roots;

	char rootHold[10];

	roots = malloc(sizeof(complex_t) * rootCount);

	// assure that we only account for the correct number of roots
	for(i = 0; i < rootCount;)
	{
		// found a root
		if(polynomial[j] == 's')
		{
			k = j;

			// zero root
			if(polynomial[j+1] == '(' || polynomial[j+1] == '/' || polynomial[j+1] == '\0')
			{
				roots[i].real = 0;
			}
			else 
			{
				// iterate until the next root 
				while(polynomial[k] != ')' && polynomial[k] != '/')
				{
					if(isdigit(polynomial[k]))
					{
						rootHold[l] = polynomial[k];	
						l++;				

						//printf("%f\n", roots[i].real);
					}
					k++;
				}
				roots[i].real = -(float)atoi(rootHold);
			}	
			// temporary
			roots[i].imag = 0;
			// temporarym
			roots[i].multiplicity = 1;
			i++;
		}
		l = 0;
		j++;
	}

	return roots;
}


int isDuplicate(complex_t *roots, int curRoot, complex_t root)
{
	int i, j, k;

	i = 0;
	j = 0;

	while(j < curRoot)
	{
		for(k = 0; k < roots[i].multiplicity; k++)
		{
			if((root.real == roots[i].real) && (root.imag == roots[i].imag))
			{
				return i;
			}
			j++;
		}
		i++;
	}

	return -1;
	
}



void printPolynomial(complex_t *roots, int numRoots)
{
	int i, j, k;

	i = 0;
	j = 0;

	while(j < numRoots)
	{
		for(k = 0; k < roots[i].multiplicity; k++)
		{
			printf("(s+%f)", -roots[i].real);
			j++;
		}
		i++;
	}
	printf("\n");
}





