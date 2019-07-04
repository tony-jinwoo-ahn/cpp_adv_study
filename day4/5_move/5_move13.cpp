#include <iostream>

template<typename T, typename U> struct pair
{
	T first;
	U second;
	//pair(const T& a, const T& b) : first(a), second(b) {}; // const는 move를 못 받는다!
	template <typename A = T, typename B = U> // 안 주면 T, U 를 디폴트로 해서 추론하라.
	pair(A&& a = A(), B&& b = B()) // 인자 안주면, A(), B()를 디폴트로 추론하라.
		: first(std::forward<A>(a))
		, second(std::forward<B>(b)) {}
};

int main()
{
	int x, y;
	pair<int, int> p1(std::move(x), std::move(y));
	pair<int, int> p2;
}