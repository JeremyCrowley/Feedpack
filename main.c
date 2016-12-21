/* author: Jeremy Crowley */
/* file: main.c */


#include <stdio.h>
#include <string.h>
#include "rootlocus.h"
#include "nyquist.h"

//#define ROOTLOCUS_TEST
//#define NYQUIST_TEST

/* pound defines for enabling different transfer functions */
#define PROBLEM_5_7_A
//#define PROBLEM_5_7_C


#define INPUT_TEST

int main(void)
{
	int i;
	int slash;

	char *transferFunc = malloc(sizeof(char)*100);
	char *rawDenom = malloc(sizeof(char)*100);;
	char *rawNum = malloc(sizeof(char)*100);;
	

	#ifdef INPUT_TEST

	char *tf = malloc(sizeof(char)*100);

	char *den = malloc(sizeof(char)*100);
	char *num = malloc(sizeof(char)*100);
	char ch;
	ch = '/';

	den = NULL;
	num = NULL;

	printf("Hello, welcome to Jeremy's feedback control package\n");
	printf("Please enter a transfer function: \n");
	scanf("%s", tf);
	printf("You entered: %s\n", tf);

	strcpy(transferFunc, tf);

	den = strchr(tf, ch);
	den = den+1;

	strcpy(rawDenom, den);	
	
	num = strstr(tf, &ch);
	
	slash = num - tf;

	strncpy(rawNum, tf, slash);

	
	printf("numerator: %s\n", rawNum);
	printf("denominator: %s\n", rawDenom);
	printf("transfer: %s\n", transferFunc);
	



	#endif /* INPUT_TEST */

	#ifdef ROOTLOCUS_TEST


	#ifdef PROBLEM_5_7_A
	/* zeros of a transfer function */
	int numZeros = 1;
	complex_t zeros[numZeros];

	zeros[0].multiplicity = 1;
	zeros[0].real = -3;
	zeros[0].imag = 0;

	polynomial_t numerator;

	numerator.numRoots = numZeros;
	numerator.originRoots = 0;

	// need to make a function for this
	numerator.roots = (complex_t*)malloc(sizeof(complex_t)*numerator.numRoots);
	numerator.roots[0] = zeros[0];

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

	
	polynomial_t denominator;

	denominator.numRoots = numPoles;
	denominator.originRoots = 1;

	denominator.roots = (complex_t*)malloc(sizeof(complex_t)*denominator.numRoots);
	denominator.roots[0] = poles[0];
	denominator.roots[1] = poles[1];
	denominator.roots[2] = poles[2];
	denominator.roots[3] = poles[3];

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
	centroid = FindCentroid(numerator, denominator);

	/* asymptotoe calculation */
	float angles[numPoles-numZeros];

	FindAsymptotes(centroid, numZeros, numPoles, angles);

	
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

	float arrAngle0[zeros[0].multiplicity];

	findDeparture(denominator.roots[0], numerator, denominator, depAngle0);
	for(i = 0; i < denominator.roots[0].multiplicity; i++)
	{
		printf("Departure angle of pole at (%f, %f) is : %f degrees\n", 
			denominator.roots[0].real, denominator.roots[0].imag, depAngle0[i]);
	}
	
	
	findDeparture(denominator.roots[1], numerator, denominator, depAngle1);
	for(i = 0; i < denominator.roots[1].multiplicity; i++)
	{
		printf("Departure angle of pole at (%f, %f) is : %f degrees\n", 
			denominator.roots[1].real, denominator.roots[1].imag, depAngle1[i]);
	}
	
	
	findDeparture(denominator.roots[2], numerator, denominator, depAngle2);
	for(i = 0; i < denominator.roots[2].multiplicity; i++)
	{
		printf("Departure angle of pole at (%f, %f) is : %f degrees\n", 
			denominator.roots[2].real, denominator.roots[2].imag, depAngle2[i]);
	}

	
	findDeparture(denominator.roots[3], numerator, denominator, depAngle3);
	for(i = 0; i < denominator.roots[3].multiplicity; i++)
	{
		printf("Departure angle of pole at (%f, %f) is : %f degrees\n", 
			denominator.roots[3].real, denominator.roots[3].imag, depAngle3[i]);
	}

	findArrival(numerator.roots[0], numerator, denominator, arrAngle0);
	for(i = 0; i < numerator.roots[0].multiplicity; i++)
	{
		printf("Arrival angle of zeros at (%f, %f) is : %f degrees\n", numerator.roots[0].real, numerator.roots[0].imag, arrAngle0[i]);
	}
	#endif /* PROBLEM_5_7_C */


	#endif /* ROOTLOCUS_TEST */



	#ifdef NYQUIST_TEST

	/* zeros of a transfer function */
	int numZeros = 1;
	complex_t zeros[numZeros];

	zeros[0].multiplicity = 1;
	zeros[0].real = -2;
	zeros[0].imag = 0;

	polynomial_t numerator;

	numerator.numRoots = numZeros;
	numerator.originRoots = 0;

	// need to make a function for this
	numerator.roots = (complex_t*)malloc(sizeof(complex_t)*numerator.numRoots);
	numerator.roots[0] = zeros[0];


		/* poles of a transfer function */
	int numPoles = 1;
	complex_t poles[numPoles];

	poles[0].multiplicity = 1;
	poles[0].real = -10;
	poles[0].imag = 0;

	
	polynomial_t denominator;

	denominator.numRoots = numPoles;
	denominator.originRoots = 0;

	denominator.roots = (complex_t*)malloc(sizeof(complex_t)*denominator.numRoots);
	denominator.roots[0] = poles[0];


	float omegaZero, omegaInfty;

	omegaZero = sAtZero(numerator, denominator);
	omegaInfty = sToInfty(numerator, denominator);

	printf("s at zero: %f\n s at infinity: %f\n", omegaZero, omegaInfty);


	#endif /* NYQUIST_TEST */
   
}
