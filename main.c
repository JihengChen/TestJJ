/*
 * main.c
 *
 *  Created on: Oct 9, 2015
 *      Author: Jiheng Chen
 */

#include <stdio.h>
#include <math.h>

double newton( double x0, double epsilon, double (*f)(double), double (*fprim)(double) )
{
	double x_pre, x;			         										// x_pre: the previous x value
																				// x: the current x value
	x_pre = x0;

	for( ;; )																	// An infinite loop
	{
		x = x_pre - f(x_pre) * 1.0 / fprim(x_pre);				// The implementation of Newton-Raphson method
		if( fabs(x - x_pre) < epsilon ) break;					// Iterating until the accuracy condition is reached
		x_pre = x;															// Preparation for next iteration
	}

	return x;																// Return the root
}

double f( double v )													// A desired function
{
	return 70 * pow(v, 3) - 3 * pow(v, 2) + 4 * v - 16;
}

double fprim( double v )											// The derivative of the desired funcion
{
	return 210 * pow(v, 2) - 6 * v + 4;
}

int main()
{
	double x0, epsilon;												// x0: the initial estimate.		epsilon: the desired accuracy
	double (*f1)() = f;													// f1: pointer to the desired function f
	double (*f2)() = fprim;											// f2: pointer to the derivative function fprim

	printf("Enter the initial estimate value(e.g. 1):\n");
	fflush( stdout );
	scanf("%lf", &x0);															// Let user enter the initial estimate value.
	printf("Enter the desired accuracy(e.g. 0.0001):\n");
	fflush( stdout );
	scanf("%lf", &epsilon);													// Let user enter the desired accuracy.

	printf("The root is %lf.\n", newton(x0, epsilon, f1, f2) );		// Calculate the root and print it out.

	return 0;
}
