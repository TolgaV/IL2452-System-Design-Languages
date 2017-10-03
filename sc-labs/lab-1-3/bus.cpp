#include "stdafx.h"
#include "bus.h"

void Bus::mux() {
	while (true) {
		wait();
		inM1->read(c1);
		inM2->read(c2);
		sel = inM3->read();
		if (sel == 0) {
			cOut = c1;
		}
		else if (sel == 1) {
			cOut = c2;
		}
		else {
			cout << endl << "Select Signal Unavailable" << endl;
		}
		outM5->write(cOut);
	}
}