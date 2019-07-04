#include <iostream>
#include <type_traits>
/*
template <typename T> T gcd(T arg1, T arg2)
{
	// 최대공약수를 반환한다고 가정.
	// 정수가 아닌경우 실패하게 하고싶다.
	// static_assert : 1번째 인자가 false이면 컴파일 중지
	static_assert(std::is_integral<T>::value, "not integral");

	return 0;
}
*/

// static_assert: 조건을 만족 못하면 무조건 에러.
// enable_if:     조건을 만족 못하면 템플릿 사용하지 않음.
//	   			  동일 이름의 다른 함수가 있으면 사용가능.

template <typename T> 
typename std::enable_if<std::is_integral<T>::value, T>::type
gcd(T arg1, T arg2)
{
	std::cout << "T.T" << std::endl;
	return 0;
}

// double 버전의 함수 제공한다치자
double gcd(double arg1, double arg2)
{
	std::cout << "double" << std::endl;
	return 0;
}

int main()
{
	gcd(10, 6);
	gcd(3.4, 2.4);
}