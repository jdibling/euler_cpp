/*

Starting in the top left corner of a 2x2 grid, there are 6 routes (without backtracking) to the bottom right corner.


How many routes are there through a 20x20 grid?

	X X
	X X

	X X X
	X X X
	X X X

	0 1 2

0 	1 1 1
1	1 2 3
2	1 3 6


	1 1 1  1
	1 2 3  4
	1 3 6  10
	1 4 10 20

*/

#include "euler.h"

void Euler_15_0()
{
	const size_t X = 20, Y = 20;

	uint64_t edges[X+1][Y+1] = {1};

	for( int x = 0; x <= X; ++x )
	{
		for( int y = 0; y <= Y; ++y )
		{
			if( x < X )
				edges[x+1][y] += edges[x][y];
			if( y < Y )
				edges[x][y+1] += edges[x][y];
		}
	}

	cout << edges[X][Y] << endl;
}