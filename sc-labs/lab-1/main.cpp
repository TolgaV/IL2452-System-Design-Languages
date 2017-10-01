#include "stdafx.h"
#include "testbench.h"
#include "or-gate.h"
#include "monitor.h"

int sc_main(int argc, char *argv[]) {
	
	sc_signal<sc_bit> t_a;
	sc_signal<sc_bit> t_b;
	sc_signal<sc_bit> t_c;

	or_gate *g1;
	g1 = new or_gate("Gate1");
	driver *d1;
	d1 = new driver("Driver1");
	monitor *m1;
	m1 = new monitor("Monitor1");

	//or_gate orgt("Gate2");
	//driver drvr("Driver2");
	//monitor mntr("Monitor2");
	
	/* Name Based Port to Channel Binding*/
	
	g1->a(t_a);
	g1->b(t_b);
	g1->c(t_c);

	d1->d_a(t_a);
	d1->d_b(t_b);

	m1->m_a(t_a);
	m1->m_b(t_b);
	m1->m_c(t_c);

	/* Position Based Port to Channel Binding */
	
	//orgt(t_a, t_b, t_c);
	//drvr(t_a, t_b);
	//mntr(t_a, t_b, t_c);



	//Start and run the simulation for 100 ns
	sc_start(100, SC_NS); 
	//Return on success
	return 0;

}