#include <iostream>
#include <type_traits>

using namespace std;

/*

//int2type을 발전시켜 cpp11 표준에 추가된 템플릿
template<typename T, T N> struct integral_constant
{
	// enum {value=N}; // cpp11 이전 스타일. 예전에 유일하게 컴파일타임에 만들수있는 상수.

	static constexpr T value = N; // cpp11 이후 스타일
									// constexpr 을 사용한 컴파일시간 상수.

문제: 정수형상수를 타입으로 바꾸는 cpp표준은? 
답:   integral_constant
};

integral_constant<int, 0> t0;
integral_constant<int, 1> t1;
integral_constant<short, 1> s1;

integral_constant<bool, true> b0;
integral_constant<bool, false> b1;

// true/false			: 참, 거짓을 나타내는 값.   같은 타입.
// true_type/false_type : 참, 거짓을 나타내는 타입. 다른 타입.
typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

// cpp 표준의 is_pointer는 아래처럼 만들었습니다.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};

*/


template <typename T> void printv_imp(T v, std::true_type)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}
template <typename T> void printv_imp(T v, std::false_type)
{
	std::cout << "Not pointer" << std::endl;
	std::cout << v << std::endl;
}

template <typename T> void printv(T a)
{
	printv_imp(a, std::is_pointer<T> ());
	// 클래스이름() : 임시로 사용할 객체 생성
}

int main()
{
	int n = 999;
	printv(n);
	printv(&n);
}
