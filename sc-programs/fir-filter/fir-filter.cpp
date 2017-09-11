// fir-filter.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "systemc.h"

const sc_uint<8> coef[5] = {
	18,
	77,
	107,
	77,
	18
};

SC_MODULE(fir) {
	sc_in<bool> clk;
	sc_in<bool> rst;
	sc_in< sc_int<16> > inp;
	sc_out< sc_int<16> > outp;

	void fir_main();

	SC_CTOR(fir) {
		SC_CTHREAD(fir_main, clk.pos());	//SC_CTHREAD has two arguments, unlike SC_METHOD or SC_THREAD
		//SC_CTHREAD is only sensitive to clock, so there is no need to define a sensitivity list
		reset_signal_is(rst, true);			//(name of reset signal, its initial state)
	}
};

// FIR Main Thread fir_main(). It'll be a clocked thread (CTHREAD)
void fir::fir_main(void) {			//void is redundant but a good practice
	//Shift register declaration
	sc_int<16> taps[5];//same type as the input port (sc_int<16>)
	
									
	//First, in the thread body list out any reset functionality the algorithm should have:
	//Reset Code
	//Reset internal variables
	//Reset Outputs
	//wait
	/* --- */
	//Reset
	outp.write(0);
	wait();	//wait(); wait for one clock cycle, everything from beginning of the thread to first wait statement will become a reset state in generated RTL
	//Put all the thread functionality in a continuous while loop
	while (true) {
		//Read inputs
		//Algorithm code
		//Write outputs
		//wait
		/* --- */
		//FIR filter has an array of input port which is read by a shift register, so we need to declare one.
		for (int i = 4; i > 0; i--) { //backward assingmnet like this ensures no tap values are overwritten. we are shifting them before we read.
			taps[i] = taps[i - 1];	
		}
		taps[0] = inp.read();

		//multiply accumulate part of FIR module
		sc_int<16> val;
		for (int i = 0; i < 5; i++) {
			val += coef[i] * taps[i];
		}
		outp.write(val);
		wait();	//wait one cycle and repeat
	}
}
