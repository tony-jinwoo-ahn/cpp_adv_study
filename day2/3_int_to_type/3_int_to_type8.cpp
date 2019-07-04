#include <iostream>
#include <type_traits>
using namespace std;

//  포인터 여부에 따라 다르게 처리하는 방법

// 1. cpp17 이 나오기 전까지.
template<typename T> void foo_imp(T v, true_type) {}
template<typename T> void foo_imp(T v, false_type) {}

/*
template<typename T> void foo(T v)
{
	//1. is_pointer<T>::value 사용
	if (std::is_pointer<T>::value)
	{
		// 단, 아래와 같은 표현식은 사용불가.
		*v = 10; // error. if문 내부가 거짓이 되더라도 컴파일 되므로.
	}
	else
	{
	}
	// 2. true_type / false_type 사용한 오버로딩
	// foo_imp 안에서는 *v = 10 사용가능.
	foo_imp(v, is_pointer<T>());

}
*/

// 2. enable_if 사용
// 추후 계속...

// 3. cpp17 이후에는 true_type, false_type 몰라도됨! constexpr 쓰면됨.
// /std:c++17
// g++ : g++ 소스이름.cpp -std=c++17
template<typename T> void foo(T v)
{
	// if constexpr : 컴파일시간 if문
	// 조건이 거짓일 경우 코드 자체를 생성하지 않는다.
	if constexpr (std::is_pointer<T>::value)
	{
		//*v = 10;
		std::cout << v << " : " << *v << std::endl;
	}
	else
	{
		std::cout << v << std::endl;
	}
}

int main()
{
	int n = 999;
	foo(n);
	foo(&n);
}
