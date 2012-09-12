#include "euler.h"
#include <boost/chrono/process_cpu_clocks.hpp>
#include <cmath>


struct Euler
{
	typedef void(*EulerFN)();
	std::string name_;
	EulerFN fn_;
	Euler(const char* name, EulerFN fn) : name_(name), fn_(fn) {};
};

void Euler_1_0();
void Euler_2_0();
void Euler_3_0();
void Euler_4_0();
void Euler_5_0();
void Euler_6_0();
void Euler_7_0();
void Euler_8_0();
void Euler_8_1();
void Euler_9_0();
void Euler_10_0();
void Euler_11_0();
void Euler_12_0();
void Euler_13_0();
void Euler_14_0();
void Euler_14_1();
void Euler_14_2();
void Euler_15_0();
void Euler_16_0();
void Euler_18_0();
void Euler_20_0();

Euler eulers[] =
{
	//Euler("1.0", &Euler_1_0),
	//Euler("2.0", &Euler_2_0),
	//Euler("3.0", &Euler_3_0),
	//Euler("4.0", &Euler_4_0),
	//Euler("5.0", &Euler_5_0),
	//Euler("6.0", &Euler_6_0),
	//Euler("7.0", &Euler_7_0),
	//Euler("8.0", &Euler_8_0),
	//Euler("9.0", &Euler_9_0),
	//Euler("10.0", &Euler_10_0),
	//Euler("11.0", &Euler_11_0),
	//Euler("12.0", &Euler_12_0),
	//Euler("13.0", &Euler_13_0),
	//Euler("14.0", &Euler_14_0),
	//Euler("14.1", &Euler_14_1),
	//Euler("14.2", &Euler_14_2),
	//Euler("15.0", &Euler_15_0),
	//Euler("16.0", &Euler_16_0)
	//Euler("18.0", &Euler_18_0)
	Euler("20.0", &Euler_20_0)

};

const size_t num_eulers = sizeof(eulers)/sizeof(eulers[0]);

int main()
{
	for( size_t e = 0; e < num_eulers; ++e )
	{
		cout << "===== "<< eulers[e].name_ << " " << string(40,'=') << endl;

		boost::chrono::steady_clock::time_point start = boost::chrono::steady_clock::now();
		////////////////////////////

		eulers[e].fn_();

		///////////////////////////
		boost::chrono::duration<double> sec = boost::chrono::steady_clock::now() - start;
		cout << "Executed in " << sec.count() << " seconds" << endl;
	}
	return 0;
}