/*

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

*/
#include "euler.h"

string digits [] =
{
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

string teens [] =
{
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen"
};

string tens [] =
{
	"ten",
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety"
};

string mag [] =
{
	"hundred",
	"thousand"
};

string to_str(unsigned int x)
{
	string ret;
	int thousands = x/1000;
	if( thousands )
	{
		ret += digits[thousands];
		ret += " thousand";
	}
	int hundreds = (x-(thousands*1000))/100;
	if( hundreds )
	{
		if( !ret.empty() )
			ret += " ";
		ret += digits[hundreds];
		ret += " hundred";
	}
	int cent = x%100;
	if( cent >= 11 && cent <= 19 )
	{
		if( !ret.empty() )
			ret += " and ";
		ret += teens[(cent%10)-1];
	}
	else if( cent == 0 && ret.empty() )
	{
		ret = digits[0];
	}
	else
	{
		if( !ret.empty() && cent > 0 )
			ret += " and";
		int t = cent/10;
		int o = cent%10;
		if( t > 0 )
		{
			ret+= " ";
			ret += tens[t-1];
		}
		if( o > 0 )
		{
			if( t > 0 )
				ret += "-";
			else
				ret += " ";
			ret += digits[o];
		}
	}

	return ret;
}

void Euler_16_0()
{
	map<char,uint64_t> chars;

	for( int i = 1; i <= 1000; ++i )
	{
		string s = to_str(i);
		for_each(s.begin(), s.end(), [&chars](char c)
		{
			chars[c] += 1;
		});
	}
	
	uint64_t x = 0;
	for( char c = 'a'; c <= 'z'; ++c )
		x += chars[c];

	cout << x << endl;

}
