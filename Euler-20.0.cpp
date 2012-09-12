/*

n! means n  (n  1)  ...  3  2  1

For example, 10! = 10  9  ...  3  2  1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

*/

#include "euler.h"
#include "slist.hpp"

#include <vector>
using namespace std;


/*


		6	7	2
			4	8
		----------
				
	     4/	5/8	1/6	 /6
  /2	2/4  /8  /8  0/0 

  ==============================

    3   2   2     5    6  




			6	7	2
				4	8
			----------
				9	6
		3	3	6
	2	8	8
	===================
	3	2	2	5	6


				
*/

template<class Ty, Ty Def=Ty()> class setvec
{
public:
	setvec(Ty val) : val_(val) {}
	operator vector<Ty> () const
	{
		vector<Ty> ret;
		for( Ty xx=val_; xx>Def; xx/=10 )
			ret.push_back(xx%10);
		return ret;
	}
private:
	Ty val_;
};

template<class Ty, Ty Def=Ty()> class mulvec
{
public:
	mulvec(const vector<Ty>& X, const vector<Ty>& Y) : X_(X), Y_(Y) {};
	operator vector<Ty> () const
	{
		vector<Ty> Z;

		for( size_t Xi = 0; Xi < X_.size(); ++Xi )
		{
			Ty xx = X_[Xi];
			for( size_t Yi = 0; Yi < Y_.size(); ++Yi )
			{
				Ty yy = Y_[Yi];

				Ty prod = X_[Xi] * Y_[Yi];
				for( size_t Zi = Xi+Yi; prod>0; prod/=10, ++Zi )
				{
					while( Z.size() < (Zi+1) )
						Z.push_back(Def);

					prod += Z[Zi];
					Z[Zi] = prod%10;
				}
			}
		}

		
		return Z;
	}
private:
	vector<Ty> X_, Y_;
};

void Euler_20_0()
{
//	static const unsigned n = 10;
	static const unsigned n = 100;

	vector<unsigned> X = setvec<unsigned>(1), Y;
	for( unsigned i = 2; i <= n; ++i )
	{
		vector<unsigned> Y = setvec<unsigned>(i);
		vector<unsigned> Z = mulvec<unsigned>(X,Y);
		X = Z;
	}

	uint64_t ttl = std::accumulate(X.begin(), X.end(), uint64_t(0), [](uint64_t accum, unsigned x) -> uint64_t
	{
		return accum+(uint64_t)x;
	});

	cout << "The sum of the digits in " << n << "! is: " << ttl << endl;
}

