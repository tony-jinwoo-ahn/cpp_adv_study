#include <iostream>

template<typename T, 
	int N,
	template<typename> class AT>
class Test
{
	AT a; // error. AT�� Ÿ���� �ƴ� ���ø� �Դϴ�.
	AT<T> ax;
};

template<typename T, template<typename> class AT> class List
{
	struct Node {};

//	AT ax; // error. AT�� ���ø�
//	AT<T> ax; // MyAlloc<int>
	AT<Node> ax; // MyAlloc<Node>
};

Test<int, 10, MyAlloc >


template<typename T> struct MyAlloc {};

/*
template<typename T, typename Ax> 
class List
{
	// Node�� Allocator�� �ʿ�!
};
*/


int main()
{
	List<int, MyAlloc<int>> s;
}