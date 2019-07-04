#include <iostream>

template<typename T, typename U> struct pair
{
	T first;
	U second;
	//pair(const T& a, const T& b) : first(a), second(b) {}; // const�� move�� �� �޴´�!
	template <typename A = T, typename B = U> // �� �ָ� T, U �� ����Ʈ�� �ؼ� �߷��϶�.
	pair(A&& a = A(), B&& b = B()) // ���� ���ָ�, A(), B()�� ����Ʈ�� �߷��϶�.
		: first(std::forward<A>(a))
		, second(std::forward<B>(b)) {}
};

int main()
{
	int x, y;
	pair<int, int> p1(std::move(x), std::move(y));
	pair<int, int> p2;
}