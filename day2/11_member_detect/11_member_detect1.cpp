// member detect page 143

#include <iostream>
#include <vector>

// list: 멤버함수 sort() 제공
// vector: 멤버함수 sort()가 없다. 대신에 일반함수 sort()로 보내야 함.

template<typename T>
void foo(T& c)
{
	auto n = c.front();
	// front() 가 있는지부터 조사하고 싶다. 특정한 멤버함수가 있는지.
}
int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);

	//----------------------------------------------------
	// 인터페이스 가상함수 쓰면 느리니까, 이렇게 inline 치환되는 기법으로 빠르게 한다.
	/*
	MyAllocator<int> ax;
	allocator_traits<MyAllocator<int>> at(ax); // 멤버 디텍트 기술 사용
	int n = at.max_size(); // 1. MyAllocator에 max_size가 있으면 내꺼 사용
							// 2. 없으면 allocator_traits의 디폴트 max_size 사용
	*/
}
// cppreference.com 에서 allocator 검색
// allocate, deallocate 등등을 다 구현해야 한다. 그래야 얼로케이터라고 할 수 있다.
//(optional) 이라고 되있으면, 내가 만든 함수가 있으면 그거쓰고 없으면 디폴트버전으로 동작한다.
//그말인즉슨 내가 저 함수를 만들었는지 조사한다는 얘기다.
