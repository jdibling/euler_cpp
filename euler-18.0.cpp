#include "euler.h"

#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <numeric>
using namespace std;
#include <boost/tokenizer.hpp>
using namespace boost;

struct Node
{
	unsigned val_, cost_;
	Node* parent_;

	Node(unsigned val) : val_(val), cost_(0), parent_(nullptr) {};
};

typedef vector<Node> Row;
typedef vector<Row> Rows;

void Euler_18_0()
{
	ifstream f;
	f.exceptions();
	f.open("euler-18.txt", ios::in);

	Rows rows;

	for( string line; getline(f, line, '\n'); )
	{
		static const string nums="0123456789";
		stringstream ss;
		ss << line;

		Row row;
		for( string tok ; getline(ss, tok, ' '); )
		{
			cout << "[" << tok << "] ";
			Node node(atoi(tok.c_str()));
			row.push_back(node);
		}
		cout << " @@" << endl;
		rows.push_back(row);
	}

	rows[0][0].cost_ = rows[0][0].val_;	// seed the top of the tree

	for( size_t row_n = 1; row_n < rows.size(); ++row_n )
	{
		Row& row = rows.at(row_n);
		Row& parent_row = rows.at(row_n-1);

		for( size_t col_n = 0, num_cols = row.size(); col_n < num_cols; ++col_n )
		{
			Node	*left = ((col_n == 0) ? nullptr : &parent_row.at(col_n-1)),
					*right = ((col_n == (num_cols-1)) ? nullptr : &parent_row.at(col_n));

			Node& me = row.at(col_n);
			if( !left )
			{
				me.cost_ = me.val_ + right->cost_;
				me.parent_ = left;
			}
			else if( !right )
			{
				me.cost_ = me.val_ + left->cost_;
				me.parent_ = right;
			}
			else
			{
				me.parent_ = ( (left->cost_ > right->cost_) ? left : right );
				me.cost_ = me.val_ + me.parent_->cost_;
			}
		}
	}

	cout << "Maximum Total: " << std::accumulate(rows.back().begin(), rows.back().end(), unsigned(0), [](unsigned prev, const Node& node) -> unsigned 
	{
		return ((node.cost_ > prev) ? node.cost_ : prev);
	}) << endl;
}