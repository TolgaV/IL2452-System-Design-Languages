// file name = testbench.cpp
#include "stdafx.h"
#include"testbench.h"

void driver::prc_drive() {
	char arr[27] = "abcdefghijklmnopqrstuvwxyz";
	int i;
	while (1) {
		for (i = 0; i<26; i++) {
			d_char1.write(arr[i]);
			d_char2.write(arr[i]);
			
			/* Explanation of the behavior */
			//Since we do not have any time related statement after commenting wait out
			//SystemC is not advancing the time, it even isn't advancing delta cycle.
			//Instead immediate notification occurs during evaluate update paradox here.
			//See also "SystemC Simulation Cycle"
			//cout << i;
			cout << "Simulation time is: " << sc_simulation_time<< "\n";
			cout << "Delta Cycle count is: " << sc_delta_count << "\n";
			
			//Required to advance time.
			wait(25, SC_NS);

			// delay in order to see the output.
			for (int i = 0; i < 100000000; i++);// { cout << "xxx"; };
		}

	}
}

void monitor::prc_monitor() {

	cout << "AT " << sc_simulation_time() << " UART output is : " << m_char << endl;
}