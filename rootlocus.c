/* author: Jeremy Crowley */
/* file: rootlocus.c */


#include "rootlocus.h"

#define PI 3.141592

float SumRoots(complex_t roots[], int numRoots)
{
	int i, j;
	int sum = 0;

	/* add all real parts (imaginary will cancel) */ 
	for(i = 0; i < numRoots; i++)
	{	
		for(j = roots[i].multiplicity; j > 0;j--)
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

	/* find the sum of the zeros and the poles */
	sumZeros = SumRoots(zeros, numZeros);
	sumPoles = SumRoots(poles, numPoles);

	centroid = (sumPoles - sumZeros) / (numPoles - numZeros);

	return centroid;
}

void FindAsymptotes(float centroid, int numZeros, int numPoles, float *angleArray)
{
	int i;

	for(i = 0; i < (numPoles-numZeros); i++)
	{
		angleArray[i] = (180 + 360 * i)/(numPoles-numZeros);
	}
}

void findDeparture(complex_t pole, complex_t *zeros, int numZeros, complex_t *poles, int numPoles, float *depAngle)
{
	int i, j, k;
	float zeroAngleSum = 0;
	float poleAngleSum = 0;

	float imagLen, realLen, angle;
	
	/* sum the angles from the zeros to the pole */

	j=0;
	for(i = 0; i < numZeros; i += zeros[i].multiplicity)
	{
		imagLen = pole.imag - zeros[j].imag;
		realLen = pole.real - zeros[j].real;

		/* account for arctangent properites */
		if(imagLen == 0 && realLen == 0)
		{
			angle = 0;
		}
		else if(realLen < 0)
		{
			angle = (180/PI) * atan(imagLen/realLen) + 180;
		}
		else
		{
			angle = (180/PI) * atan(imagLen/realLen);
		}

		/* account for multiplicity of the pole */
		zeroAngleSum += (angle * zeros[j].multiplicity);
		j++;
	}

	/* sum the angles from the poles to the pole */

	j=0;
	for(i = 0; i < numPoles; i += poles[j].multiplicity)
	{
		imagLen = pole.imag - poles[j].imag;
		realLen = pole.real - poles[j].real;

		/* account for arctangent properites */
		if(imagLen == 0 && realLen == 0)
		{
			angle = 0;
		}
		else if(realLen < 0)
		{
			angle = (180/PI) * atan(imagLen/realLen) + 180;
		}
		else
		{
			angle = (180/PI) * atan(imagLen/realLen);
		}

		/* account for multiplicity of the pole */
		poleAngleSum += (angle * poles[j].multiplicity);
		j++;		
	}

	
	/* calculate the departure angles for the pole */
	/* and account for multiplicity */
	k = 0;
	for(i = 0; i < pole.multiplicity; i++)
	{
		depAngle[i] = zeroAngleSum - poleAngleSum - (180/pole.multiplicity) + 360 * k;
		k++;

		while(depAngle[i] < -180)
		{
			depAngle[i] += 360;
		}

	}

}