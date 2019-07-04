#include <iostream>

// 핵심 1. 함수 호출시 어떤 함수를 호출하는지는 인자만 가지고 결정.
//			반환 타입은 관련 없다.

template <typename T>
typename T::type foo(T n) { std::cout << "T" << std::endl; return 0; }
// int::type foo(int n) {} 함수를 생성하려고 한다.

void foo(...) { std::cout << "..." << std::endl; }


int main()
{	
	foo(10);
}
