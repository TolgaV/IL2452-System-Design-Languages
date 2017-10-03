#include "stdafx.h"
#include "arbiter.h"

void Arbiter::arbitrate() {
	for (;;) {
		wait();
		select->write(sel);
		if (sel == 0)
			sel = 1;
		else if (sel == 1)
			sel = 0;
		else
			cout << endl << "Select has wrong value" << endl;
	}
}