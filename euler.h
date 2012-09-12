#include <cstdlib>
#include <string>
#include <vector>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <set>
#include <iostream>
using namespace std;

#include <boost/chrono.hpp>

template<class Int> bool is_prime(Int X)
{
	Int Xa = (Int)(floor(sqrt((double)X)));
	for( int i = 2; i <= Xa; ++i )
	{
		if( !(X%i) )
			return false;
	}
	return true;
}

inline int ctoi(char c)
{
	if( c < '0' || c > '9' )
		return -1;
	return c-'0';
}

inline char itoc(int i)
{
	return static_cast<char>((i%10)+'0');
}

