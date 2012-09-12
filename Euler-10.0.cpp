/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include "euler.h"

void Euler_10_0()
{
	const int64_t N = 2000000;
	int64_t s = 0;
	for( int i = 2; i < N; ++i )
		if( is_prime(i) )
			s += i;
	cout << s << endl;
}