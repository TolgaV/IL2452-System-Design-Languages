#include "stdafx.h"
#include "monitor.h"

void monitor::prc_monitor() {
	cout << "AT" << sc_simulation_time() << "input is :";
	cout << m_a << ", " << m_b << "output is :" << m_c << endl;
}