/* author: Jeremy Crowley */
/* file: datatypes.h */


#ifndef DATATYPES_H
#define DATATYPES_H


/* data type for a complex number */

struct ComplexNumber
{
	int multiplicity;
	float real;
	float imag;
};

typedef struct ComplexNumber complex_t;


/* struct for the numerator or denominator of a transfer function */

struct Polynomial
{
	int numRoots;		// total number of zeros
	int originRoots;	// number of roots at the origin
	complex_t *roots;
};

typedef struct Polynomial polynomial_t;


/* struct for a transfer function */

struct TransferFunction
{
	float gain;
	polynomial_t numerator;
	polynomial_t denominator;
};

typedef struct TransferFunction transfer_t;


#endif /* DATATYPES_H */