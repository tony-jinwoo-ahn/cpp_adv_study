#include <iostream>
#include <type_traits>

// ���2. enable_if ����ϴ� ���

template<typename T>
typename std::enable_if< std::is_pointer<T>::value >::type
printv(T v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T>
typename std::enable_if< !std::is_pointer<T>::value >::type
printv(T v)
{
	std::cout << v << std::endl;
}
int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}

