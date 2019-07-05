#include <iostream>

void foo(std::initializer_list<int> e)
{
}

int main()
{
	// initializer_list : 메모리에 연속적으로 놓인 동일 타입의 객체를 관리하는 도구
	std::initializer_list<int> s = { 1,2,3,4,5,6,7 };

	foo(s);
	foo({1,2,3,4,5,6,7}); // ok

	auto p = s.begin();
	std::cout << *p << std::endl;
}
