#include <iostream>

template<typename T, 
	int N,
	template<typename> class AT>
class Test
{
	AT a; // error. AT는 타입이 아닌 템플릿 입니다.
	AT<T> ax;
};

template<typename T, template<typename> class AT> class List
{
	struct Node {};

//	AT ax; // error. AT는 템플릿
//	AT<T> ax; // MyAlloc<int>
	AT<Node> ax; // MyAlloc<Node>
};

Test<int, 10, MyAlloc >


template<typename T> struct MyAlloc {};

/*
template<typename T, typename Ax> 
class List
{
	// Node의 Allocator가 필요!
};
*/


int main()
{
	List<int, MyAlloc<int>> s;
}