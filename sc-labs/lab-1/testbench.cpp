#include "stdafx.h"
#include "testbench.h"

void driver::drivea() {
	d_a.write((sc_bit)false);	//b a = 0 0
	wait(5, SC_NS);
	d_a.write((sc_bit)true);	//b a = 0 1
	wait(5, SC_NS);
	d_a.write((sc_bit)0);		//b a = 1 0
	wait(5, SC_NS);
	d_a.write((sc_bit)1);		//b a = 1 1
	wait(5, SC_NS);
}

void driver::driveb() {
	d_b.write((sc_bit)0);		//to set b to 0 for 10 nanoseconds
	wait(10, SC_NS);
	d_b.write((sc_bit)1);		//to set b to 1 for 5 nanoseconds, probably should be 10ns
	wait(5, SC_NS);

}