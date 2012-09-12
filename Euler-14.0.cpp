/*

The following iterative sequence is defined for the set of positive integers:

n  n/2 (n is even)
n  3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13  40  20  10  5  16  8  4  2  1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

*/

#include "euler.h"

namespace
{
	static uint64_t cache_miss = 0;

	uint64_t generate_chain(uint64_t start)
	{
		uint64_t terms = 1; // 1 for the last 1 term
		for( uint64_t i = start; i != 1; ++terms )
		{
			if( i%2 )
				i = (3*i)+1;
			else
				i/=2;
			++cache_miss;
		}
		return terms;
	}
};

void Euler_14_0()
{
	const uint64_t N = 1000000;
	uint64_t max_terms = 0, max_start = 0;
	for( int i = 1; i <= N; ++i )
	{
		uint64_t terms = generate_chain(i);
		if( terms > max_terms )
		{
			max_terms = terms;
			max_start = i;
		}
	}
	cout << max_start << " has " << max_terms << " terms. " << cache_miss << " Cache Misses." << endl;
}


