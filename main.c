/* author: Jeremy Crowley */
/* file: main.c */


#include <stdio.h>
#include <string.h>
#include "rootlocus.h"
#include "nyquist.h"
#include "input.h"

int main(void)
{
	int i, j;
	
	// need too change to allocate dynamically
	char transferFunc[100], tf[100];
	char *rawDenom, *rawNum;

	complex_t *unprocessedZeros, *unprocessedPoles;
	polynomial_t numerator, denominator;

	int uniquePoles = 0, uniqueZeros = 0;

	int zIndex = 0, pIndex = 0;
	int duplicateIndex;
	

	printf("Hello, welcome to Jeremy's feedback control package\n");
	printf("Please enter a transfer function: \n");
	scanf("%s", tf);
	printf("You entered: %s\n", tf);

	strcpy(transferFunc, tf);

	rawNum = getNumerator(tf);
	numerator.numRoots = getNumRoots(rawNum);

	unprocessedZeros = getRoots(rawNum, numerator.numRoots);

	uniqueZeros = getNumUniqueRoots(unprocessedZeros, numerator.numRoots);

	numerator.size = uniqueZeros;
	numerator.roots = malloc(sizeof(complex_t) * uniqueZeros);

	// process zeros
	for(i = 0; i < numerator.numRoots; i++)
	{
		duplicateIndex = isDuplicate(unprocessedZeros, i, unprocessedZeros[i]);

		if(duplicateIndex != (-1))
		{
			numerator.roots[duplicateIndex].multiplicity++;
		}
		else
		{
			numerator.roots[zIndex] = unprocessedZeros[i];
			numerator.roots[zIndex].multiplicity = 1;
			zIndex++;
		}
	}

	rawDenom = getDenominator(tf);
	denominator.numRoots = getNumRoots(rawDenom);

	unprocessedPoles = getRoots(rawDenom, denominator.numRoots);

	uniquePoles = getNumUniqueRoots(unprocessedPoles, denominator.numRoots);

	denominator.size = uniquePoles;
	denominator.roots = malloc(sizeof(complex_t) * uniquePoles);

	// process zeros
	for(i = 0; i < denominator.numRoots; i++)
	{
		duplicateIndex = isDuplicate(unprocessedPoles, i, unprocessedPoles[i]);
		if(duplicateIndex != (-1))
		{
			denominator.roots[duplicateIndex].multiplicity++;
		}
		else
		{
			denominator.roots[pIndex] = unprocessedPoles[i];
			denominator.roots[pIndex].multiplicity = 1;
			pIndex++;
		}
	}


	printPolynomial(numerator.roots, numerator.numRoots);
	printPolynomial(denominator.roots, denominator.numRoots);


	/* centroid calculation */
	float centroid;
	centroid = FindCentroid(numerator, denominator);

	printf("centroid at: %f\n", centroid);

	// asymptote calculation 
	float angles[denominator.numRoots-numerator.numRoots];

	FindAsymptotes(numerator.numRoots, denominator.numRoots, angles);

	
	for(i = 0; i < (denominator.numRoots-numerator.numRoots); i++)
	{
		printf("asymptote starting at %f at an angle of %f\n", centroid, angles[i]);
	}



	float arrAngle[numerator.numRoots];	
	float depAngle[denominator.numRoots];


	j = 0;
	for(i = 0; j < numerator.numRoots; i++)
	{
		findArrival(numerator.roots[i], numerator, denominator, &arrAngle[i]);

		j += numerator.roots[i].multiplicity;

		printf("Arrival angle of zero at (%f, %f) is : %f degrees\n", 
			numerator.roots[i].real, numerator.roots[i].imag, arrAngle[i]);
	}


	j = 0;
	for(i = 0; j < denominator.numRoots; i++)
	{
		findDeparture(denominator.roots[i], numerator, denominator, &depAngle[i]);

		j += denominator.roots[i].multiplicity;

		printf("Departure angle of pole at (%f, %f) is : %f degrees\n", 
			denominator.roots[i].real, denominator.roots[i].imag, depAngle[i]);
	}


	float omegaZero, omegaInfty;

	omegaZero = sAtZero(numerator, denominator);
	omegaInfty = sToInfty(numerator, denominator);

	printf("s at zero: %f\n s at infinity: %f\n", omegaZero, omegaInfty);

   
}
