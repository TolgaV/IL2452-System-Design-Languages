//fir.cpp
//main process of the FIR module, 
//it reads inputs to taps
//then runs the algorithm
//finally writes the outputs
#include "stdafx.h"
#include <systemc.h>
#include "fir.h"

void Fir::fir_main(){
	
	sc_int<16> taps[5];
	//Reset
	outp.write(0);
	wait();
	
	while (true) {
		//Read Inputs
		for (int i = 5 - 1; i > 0; i--) {
			taps[i] = taps[i - 1];
		}
		taps[0] = inp.read();

		//Algorithm
		sc_int<16> val;
		for (int i = 0; i < 5; i++) {
			val += coef[i] * taps[i];
		}
		//Write Output
		outp.write(val);
		wait();
	}
}