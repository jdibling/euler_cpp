/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/


#include "euler.h"


void Euler_3_0()
{
	//int N = 13195;
	int64_t N = 600851475143;
	int64_t Na = static_cast<int>(ceil(sqrt(static_cast<float>(N))));

	vector<int64_t> factors;

	for( int i = 2; i < Na; ++i )
	{
		if( !(N%i) )
			factors.push_back(i);
	}

	vector<int64_t>::const_reverse_iterator highest_prime = find_if(factors.rbegin(), factors.rend(), &::is_prime<int>);

	cout << *highest_prime << endl;

}