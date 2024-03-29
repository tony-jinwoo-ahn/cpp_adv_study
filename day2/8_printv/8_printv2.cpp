#include <iostream>
#include <type_traits>

// 방법2. enable_if 사용하는 방법

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

