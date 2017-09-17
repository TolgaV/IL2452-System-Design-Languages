//counter.h
#pragma once
#include "stdafx.h"

SC_MODULE(Counter) {
public:
	sc_in<bool> clock, reset;
	sc_out<int> q;

	void count();

	SC_CTOR(Counter): modulo(5), cnt(0) {
		SC_METHOD(count);
		sensitive << clock, reset;
	}
private:
	/* To be initialized by constructor */
	int modulo;
	int cnt;
};

	/* THREAD VERSION */
/*SC_MODULE(Counter) {
public:
	sc_in<bool> clock, reset;
	sc_out<int> q;

	void count();

	SC_CTOR(Counter) : modulo(5), cont(0) {
		SC_THREAD(count);
		sensitive << clock, reset;
	}
private:
	int modulo;
	int cnt;
};*/

	/* PURE C++ VERSION */
/*
class Counter : public sc_module {
public:
	sc_in<bool> clock, reset;
	sc_out<int> q;


	Counter(sc_module_name _name, int _mod, int _cnt);
/*
Possible to move constructor to .cpp file.
Just cut the curly curly bracket region.
		:sc_module(_name), modulo(5), cnt(0) {
		SC_METHOD(count);
		sensitive << clk.pos();
	}
	SC_HAS_PROCESS(name-of-constructor/function)
*//*
	SC_HAS_PROCESS(Counter);

private:
	//Function Members
	void count();
	//Data Members
	const int modulo;
	int cnt;

};
*/