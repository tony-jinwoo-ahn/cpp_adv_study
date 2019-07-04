// 함수 오버로딩으로 해결하자

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
	// T가 포인터인지에 따라 다른 함수를 호출하게 한다.
	printv_imp(a, std::is_pointer<T>::value);
}
int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}
