// boost ���̺귯���� "compress_pair"
// cpp ǥ���� unique_ptr ���� �� �� ����� ����
#include <iostream>
#include <type_traits>

class Empty {};

template<typename T,
	typename U,
	bool b = std::is_empty<T>::value> 
struct PAIR;
//{};
// �ᱹ ���� PAIR�� ������� �ʰ� �Ʒ� 2��(false/true)�� ����ϰ� �ȴ�.
// ������� ���� ���� ����ü�� ���� ���� ��.

//------------------------------------------
template<typename T, typename U> 
struct PAIR<T, U, false>
{
	T v1;
	U v2;
	T& getValue1() { return v1; }
	U& getValue2() { return v2; }

	template<typename A, typename B>
	PAIR(A&& a, B&& b)
		: v1(std::forward<A>(a))
		, v2(std::forward<B>(b)) {}
	PAIR() = default;
};

template<typename T, typename U> 
struct PAIR<T, U, true> : public T
{
	U v2;
	T& getValue1() { return *this; }
	U& getValue2() { return v2; }

	template<typename A, typename B>
	PAIR(A&& a, B&& b)
		: T(std::forward<A>(a))
		, v2(std::forward<B>(b)) {}
	PAIR() = default;
};

int main()
{
	PAIR<Empty, int> p; // boost��.
	std::cout << sizeof(p) << std::endl;

	PAIR<int, Empty> p2; // ???
	std::cout << sizeof(p2) << std::endl;
}
