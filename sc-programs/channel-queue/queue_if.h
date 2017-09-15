#pragma once
/* Queue Interface header file */
#include "stdafx.h"
#include "systemc.h"

/* Step 1: Declare an abstract interface class
-derived from sc_interface
-use Virtual inheritance to allow multiple inheritance without
multiple inclusion of the base class members
-pure virtual functions because it is mandatory for users
to supply the implementation
*/

class queue_write_if : virtual public sc_interface {
public:
	virtual void write(int c) = 0;
};

class queue_read_if : virtual public sc_interface {
public:
	virtual int read() = 0;
};

class queue_if: public queue_write_if, public queue_read_if{};

/* Step 2: Channel Implementation
-Declare the queue class as our own channl
-the interface class is declared but does nothing
-it is the channel's responsibility to override th
pure virtual methods and describe functionality
-Derived from sc_object
-Since the queue channel is neither a hierarchical
nor a primitive channel, it is recommended that such
channels are at least derived from sc_object so that
they own attributes such as a hierarchical name and a
position in the module hierarchy.
-sc_object is the base class for all objects in the
module hierarchy!
*/
class Queue : public queue_if, public sc_object {
public:
	Queue(char *_nm, int _size)
		: sc_object(_nm), size(_size) {
		data = new int[size];
		w = r = n = 0;
	}

	void write(int c);
	int read();

private:
	int *data;
	int size, w, r, n;
};