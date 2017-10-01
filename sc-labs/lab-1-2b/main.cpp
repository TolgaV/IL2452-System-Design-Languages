// lab-1-2b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "channel.h"
#include "sink.h"
#include "source.h"

int sc_main(int argc, char *argv[])
{

	sc_clock TestClk("TestClock", 10, SC_NS, 0.5);

	Channel *mychan;
	mychan = new Channel("mychan1");
	source *mysrc;
	mysrc = new source("mysrc1");
	sink *mysnk;
	mysnk = new sink("mysnk1");

	/* Since mychan is a pointer to Channel object, it should be passed as a pointer to port */
	mysrc->out(*mychan);	//mysrc->out(mychan) wouldn't work.
	mysnk->in(*mychan);
	mysrc->clock(TestClk);
	mysnk->clock(TestClk);
	sc_start(100, SC_NS);
    return 0;
}

