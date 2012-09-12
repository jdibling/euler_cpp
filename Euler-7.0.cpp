/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
*/
#include "euler.h"

template<class Int, size_t N> Int get_nth_prime()
{
	Int x = 2;
	for( Int n = 0;n < N ; ++x )
	{
		if( is_prime(x) )
			++n;
	} 
	return x;
}

void Euler_7_0()
{
	const int N = 10001;

	int x = get_nth_prime<int,N>();

	cout << x << endl;
}