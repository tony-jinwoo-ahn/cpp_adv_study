#include <iostream>
#include <functional>

using namespace std::placeholders;

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d \n", a, b, c, d);
}

int main()
{
	void(*f1)(int); // 인자가 한개인 함수 주소만 담을 수 있다.

	// cpp11에서 추가된 함수포인터 역할의 템플릿
	// 주로 bind 와 같이 사용한다.
	std::function<void(int)> f;

	//f = &foo;
	f = std::bind(&foo, _1, 0, 0, 0);
	f(10); // 10, 0, 0, 0

//	f = std::bind(&goo, _1, "테스트용");
}

// 콜백에서 다양한 개수의 인자를 받을 수 있는 유연성.
