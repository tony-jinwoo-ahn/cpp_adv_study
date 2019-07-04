#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

// tag dispatching: 꼬리표에 따라서 함수 분배

/*
template<typename T>
void advance_imp(T& p, int n, std::random_access_iterator_tag)
{
	std::cout << "임의접근" << std::endl;
	p = p + n;
}
template<typename T>
void advance_imp(T& p, int n, std::input_iterator_tag)
{
	std::cout << "임의접근 아님" << std::endl;
	while (n--) ++p;
}
*/


// enable_if 버전으로 변경해 봅시다.
template<typename T>
typename std::enable_if< 
	std::is_same< 
		typename std::iterator_traits<T>::iterator_category,
		std::random_access_iterator_tag>::value>::type
advance(T& p, int n)
{
	std::cout << "임의접근" << std::endl;
	p = p + n;
}

template<typename T>
typename std::enable_if< // typename을 안적어주면, 전체를 해석해서 static 변수라고 해석해버림.
	!std::is_same<
	typename std::iterator_traits<T>::iterator_category,
	std::random_access_iterator_tag>::value>::type
advance(T& p, int n)
{
	std::cout << "임의접근 아님" << std::endl;
	while (n--) ++p;
}

int main()
{
	int v[5] = { 1,2,3,4,5 };
	auto p = std::begin(v);
	std::advance(p, 3);
}
