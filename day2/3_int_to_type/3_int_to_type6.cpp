#include <iostream>
#include <type_traits>

template<int N> struct my_int2type
{
	enum { value = N };
};

template <typename T> void printv_imp(T v, my_int2type<1> /* 변수명은 적지마라. 최적화 잘되게. */) 
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
// int2type<0> : 이것은 타입이다
// int2type<0>() : 이것은 임시 객체이다.

int main()
{
	int n = 999;
	printv(n);
	printv(&n);
}
