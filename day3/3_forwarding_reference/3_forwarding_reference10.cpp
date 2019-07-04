#include <iostream>

// pair: 2개의 값을 보관하는 구조체
template <typename T, typename U> 
struct pair
{
	T first;
	U second;

	// 생성자 모양 1: call by value => 복사본에 의한 성능 저하
	// pair(T a, U b) : first(a), second(b) {}

	// 생성자 모양 2: non const lvalue reference
	// pair(T& a, U& b) : first(a), second(b) {}

//	 생성자 모양 3: const lvalue reference
	 //pair(const T& a, const U& b) : first(a), second(b) {}

	// 생성자 모양 4 : cpp11 이후 스타일
	template<typename A, typename B>
	pair(A&& a, B&& b)
		: first(std::forward<A>(a))
		, second(std::forward<B>(b)) {}
};

int main()
{
	int a = 10, b = 20;
	pair<int, int> p1(10, 20);
	pair<int, int> p2(a, b);
//	pair<int&, int&> p3(a, b);

	pair<int&&, int&&> p4(10, 20);

	std::pair<int, double> p5;
}

// webkit source/wtf/wtf scope.h
//https://github.com/WebKit/webkit/blob/master/Source/WTF/wtf/Scope.h
// ScopeExit() 생성자

