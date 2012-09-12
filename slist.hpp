#ifndef EULER_SLIST
#define EULER_SLIST

namespace euler
{
	template<class Ty> class slist
	{
	public:
		slist(){};

		typedef Ty* iter;
		typedef const Ty* citer;

	private:
		template<class Ty> struct node
		{
			Ty			val_;
			node<Ty>*	next_;
			node(const Ty& val) : val_(val) {};
			node() : val_() {}

		};
	};
};

#endif