#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>


//반복자 카테고리 5가지
// 입력반복자: 입력, ++
// 출력반복자: 출력, ++
// 전진형 반복자: 입력, ++, 멀티패스 보장,     싱글리스트 반복자
// 양방향 반복자: 입력, ++, --, 멀티패스 보장, 더블리스트 반복자
// 임의접근 반복자: 입력, ++, --, +, -, [], 멀티패스 보장 => 연속된 메모리와 유사 (vector)


// 반복자의 형태
// 1. 클래스로 만들어진 객체 형태
// 2. raw pointer
// 위 2개의 차이점을 해결하는 도구
template<typename T> struct iterator_traits
{
	using iterator_category = typename T::iterator_category;
};
template<typename T> struct iterator_traits<T*>
{
	//using iterator_category = ???
	// 포인터는 덧셈뺄셈 다되는 임의접근 반복자이다. 따라서 아래와 같이...
	using iterator_category = std::random_access_iterator_tag;	
};

template <typename T>
void advance(T& p, int n)
{
	advance_imp(p, n, typename std::iterator_traits<T>::iterator_category());
}

int main()
{
	int v[5] = { 1,2,3,4,5 };
	auto p = std::begin(v);
	std::advance(p, 3);
}
