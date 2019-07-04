#include <iostream>

/*
template <typename T>
void foo(T n)
{
	typename T::type n; // 1. SFINAE가 적용될까?
						// 2. 컴파일 에러일까? - 답.
}
*/

// SFINAE 가 적용되는 위치 3곳. (함수 signature)
// 1. 함수 반환값 - 가장 많이 사용되는 기술.
template<typename T> typename T::type foo(T n) {}

// 2. 함수 인자타입 - 생성자와 같이 반환 타입이 없는 곳에서
//						SFINAE 를 사용하고 싶을 때.
template<typename T> void foo(T n, typename T::type n2) {}

// 3. 템플릿 인자 - 함수의 모양이 복잡해지지 않는 특징이 있다.
template<typename T, typename T2 = typename T::type>
void foo(T n) {}

void foo(...) { std::cout << "..." << std::endl; }

int main()
{
	foo(10);
}
