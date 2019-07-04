// 2 traits 
// 115 page int-to-type 관련내용
#include <iostream>
using namespace std;

// is_pointer: 컴파일할때 T가 포인터인지 조사하는 도구.
//				컴파일할때 사용하는 함수라는 의미로 meta function 이라 한다.

// 만드는 법
// 1. 구조체 템플릿을 만든다.
// 2. enum { value = false } 를 넣는다.
// 3. 조건을 만족하는 부분 특수화 버전을 만든다.
//		그리고 enum { value = true } 를 넣는다.

template<typename T> struct is_pointer2
{
	enum { value = false };
};
// 템플릿 부분 특수화(specialization) 문법
// T의 형태에 따라 다른 구현을 사용하겠다는 의미.
template<typename T> struct is_pointer2<T*>
{
	enum { value = true };
};


template<typename T> 
void foo(T v)
{
	
	if (is_pointer2<T>::value) {
		std::cout << "Pointer!" << endl;
	}
	else
	{
		cout << "Not a pointer..." << endl;
	}
	
}


int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}