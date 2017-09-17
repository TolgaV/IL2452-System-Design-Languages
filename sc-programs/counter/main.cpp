//main.cpp
#include "stdafx.h"
#include "counter.h"

//Top Module
SC_MODULE(SYSTEM) {
	//Declaring lower level modules
	Counter *ctr0;

	sc_signal<bool>	rst_sig;
	sc_signal<int> out;
	sc_clock clk_sig;

SC_CTOR(SYSTEM)
		:clk_sig("clk_sig", 10, SC_NS)
	{
		ctr0 = new Counter("ctr0");
		ctr0->clock(clk_sig);
		ctr0->reset(rst_sig);
		/*Important: since port q of the
		counter was not allocated to any
		signal (right now its allocated to
		sc_signal out) the code wasn't building.
		*/
		ctr0->q(out);
	}

	~SYSTEM() {
		delete ctr0;
	}
};

SYSTEM* top = NULL;

int sc_main(int argc, char* argv[])
{
	top = new SYSTEM("top");
	sc_start();
	return 0;
}

/* For getting pure C++ implementation working make 
sure instance of Counter; ctr0 is initialized correctly.
*/