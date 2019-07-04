#include <iostream>
#include <type_traits>

class Empty {};
/*
template<typename T, typename U> struct PAIR
{
	T v1;
	U v2;
	T& getValue1() { return v1; }
	U& getValue2() { return v2; }

	template<typename A, typename B>
	PAIR(A&& a, B&& b)
		: v1(std::forward<A>(a))
		, v2(std::forward<B>(b)) {}
	PAIR() = default; // PAIR() {} 이거랑 비슷한 뜻이다
};
*/
template<typename T, typename U> struct PAIR : public T
{
	U v2;
	T& getValue1() { return *this; }
	U& getValue2() { return v2; }

	template<typename A, typename B>
	PAIR(A&& a, B&& b)
		: T(std::forward<A>(a)) // 기반 클래스 생성자 호출
		, v2(std::forward<B>(b)) {}
	PAIR() = default; // PAIR() {} 이거랑 비슷한 뜻이다
};
int main()
{
	PAIR<Empty, int> p;
	std::cout << sizeof(p) << std::endl;

	PAIR<int, Empty> p2; // ???

}