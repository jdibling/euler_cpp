/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder. 
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
#include "euler.h"

template<int N> bool div_by_all(int n)
{
	for( int i = 1; i <= N; ++i )
		if( 0 != (n%i) )
			return false;
	return true;
}

template<int N> int get_smallest_div_by_all()
{
	for( int i = N+1; ; ++i )
	{
		if( div_by_all<N>(i) )
			return i;
	}
}

void Euler_5_0()
{
	const int N = 20;

	cout << get_smallest_div_by_all<N>() << endl;
}