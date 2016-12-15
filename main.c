/* author: Jeremy Crowley */
/* file: main.c */


#include <stdio.h>
#include "rootlocus.h"

/* pound defines for enabling different transfer functions */
//#define PROBLEM_5_7_A
#define PROBLEM_5_7_C

int main(void)
{

	#ifdef PROBLEM_5_7_A
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

	#endif /* PROBLEM_5_7_A */

	#ifdef PROBLEM_5_7_C

	/* zeros of a transfer function */
	int numZeros = 2;
	complex_t zeros[numZeros];

	zeros[0].multiplicity = 2;
	zeros[0].real = -3;
	zeros[0].imag = 0;

	/* poles of a transfer function */
	int numPoles = 5;
	complex_t poles[numPoles];

	poles[0].multiplicity = 2;
	poles[0].real = 0;
	poles[0].imag = 0;

	poles[1].multiplicity = 1;
	poles[1].real = -10;
	poles[1].imag = 0;

	poles[2].multiplicity = 1;
	poles[2].real = -3;
	poles[2].imag = 4;

	poles[3].multiplicity = 1;
	poles[3].real = -3;
	poles[3].imag = -4;

	#endif /* PROBLEM_5_7_C */


	/* centroid calculation */
	float centroid;
	centroid = FindCentroid(zeros, numZeros, poles, numPoles);

	/* asymptotoe calculation */
	float angles[numPoles-numZeros];

	FindAsymptotes(centroid, numZeros, numPoles, angles);

	int i;
	for(i = 0; i < (numPoles-numZeros); i++)
	{
		printf("asymptote starting at %f at an angle of %f\n", centroid, angles[i]);
	}


	#if defined(PROBLEM_5_7_C) || defined(PROBLEM_5_7_A) 

	/* departure calculation */
	float depAngle0[poles[0].multiplicity];
	float depAngle1[poles[1].multiplicity];
	float depAngle2[poles[2].multiplicity];
	float depAngle3[poles[3].multiplicity];

	findDeparture(poles[0], zeros, numZeros, poles, numPoles, depAngle0);
	for(i = 0; i < poles[0].multiplicity; i++)
	{
		printf("Departure angle of pole at (%f, %f) is : %f degrees\n", poles[0].real, poles[0].imag, depAngle0[i]);
	}
	
	
	findDeparture(poles[1], zeros, numZeros, poles, numPoles, depAngle1);
	for(i = 0; i < poles[1].multiplicity; i++)
	{
		printf("Departure angle of pole at (%f, %f) is : %f degrees\n", poles[1].real, poles[1].imag, depAngle1[i]);
	}
	
	
	findDeparture(poles[2], zeros, numZeros, poles, numPoles, depAngle2);
	for(i = 0; i < poles[2].multiplicity; i++)
	{
		printf("Departure angle of pole at (%f, %f) is : %f degrees\n", poles[2].real, poles[2].imag, depAngle2[i]);
	}

	
	findDeparture(poles[3], zeros, numZeros, poles, numPoles, depAngle3);
	for(i = 0; i < poles[3].multiplicity; i++)
	{
		printf("Departure angle of pole at (%f, %f) is : %f degrees\n", poles[3].real, poles[3].imag, depAngle3[i]);
	}

	#endif /* PROBLEM_5_7_C */
   
}
