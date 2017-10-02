// lab-1-2b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sink.h"
#include "source.h"

SC_MODULE(Top) {
public:
	sc_fifo<char> fifo;
	sc_in<bool> clk;
	source src;
	sink snk;

	SC_CTOR(Top) : src("source1"), snk("sink1"), fifo("fifo", 5) {
		src.out(fifo);	//src.out stands for "sourceFifoOut"
		snk.in(fifo);
		src.clock(clk);
		snk.clock(clk);
	}
};

int sc_main(int argc, char *argv[])
{

	sc_clock TestClk("TestClock", 10, SC_NS, 0.5);

	Top topModule("top1");
	topModule.clk(TestClk);
	/*
	Channel *mychan;
	mychan = new Channel("mychan1");
	source *mysrc;
	mysrc = new source("mysrc1");
	sink *mysnk;
	mysnk = new sink("mysnk1");
	*/
	/* Since mychan is a pointer to Channel object, it should be passed as a pointer to port */
	/*mysrc->out(*mychan);	//mysrc->out(mychan) wouldn't work.
	mysnk->in(*mychan);
	mysrc->clock(TestClk);
	mysnk->clock(TestClk);
	*/
	sc_start();

	//sc_start(100, SC_NS);
	return 0;
}

