/* 
 * SYSC 2006
 * Incomplete implementations of the functions that will be coded during the lab. 
 */

#include <stdlib.h>
#include <math.h>

#include "composition.h"

/* Returns n! for n >= 0. (0! is defined to be 1.)
   Note that the return type is int, and n! grows rapidly as n increases,
   so this function should only be used for fairly small values of n; 
   i.e., if signed ints are implemented as 32-bit values, n must be <= 12.
*/
int fact(int n)
{	
	int fact = 1;
	for(int c = 1; c <= n; c++)
	{
		fact = fact*c;
	}
    return fact;
}

/* Returns the number of different ordered subsets of k objects picked
   from a set of n objects, for n > 0, k > 0, n >= k.
 */
int ordered_sub(int n, int k)
{
    return (fact(n)/fact(n - k));
}

/* Returns the binomial coefficient (n k); that is, the number of 
   combinations of k objects that can be chosen from a set of n objects, 
   for n > 0, k > 0, n >= k.
 */
int binom(int n, int k)
{
    return (ordered_sub(n, k)/fact(k));
}

/* Returns the cosine of x (measured in radians) by calculating
 * the first n terms of the infinite series expansion of cosine.
 */
double cosine(double x, int n)
{
	double cos = 1;
	int b = 2;

	while(n > 0)
	{
		cos = cos - (pow(x, b)/fact(b));
		n--;
		cos = cos + (pow(x, b+2)/fact(b+2));
		n--;
		b = b + 4;
	}

    return cos;
}

