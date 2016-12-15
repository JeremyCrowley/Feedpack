/* author: Jeremy Crowley */
/* file: nyquist.c */


#include "nyquist.h"


float sAtZero(complex_t *zeros, int numZeros, complex_t *poles, int numPoles)
{
	int i;

	/* check for ratio of origin zeros to origin poles and cancel */



	/* iterate through zeros */
	/* if any are left at origin --> return zero */
	for(i = 0; i < numPoles; i++)
	{
		
	}

	/* iterate through poles */
	/* if any are left at origin --> return infty */
	
	return 0;
}

float sToInfty(complex_t *zeros, int numZeros, complex_t *poles, int numPoles)
{
	if(numPoles > numZeros)
	{
		return 0.0;
	}
	else if(numPoles == numZeros)
	{
		return 1.0;
	}
	else
	{
		/* we should only be calculating for proper functions */
		return -1.0;
	}
}