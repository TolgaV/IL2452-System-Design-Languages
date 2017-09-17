#include "stdafx.h"
#include "monitor.h"

void Monitor::watcher() {
	std::cout << " At " << sc_simulation_time() << " input is : ";
	std::cout << a << " , " << b << " output is : " << c << endl;
}

/* Monitor only has to be sensitive to output in order for not to
print duplicate stuff everytime something changes */
Monitor::Monitor(sc_module_name _name)
	:sc_module(_name) {
	SC_METHOD(watcher);
	sensitive << c;//a, b, c, clock.pos();
}