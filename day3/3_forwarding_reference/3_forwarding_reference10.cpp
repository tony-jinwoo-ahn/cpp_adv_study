#include <iostream>

// pair: 2���� ���� �����ϴ� ����ü
template <typename T, typename U> 
struct pair
{
	T first;
	U second;

	// ������ ��� 1: call by value => ���纻�� ���� ���� ����
	// pair(T a, U b) : first(a), second(b) {}

	// ������ ��� 2: non const lvalue reference
	// pair(T& a, U& b) : first(a), second(b) {}

//	 ������ ��� 3: const lvalue reference
	 //pair(const T& a, const U& b) : first(a), second(b) {}

	// ������ ��� 4 : cpp11 ���� ��Ÿ��
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
// ScopeExit() ������

