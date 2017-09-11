//tb.cpp
#include "stdafx.h"
#include "tb.h"

void Tb::source() {
	//Reset, we reset the output ports of the testbench initially
	inp.write(0);
	rst.write(0);
	wait();
	rst.write(1);
	wait();

	//Read Inputs
	sc_int<16> tmp;
	//Send stimulus to FIR
	for (int i = 0; i < 64; i++)
	{
		if ((i > 23) && (i < 29))
			tmp = 256;
		else
			tmp = 0;
		inp.write(tmp);
		wait();
	}
}

void Tb::sink() {
	sc_int<16> indata;
	//Read output coming from DUT (Design Under Test)
	for (int i = 0; i < 64; i++)
	{
		indata = outp.read();
		wait();
		cout << i << ":\t" << indata.to_int() << endl;
	}
	//End simulation
	system("pause");
	sc_stop();
}