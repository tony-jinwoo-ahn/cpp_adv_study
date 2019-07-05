#include <iostream>
#include <functional>

using namespace std::placeholders;

void foo(int a, int& b)
{
	b = 100;
}

int main()
{
	std::function<void(int)> f;
	/*
	{
		int n = 0;
		f = std::bind(&foo, _1, n); // n이 아니라 n의 값을 고정(보관)
	} // 블럭을 벗어나는 순간 파괴된다.
	*/
	
	int n = 0;
	f = std::bind(&foo, _1, std::ref(n)); // 참조로 고정해달라

	f(10); // foo(10, n)

	std::cout << n << std::endl; // 얼마 나올까요?
}

