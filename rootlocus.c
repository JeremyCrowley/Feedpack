/* author: Jeremy Crowley */
/* file: rootlocus.c */


#include "rootlocus.h"

float SumRoots(complex_t roots[], int numRoots)
{
	int i;
	int sum = 0;

	for(i = 0; i < numRoots; i++)
	{
		sum += roots[i].real;
	}
	return sum;
}

float FindCentroid(complex_t zeros[], int numZeros, complex_t poles[], int numPoles)
{
	float centroid = 0;
	float sumZeros, sumPoles;

	sumZeros = SumRoots(zeros, numZeros);
	sumPoles = SumRoots(poles, numPoles);

	centroid = (sumPoles - sumZeros) / (numPoles - numZeros);

	return centroid;
}

void FindAsymptotes(float centroid, int numZeros, int numPoles, float angleArray[numPoles-numZeros])
{
	int i;

	for(i = 0; i < (numPoles-numZeros); i++)
	{
		angleArray[i] = (180 + 360 * i)/(numPoles-numZeros);
	}
}