#include "stdafx.h"
#include "filter.h"

void Filter::filterIt() {
	while (true) {
		wait();					//wait until clock's positive edge
		//in->read(c);			//read a character from FIFO port
		c = in->read();			//read a character from FIFO port

		if ((c == 's') | (c == 'y') | (c == 't') | (c == 'e') | (c == 'm') | (c == 'c')) {
			c = '#';
		}
		else {

		}
		e1.notify();
		wait(e2);
	}
}

void Filter::toBus() {
	while (true) {
		wait(e1);
		out->write(c);
		e2.notify();
	}
}