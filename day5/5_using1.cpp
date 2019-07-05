// 5_using
#include <iostream>
#include <type_traits>

/*
// cpp14 부터 아래 코드를 제공합니다
template <typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;

// variable template 이라는 문법 
template<typename T>
bool is_pointer_v = std::is_pointer<T>::value;
*/


template <typename T>
void foo(T a)
{
	
//	bool b = std::is_pointer<T>::value;
	bool b = std::is_pointer_v<T>;

//	typename std::remove_pointer<T>:type t;
	remove_pointer_t<T> t;
}

int main()
{
	int n;
	foo(&n);
}
