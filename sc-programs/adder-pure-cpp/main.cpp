#include "stdafx.h"
#include "top.h"

Top::Top(sc_module_name _name)
	:sc_module(_name) {

	/* Design Under Test(DUT) instantiation */
	dut_inst = new Adder("adder1");
	/* Port to Channel Binding (sc_signal is a primitive channel) */
	dut_inst->a(siga);
	dut_inst->b(sigb);
	dut_inst->c(sigc);

	/* Monitor instantiation */
	mon_inst = new Monitor("monitor1");
	/* Port to Channel Binding */
	mon_inst->a(siga);
	mon_inst->b(sigb);
	mon_inst->c(sigc);
	mon_inst->clock(testclk);

	/* Stimulus instantiation */
	stim_inst = new Stimulus("stimulus1");
	/* Port to Channel Binding */
	stim_inst->a(siga);
	stim_inst->b(sigb);
	stim_inst->clock(testclk);
};

Top *top_module = NULL;

int sc_main(int argc, char* argv[]) {
	top_module = new Top("top1");

	sc_start();
	system("pause");
	return 0;
}