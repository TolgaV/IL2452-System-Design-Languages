// channel-queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "queue_if.h"
// Testing functionality of module for the queue
// we use port-less channel access: accessingt the channel without declaring ports
class Test : public sc_module {			//class in c++ style is working but constructor in c++ style not working
public:
	Queue queue;
	SC_CTOR(Test) : queue("queue", 10) {
		SC_THREAD(testing);
	}
	void testing() {
		//port-less channel access
		for (int i = 0; i<10; i++)
			queue.write(i);
		//port-less channel access
		for (int i = 0; i<10; i++)
			std::cout << queue.read();
	}
};

Test *t = NULL;


int sc_main(int argc, char* argv[])
{
	t = new Test("top");
	sc_start();
	system("pause");
	return 0;
}