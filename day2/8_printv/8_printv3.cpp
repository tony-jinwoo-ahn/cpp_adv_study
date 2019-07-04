#include <iostream>
#include <type_traits>

// 방법 3. constexpr - cpp17 style
// cppreference.com 에서 invoke 찾아보기
// possible implementation 참고하기

template<typename T>
void printv(T v)
{
	if constexpr (std::is_pointer<T>::value) {
		std::cout << v << " : " << *v << std::endl;
	}
	else {
		std::cout << v << std::endl;
	}	
}
int main()
{
	std::cout << "cpp 17 style! \n";
	int n = 0;
	printv(n);
	printv(&n);
}
