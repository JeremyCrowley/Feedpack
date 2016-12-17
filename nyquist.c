/* author: Jeremy Crowley */
/* file: nyquist.c */


#include "nyquist.h"


float sAtZero(polynomial_t numerator, polynomial_t denominator)
{
	int i;
	float numProduct = 1;
	float denomProduct = 1;
	/* check for ratio of origin zeros to origin poles and cancel */
	if(numerator.originRoots > denominator.originRoots)
	{
		return 0.0;
	}
	else if(numerator.originRoots < denominator.originRoots)
	{
		return INFINITY;
	}
	else
	{
		for(i = 0; i < numerator.numRoots; i++)
		{
			if(numerator.roots[i].imag == 0)
			{
				numProduct = numProduct * numerator.roots[i].real;
			}
			else if(numerator.roots[i].imag < 0) // only will catch one of the pairs of complex numbers
			{
				numProduct = numProduct * (numerator.roots[i].real - numerator.roots[i].imag);
			}
		}
		for(i = 0; i < denominator.numRoots; i++)
		{
			if(denominator.roots[i].imag == 0)
			{
				denomProduct = denomProduct * denominator.roots[i].real;
			}
			else if(denominator.roots[i].imag < 0)
			{
				denomProduct = denomProduct * (denominator.roots[i].real - denominator.roots[i].imag);
			}
		}

		return (numProduct/denomProduct);
	}

}

float sToInfty(polynomial_t numerator, polynomial_t denominator)
{
	if(denominator.numRoots > numerator.numRoots)
	{
		return 0.0;
	}
	else if(denominator.numRoots == numerator.numRoots)
	{
		return 1.0;
	}
	else
	{
		/* we should only be calculating for proper functions */
		return INFINITY;
	}
}