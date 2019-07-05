#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_pointer<T>::value, int>::type
foo0(T a)
{}
// 위 코드를 _t 와 _v 버전을 사용해서 변경해 보세요

// 1. 함수 반환타입을 이용한 SFINAE
template<typename T>
std::enable_if_t<std::is_pointer_v<T>, int>
foo(T a)
{}

// 2. 함수 인자를 사용한 SFINAE
template<typename T>
int
goo(T a, std::enable_if_t<std::is_pointer_v<T>, int> = 0) // 어차피 쓸거 아니니까 = 0 해놓자
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
