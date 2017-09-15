#include "stdafx.h"
#include "queue_if.h"
/* With the same interface declaration, definitions may be different */
//Definition of write function
void Queue::write(int c) {
	if (n < size) {
		n++;
		data[w++] = c;
		if (w == size) w = 0;
	}
}
//Definition of read function
int Queue::read() {
	int c = 0;
	if (n > 0) {
		n--;
		c = data[r++];
		if (r == size)r = 0;
	}
	return c;
}
