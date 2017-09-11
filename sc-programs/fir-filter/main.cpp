//main.cpp
#include "stdafx.h"
#include <systemc.h>
#include "fir.h"
#include "tb.h"

//Top Module
SC_MODULE(SYSTEM) {
	//Declaring lower level modules
	Fir* fir0;
	Tb* tb0;

	sc_signal<bool>	rst_sig;
	sc_signal<sc_int<16>> inp_sig;
	sc_signal<sc_int<16>> outp_sig;

	sc_clock clk_sig;

	SC_CTOR(SYSTEM)
		:clk_sig("clk_sig", 10, SC_NS)
	{
		tb0 = new Tb("tb0");
		tb0->clk(clk_sig);
		tb0->inp(inp_sig);
		tb0->outp(outp_sig);
		tb0->rst(rst_sig);

		fir0 = new Fir("fir0");
		fir0->clk(clk_sig);
		fir0->inp(inp_sig);
		fir0->outp(outp_sig);
		fir0->rst(rst_sig);
	}

	~SYSTEM() {
		delete tb0;
		delete fir0;
	}
};

SYSTEM* top = NULL;

int sc_main(int argc, char* argv[])
{
	top = new SYSTEM("top");
	sc_start();
	return 0;
}