//top.h
#pragma once
#include "stdafx.h"
#include "systemc.h"
#include "stimulus.h"
#include "adder.h"
#include "monitor.h"
SC_MODULE(Top) {
	//Channels
	sc_signal<int> siga, sigb, sigc;
	sc_clock testclk;

	//Module Instantiation
	Stimulus stim;
	Adder dut;			//Design Under Test
	Monitor mon;

	//initializing members using constructor
	SC_CTOR(Top) :testclk("testclk"), stim("stim"), dut("dut"), mon("mon") {
		stim.a(siga);
		stim.b(sigb);
		stim.clk(testclk);		//Name binding

		dut.a(siga);
		dut.b(sigb);
		dut.c(sigc);
		//dut(siga,sigb,sigc)	//Positional binding

		mon.a(siga);
		mon.b(sigb);
		mon.c(sigc);
		mon.clk(testclk);
	}
};

