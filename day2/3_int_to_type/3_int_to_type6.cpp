#include <iostream>
#include <type_traits>

template<int N> struct my_int2type
{
	enum { value = N };
};

template <typename T> void printv_imp(T v, my_int2type<1> /* �������� ��������. ����ȭ �ߵǰ�. */) 
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}
template <typename T> void printv_imp(T v, my_int2type<0>)
{
	std::cout << "Not pointer" << std::endl;
	std::cout << v << std::endl;
}

template <typename T> void printv(T a)
{	
	printv_imp( a, my_int2type<std::is_pointer<T>::value>() );
}
// int2type<0> : �̰��� Ÿ���̴�
// int2type<0>() : �̰��� �ӽ� ��ü�̴�.

int main()
{
	int n = 999;
	printv(n);
	printv(&n);
}
