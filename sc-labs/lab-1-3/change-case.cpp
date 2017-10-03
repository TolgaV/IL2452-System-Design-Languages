#include "stdafx.h"
#include "change-case.h"
#include <cctype>

void ChangeCase::upCase() {
	while (true) {
		wait();					//wait until clock's positive edge
		//in->read(c);			//read a character from FIFO port
		c = in->read();
		c = (char)toupper(c);	//convert character to upper case
		e1.notify();
		wait(e2);
	}
}

void ChangeCase::toBus() {
	while (true) {
		wait(e1);
		out->write(c);
		e2.notify();
	}
}