/*

A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

#include "euler.h"

void Euler_9_0()
{
	for( int a = 1; a < 998 ;++a )
	{
		for( int b = a+1; b < 999;++b )
		{
			int c = 1000 - (a+b);
			int a2 = a*a;
			int b2 = b*b;
			int c2 = c*c;

			if( a2+b2 == c2 )
			{
				cout << "abc = " << a*b*c << endl;
				return;
			}
		}
	}

	cout << "Not Found!" << endl;
}