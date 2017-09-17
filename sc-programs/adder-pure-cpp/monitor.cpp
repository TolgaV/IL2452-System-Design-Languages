#include "stdafx.h"
#include "monitor.h"

void Monitor::watcher() {
	cout << " At " << sc_simulation_time() << " input is : ";
	cout << a << " , " << b << " output is : " << c << endl;
}


Monitor::Monitor(sc_module_name _name)
	:sc_module(_name) {
	SC_METHOD(watcher);
	sensitive << a, b, c;
}