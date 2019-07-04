#include <iostream>
#include <type_traits>

// 规过2. enable_if 荤侩窍绰 规过

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

