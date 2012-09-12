/*
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include "euler.h"

void Euler_6_0()
{
	const int N = 100;
	int s_sq = 0;  // sum of squares
	int s = 0;  // sum
	
	for( int i = 1; i <= N; ++i )
	{
		s += i;
		s_sq += (i*i);
	}

	int sq_s = s*s;

	cout << "[1.." << N << "] : Sum/Squares = " << s_sq << "\tSquare/Sums = " << sq_s << "\tDiff = " << std::max(s_sq,sq_s) - std::min(s_sq,sq_s) << endl;
}