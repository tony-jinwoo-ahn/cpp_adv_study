// �Լ� �����ε����� �ذ�����

#include <iostream>
#include <type_traits>

template <typename T> void printv_imp(T v, YES)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}
template <typename T> void printv_imp(T v, NO)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}
/*
template <typename T> void printv_imp_pointer(T v)
{
	std::cout << "Not pointer" << std::endl;
	std::cout << v << std::endl;
}
*/

template <typename T> void printv_imp_not_pointer(T v)
{
	std::cout << "Not pointer" << std::endl;
	std::cout << v << std::endl;
}

template <typename T> void printv(T a)
{
	// T�� ������������ ���� �ٸ� �Լ��� ȣ���ϰ� �Ѵ�.
	printv_imp(a, std::is_pointer<T>::value);
}
int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}
