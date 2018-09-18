#pragma once
#include <iostream>

template<bool T1, bool T2, bool T3>
class CounterClass
{
public:
	template<bool M = T1, typename std::enable_if<M>::type* = nullptr>
	void increaseCount1()
	{
		std::cout << "Count1 is true : " << ++count1 << std::endl;
	}

	template<bool M = T1, typename std::enable_if<!M>::type* = nullptr>
	void increaseCount1()
	{
		std::cout << "Count1 is false : " << count1 << std::endl;
	}

	template<bool M = T2, typename std::enable_if<M>::type* = nullptr>
	void increaseCount2()
	{
		std::cout << "Count2 is true : " << ++count2 << std::endl;

	}
	
	template<bool M = T2, typename std::enable_if<!M>::type* = nullptr>
	void increaseCount2()
	{
		std::cout << "Count2 is false : " << count2 << std::endl;
	}

	template<bool M = T3, typename std::enable_if<M>::type* = nullptr>
	void increaseCount3()
	{
		std::cout << "Count3 is true : " << ++count3 << std::endl;

	}

	template<bool M = T3, typename std::enable_if<!M>::type* = nullptr>
	void increaseCount3()
	{
		std::cout << "Count3 is false : " << count3 << std::endl;
	}


	void printOut()
	{
		std::cout << count1 << " " << count2 << " " << count3 << std::endl;
	}

private:
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
};

/*


template<typename Impl>
struct CRTPInterface : CRTPBase
{
	void increaseCount1() { impl().increaseCount1(); }
	void increaseCount2() { impl().increaseCount2(); }
	void increaseCount3() { impl().increaseCount3(); }
	void printOut()		  { impl().printOut(); }

private:
	Impl & impl()
	{
		return *static_cast<Impl*>(this);
	}
}
*/




class CounterWrapper
{
	class CounterConcept
	{
	public:
		virtual void increaseCount1() = 0;
		virtual void increaseCount2() = 0;
		virtual void increaseCount3() = 0;
		virtual void printOut() = 0;
		virtual ~CounterConcept() {};
	};


	template<typename T>
	class CounterModel : public CounterConcept
	{
		T* m_counter;
	public:
		CounterModel(T* counter)
			: m_counter(counter)
		{}

		void increaseCount1() { m_counter->increaseCount1(); }
		void increaseCount2() { m_counter->increaseCount2(); }
		void increaseCount3() { m_counter->increaseCount3(); }
		void printOut() { m_counter->printOut(); }

		//~CounterModel() {}
	};

	template<typename T>
	CounterConcept* createT(T* counter)
	{
		return new CounterModel<T>(counter);
	}

public:
	CounterWrapper(bool b1, bool b2, bool b3)
	{
		if (b1 & b2 & !b3)
		{
			inject = createT ( new CounterClass<true, true, false>());
		}
		else
		{
			inject = createT( new CounterClass<false, false, false>());
		}
	}

	void test()
	{
		inject->increaseCount1();
		inject->increaseCount1();
		inject->increaseCount2();
		inject->increaseCount2();
		inject->increaseCount3();
		inject->increaseCount3();
		inject->printOut();
	}

	~CounterWrapper()
	{
		delete inject;
	}
private:
	CounterConcept* inject;

};


