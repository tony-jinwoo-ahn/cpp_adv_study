

#include <iostream>
#include <string>
#include <vector>


class Test
{
	int data;
	std::string s = "hello";
public:
	Test() {}
	~Test() {}
	Test(const Test& t) : data(std::move(t.data)), s(std::move(t.s))
	{
		std::cout << __FUNCSIG__ << std::endl;
	}
	Test& operator=(const Test& t) {
		data = t.data;
		s = std::move(t.s);

		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}

	

	Test(Test&& t) noexcept (
		std::is_nothrow_move_constructible<std::string>::value)
		: data(t.data), s(std::move(t.s))
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	Test& operator=(Test&& t) noexcept (
		std::is_move_assignable<std::string>::value)
	{
		data = t.data;
		s = std::move(t.s);
		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}
};

// move와 알고리즘
// move에서 알아야 하는 것
// 1. 클래스 만들 때 move 계열 함수 2개를 만드는 법
// 2. 일반 알고리즘 구현할 때 move() 를 사용해서 
//    옮기는 것이 빠른 경우가 있다.

template<typename T> void Swap(T& a, T& b)
{
	/*
	잘못 만든 스왑이다. 복사를 쓰고 있다.
	T tmp = a;
	a = b;
	b = tmp;
	*/

	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);

}

int main()
{
	Test t1, t2;
	Swap(t1, t2);
}
