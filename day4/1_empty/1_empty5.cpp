#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

// 5개의 추상적인 개념을 코드로 만들려면? empty 기법 사용
//반복자 카테고리 5가지
// 입력반복자: 입력, ++
// 출력반복자: 출력, ++
// 전진형 반복자: 입력, ++, 멀티패스 보장,     싱글리스트 반복자
// 양방향 반복자: 입력, ++, --, 멀티패스 보장, 더블리스트 반복자
// 임의접근 반복자: 입력, ++, --, +, -, [], 멀티패스 보장 => 연속된 메모리와 유사 (vector)

// 반복자 카테고리 개념을 타입화 합니다
/*
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};


// 각 컨테이너의 반복자 설계시 자신이 무슨 종류의 반복자인지
// 알려주어야 합니다
template<typename T> class vector_iterator
{
public:
	// 모든 반복자 안에는 반드시 iterator_category가 정의되어야 합니다.
	// typedef random_access_iterator_tag iterator_category; 옛날 스타일이다
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	using iterator_category = bidirectional_iterator_tag;
};
*/

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

template <typename T>
void advance(T& p, int n)
{
	// T: 반복자
	//p = p + n;
	advance_imp( p, n, typename T::iterator_category() );
}

int main()
{
	std::list<int> v = { 1,2,3,4,5 };
	auto p = v.begin();
	std::advance(p, 3);
}
