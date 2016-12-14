/* author: Jeremy Crowley */
/* file: main.c */


#include <stdio.h>
#include "rootlocus.h"

int main(void)
{

	/* zeros of a transfer function */
	int numZeros = 1;
	complex_t zeros[numZeros];

	zeros[0].multiplicity = 1;
	zeros[0].real = -3;
	zeros[0].imag = 0;

	/* poles of a transfer function */
	int numPoles = 4;
	complex_t poles[numPoles];

	poles[0].multiplicity = 1;
	poles[0].real = 0;
	poles[0].imag = 0;

	poles[1].multiplicity = 1;
	poles[1].real = -10;
	poles[1].imag = 0;

	poles[2].multiplicity = 1;
	poles[2].real = -1;
	poles[2].imag = 1;

	poles[3].multiplicity = 1;
	poles[3].real = -1;
	poles[3].imag = -1;

	/* centroid calculation */
	float centroid;
	centroid = FindCentroid(zeros, numZeros, poles, numPoles);

	printf("centroid at: %f\n", centroid);

	/* asymptotoe calculation */
	float angles[numPoles-numZeros];

	FindAsymptotes(centroid, numZeros, numPoles, angles);

	int i;
	for(i = 0; i < (numPoles-numZeros); i++)
	{
		printf("asymptote starting at %f at an angle of %f\n", centroid, angles[i]);
	}

	/* departure calculation */
	//float depAngle;

   
}
