#include <iostream>
#include <type_traits>

// 방법 1. truetype/falsetype 이용 함수 오버로딩
template<typename T> void
printv_imp(T v, std::true_type)
{
	std::cout << v << " : " << *v << std::endl;
}
template<typename T> void
printv_imp(T v, std::false_type)
{
	std::cout << v << std::endl;
}
template<typename T>
void printv(T v)
{
	printv_imp(v, std::is_pointer<T>());
}
int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}
