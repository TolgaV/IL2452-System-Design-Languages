// lab-1-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "testbench.h"
#include "arbiter.h"
#include "uart.h"
#include "bus.h"
#include "filter.h"
#include "change-case.h"

SC_MODULE(Top) {
public:
	sc_fifo<char> M1toM4, M2toM4, M4toM5;
	//sc_fifo<char> M5toT2; //,T1toM1, T1toM2;
	sc_signal<char> T1toM1, T1toM2;
	sc_signal<char> M5toT2;
	sc_signal<bool> M3toM4;
	sc_in<bool> clk;

	Arbiter arbtr;// {"Arbiter1"};
	Uart rt;// { "UART1" };
	Bus b;// { "Bus1" };
	Filter fltr;// { "Filter1" };
	ChangeCase chng;// { "ChangeCase1" };
	//Testbench
	driver drvr;// { "Driver1" };
	monitor mntr;// { "Monitor1" };


	SC_CTOR(Top) :arbtr("Arbiter1"), rt("UART1"), b("Bus1"), fltr("Filter1"), chng("Changer1"), 
		drvr("Driver1"), mntr("Monitor1")
		// : M1toM4("fifo1", 5), M2toM4("fifo2", 5), M4toM5("fifo3", 5),
		//T1toM1("fifo4", 5), T1toM2("fifo5", 5), M5toT2("fifo6", 5), M3toM4("fifo6", 5){
		//src("source1"), snk("sink1"), fifo("fifo", 5) {
	{
		//ARBITER
		arbtr.clock(clk);
		arbtr.select(M3toM4);	//bool
		//UART
		rt.clock(clk);
		rt.input(M4toM5);
		rt.output(M5toT2);
		//BUS
		b.clock(clk);
		b.inM1(M1toM4);
		b.inM2(M2toM4);
		b.inM3(M3toM4);			//bool
		b.outM5(M4toM5);
		//FILTER
		fltr.clock(clk);
		fltr.in(T1toM2);
		fltr.out(M2toM4);
		//CHANGE-CASE
		chng.clock(clk);
		chng.in(T1toM1);
		chng.out(M1toM4);
		//DRIVER
		drvr.d_char1(T1toM1);
		drvr.d_char2(T1toM2);
		//MONITOR
		mntr.m_char(M5toT2);

	}
};

int sc_main(int argc, char *argv[])
{
	sc_clock TestClk("TestClock", 10, SC_NS, 0.5);

	Top topModule("top1");
	topModule.clk(TestClk);
	sc_start();


    return 0;
}