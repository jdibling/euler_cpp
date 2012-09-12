/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include "euler.h"

template<class Int> bool is_palendromic_number(Int X)
{
	stringstream ss;
	ss << X;
	string s = ss.str();
	string s2 = s;
	reverse(s2.begin(), s2.end());

	return s2 == s;	
}

void Euler_4_0()
{
	int64_t Y = 0, A = 0, B = 0;

	for( int i = 999; i >= 100; --i )
	{
		for( int j = 999; j >= 100; --j )
		{
			int64_t y = i*j;
			if( is_palendromic_number(y) && y > Y )
			{
				Y = y;
				A = i;
				B = j;
			}
		}
	}

	
	cout << Y << " = " << A << " * " << B << endl;
	return;

}