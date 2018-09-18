#include <iostream>
#include <vector>
#include "staticpoly.h"

int main()
{

	std::cout << "hello, world" << std::endl;

	CounterClass<true, true, false> myOnOnOff;

	myOnOnOff.increaseCount1();
	myOnOnOff.increaseCount1();
	myOnOnOff.increaseCount2();
	myOnOnOff.increaseCount2();
	myOnOnOff.increaseCount3();
	myOnOnOff.increaseCount3();
	myOnOnOff.printOut();


	
	CounterWrapper myCounter(true, true, false);

	myCounter.test();


	CounterWrapper myCounter2(false, false, false);

	myCounter2.test();

	getchar();
}
