/* author: Jeremy Crowley */
/* file: rootlocus.h */


#ifndef ROOTLOCUS_H
#define ROOTLOCUS_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "datatypes.h"

/* desc - calculates the sum of the roots from an array of complex numbers (zeros or poles) 
 * param - roots is a pointer to the array containing the roots
 * param - numRoots is the number of roots in the array 
 * ret - a floating point value of the sum
 */
float SumRoots(polynomial_t Polynomial);

/* desc - calculates the centroid of the rootlocus given the zeros and poles
 * param - zeros is a pointer to an array containing the zeros
 * param - numZeros is the number of roots in the array 
 * param - poles is a pointer to an array containing the poles
 * param - numPoles is the number of poles in the array
 * ret - a floating point value of the centroid
 */
float FindCentroid(polynomial_t numerator, polynomial_t denominator);

/* desc - writes angle of asymptotes to array 
 * param - centroid is the location of the centroid on the real axis
 * param - numZeros is the number of roots in the array 
 * param - numPoles is the number of poles in the array
 * param - angleArray is a pointer to the array to be filled with the angles of the asymptotes
 * ret - void
 */
void FindAsymptotes(int numZeros, int numPoles, float *angleArray);

/* desc - finds the departure angle of a pole 
 * param - poles is the pole for which the departure angle is being calculated
 * param - zeros is a pointer to an array containing the zeros
 * param - numZeros is the number of roots in the array 
 * param - poles is a pointer to an array containing the poles
 * param - numPoles is the number of poles in the array
 * param - depAnlgle is a pointer to the array of departure angles
 * ret - void
 */
void findDeparture(complex_t pole, polynomial_t numerator, polynomial_t denominator, float *depAngle);

/* desc - finds the departure angle of a pole 
 * param - zero is the zero for which the arrival angle is being calculated
 * param - zeros is a pointer to an array containing the zeros
 * param - numZeros is the number of roots in the array 
 * param - poles is a pointer to an array containing the poles
 * param - numPoles is the number of poles in the array
 * param - arrAngle is a pointer to the array of arrival angles
 * ret - void
 */
void findArrival(complex_t zero, polynomial_t numerator, polynomial_t denominator, float *arrAngle);


#endif
