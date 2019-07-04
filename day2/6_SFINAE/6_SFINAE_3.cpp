#include <iostream>

/*
template <typename T>
void foo(T n)
{
	typename T::type n; // 1. SFINAE�� ����ɱ�?
						// 2. ������ �����ϱ�? - ��.
}
*/

// SFINAE �� ����Ǵ� ��ġ 3��. (�Լ� signature)
// 1. �Լ� ��ȯ�� - ���� ���� ���Ǵ� ���.
template<typename T> typename T::type foo(T n) {}

// 2. �Լ� ����Ÿ�� - �����ڿ� ���� ��ȯ Ÿ���� ���� ������
//						SFINAE �� ����ϰ� ���� ��.
template<typename T> void foo(T n, typename T::type n2) {}

// 3. ���ø� ���� - �Լ��� ����� ���������� �ʴ� Ư¡�� �ִ�.
template<typename T, typename T2 = typename T::type>
void foo(T n) {}

void foo(...) { std::cout << "..." << std::endl; }

int main()
{
	foo(10);
}
