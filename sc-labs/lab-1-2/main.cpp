// lab-1-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "channel.h"
#include "source.h"
#include "sink.h"
//class Top: public hchan, public sink, public source/*
class Top : public sc_module, public Hchan {
public:
	sc_signal<w_if> sig_1;
	sc_signal<r_if> sig_2;
	sc_clock clk_sig;

	Hchan *chan;
	source *src;
	sink *snk;


	Top(sc_module_name name) :sc_module(name){

		sc_clock theclock("theClock", 10, SC_NS);
		//Hchan *chan;
		chan = new Hchan("channel1");
		//source *src;
		src = new source("source1");
		//sink *snk;
		snk = new sink("sink1");

		src->out(chan->input);
		src->clock(theclock);
		snk->in(chan->output);
		snk->clock(theclock);
		chan->clock(theclock);
		//src = new source("source1");
		//snk = new sink("sink1");
	}
	SC_HAS_PROCESS(Top);
};

int sc_main(int argc, char *argv[])
{
	//sc_signal<w_if> sig1;
	//sc_signal<r_if> sig2;


	Top topmodule("TOP");
	sc_start();
	return 0;
}
	

/*
	hchan channel1("Channel1");
	source source1("Source1");
	sink sink1("Sink1");
	source1.out(channel1.in_chan);
	source1.clock(theclock);
	sink1.in(channel1.out_chan);
	sink1.clock(theclock);
	channel1.clock(theclock);
	sc_start(100, SC_NS);*/
//	system("pause");
  //  return 0;/
//}

