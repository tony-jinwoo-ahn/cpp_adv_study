#include <iostream>

// 인자로 T 만 받으면 call by value 이니까 안좋다!
//template<typename T> void foo(const T& f)
template<typename T> void foo(T&& f) // forwarding reference를 써야 다 받는다! 다 받고싶다! 이게 정답.
{
	//f();
	std::forward<T>(f)();
}
void goo() { std::cout << "goo" << std::endl; }

int main()
{
	foo(goo);
	// 람다 표현식은 rvalue 입니다.
	// mutable 람다표현식: () 연산자 함수를 비상수 멤버 함수로 해달라는 의미.
	foo( []() mutable {std::cout << "lambda" << std::endl; } );
}
