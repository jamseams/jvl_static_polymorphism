#pragma once

template<bool T1, bool T2, bool T3>
class CounterClass
{




	template<T1>
	increaseCount1();

	template<T2>
	increaseCount1();
	
	template<T3>
	increaseCount1();

private:
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
};