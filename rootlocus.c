/* author: Jeremy Crowley */
/* file: rootlocus.c */


#include "rootlocus.h"

#define PI 3.141592

float SumRoots(polynomial_t polynomial)
{
	int i, j;
	int sum = 0;

	/* add all real parts (imaginary will cancel) */ 
	for(i = 0; i < polynomial.numRoots; i++)
	{	
		for(j = polynomial.roots[i].multiplicity; j > 0;j--)
		{
			sum += polynomial.roots[i].real;
		}	
	}
	return sum;
}

float FindCentroid(polynomial_t numerator, polynomial_t denominator)
{
	float centroid = 0;
	float sumZeros, sumPoles;

	/* find the sum of the zeros and the poles */
	sumZeros = SumRoots(numerator);
	sumPoles = SumRoots(denominator);

	centroid = (sumPoles - sumZeros) / (denominator.numRoots - numerator.numRoots);

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

void findDeparture(complex_t pole, polynomial_t numerator, polynomial_t denominator, float *depAngle)
{
	int i, j, k;
	float zeroAngleSum = 0;
	float poleAngleSum = 0;

	float imagLen, realLen, angle;
	
	/* sum the angles from the zeros to the pole */

	j=0;
	for(i = 0; i < numerator.numRoots; i += numerator.roots[i].multiplicity)
	{
		imagLen = pole.imag - numerator.roots[j].imag;
		realLen = pole.real - numerator.roots[j].real;

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
		zeroAngleSum += (angle * numerator.roots[j].multiplicity);
		j++;
	}

	/* sum the angles from the poles to the pole */

	j=0;
	for(i = 0; i < denominator.numRoots; i += denominator.roots[j].multiplicity)
	{
		imagLen = pole.imag - denominator.roots[j].imag;
		realLen = pole.real - denominator.roots[j].real;

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
		poleAngleSum += (angle * denominator.roots[j].multiplicity);
		j++;		
	}

	
	/* calculate the departure angles for the pole */
	/* and account for multiplicity */
	k = 0;
	for(i = 0; i < pole.multiplicity; i++)
	{
		depAngle[i] = zeroAngleSum - poleAngleSum - (180/pole.multiplicity) - (360/pole.multiplicity) * k;
		k++;

		if(depAngle[i] + 180 < 0)
		{
			while(depAngle[i] + 180 < 0)
			{
				depAngle[i] += 360;
			}
		}
		else if(depAngle[i] > 180)
		{
			while(depAngle[i] > 180)
			{
				depAngle[i] -= 360;
			}
		}
		else{
			// do nothing
		}

	}

}


void findArrival(complex_t zero, polynomial_t numerator, polynomial_t denominator, float *arrAngle)
{
	int i, j, k;
	float zeroAngleSum = 0;
	float poleAngleSum = 0;

	float imagLen, realLen, angle;
	
	/* sum the angles from the zeros to the pole */

	j=0;
	for(i = 0; i < numerator.numRoots; i += numerator.roots[i].multiplicity)
	{
		imagLen = zero.imag - numerator.roots[j].imag;
		realLen = zero.real - numerator.roots[j].real;

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
		zeroAngleSum += (angle * numerator.roots[j].multiplicity);
		j++;
	}

	/* sum the angles from the poles to the pole */

	j=0;
	for(i = 0; i < denominator.numRoots; i += denominator.roots[j].multiplicity)
	{
		imagLen = zero.imag - denominator.roots[j].imag;
		realLen = zero.real - denominator.roots[j].real;

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
		poleAngleSum += (angle * denominator.roots[j].multiplicity);
		j++;		
	}

	
	/* calculate the arrival angles for the zeros */
	/* and account for multiplicity */
	k = 0;
	for(i = 0; i < zero.multiplicity; i++)
	{
		arrAngle[i] = poleAngleSum - zeroAngleSum + (180/zero.multiplicity) + (360/zero.multiplicity) * k;
		k++;

		if(arrAngle[i] + 180 < 0)
		{
			while(arrAngle[i] + 180 < 0)
			{
				arrAngle[i] += 360;
			}
		}
		else if(arrAngle[i] > 180)
		{
			while(arrAngle[i] > 180)
			{
				arrAngle[i] -= 360;
			}
		}
		else{
			// do nothing
		}

	}

}



