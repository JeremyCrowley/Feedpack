/* author: Jeremy Crowley */
/* file: rootlocus.c */


#include "rootlocus.h"

float SumRoots(complex_t roots[], int numRoots)
{
	int i, j;
	int sum = 0;

	/* add all real parts (imaginary will cancel) */ 
	for(i = 0; i < numRoots; i++)
	{
		for(j = roots[i].multiplicity; j > 1;j++)
		{
			sum += roots[i].real;
		}
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

float findDeparture(complex_t pole, complex_t *zeros, int numZeros, complex_t *poles, int numPoles)
{
	int i;
	float depAngle = 0;
	float zeroAngleSum = 0;
	float poleAngleSum = 0;

	float imagLen, realLen;
	

	for(i = 0; i < numZeros; i++)
	{
		imagLen = pole.imag - zeros[i].imag;
		realLen = pole.real - zeros[i].real;

		zeroAngleSum += atan(imagLen/realLen);
	}

	for(i = 0; i < numPoles; i++)
	{
		imagLen = pole.imag - poles[i].imag;
		realLen = pole.real - poles[i].real;

		poleAngleSum += atan(imagLen/realLen);
	}

	// not complete formula
	depAngle = zeroAngleSum - poleAngleSum;


	return depAngle;


}