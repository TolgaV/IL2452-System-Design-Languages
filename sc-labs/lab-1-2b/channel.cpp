#include "stdafx.h"
#include "channel.h"


void Channel::write(char c) {
	temp = c;
	cout << "Written value is " << temp << endl;
}

void Channel::read(char &c) {
	c = temp;
	cout << "Read value is " << temp << endl;
}

void Channel::register_port(sc_port_base& port_,
	const char* if_typename_)
{
	cout << "binding    " << port_.name() << " to "
		<< "interface: " << if_typename_ << endl;
}