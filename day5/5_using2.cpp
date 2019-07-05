#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_pointer<T>::value, int>::type
foo0(T a)
{}
// �� �ڵ带 _t �� _v ������ ����ؼ� ������ ������

// 1. �Լ� ��ȯŸ���� �̿��� SFINAE
template<typename T>
std::enable_if_t<std::is_pointer_v<T>, int>
foo(T a)
{}

// 2. �Լ� ���ڸ� ����� SFINAE
template<typename T>
int
goo(T a, std::enable_if_t<std::is_pointer_v<T>, int> = 0) // ������ ���� �ƴϴϱ� = 0 �س���
{
	return 0;
}

template<typename T = double,
		std::enable_if_t<std::is_pointer_v<T>, int> = 0 >
int
hoo(T a)
{
	return 0;
}

int main()
{	
	std::default_delete<int> d;
}
