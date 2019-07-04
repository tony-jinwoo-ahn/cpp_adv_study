// 2 traits 
// 115 page int-to-type 관련내용
#include <iostream>
using namespace std;

// is_reference 만들어보기


// 만드는 법
// 1. 구조체 템플릿을 만든다.
// 2. enum { value = false } 를 넣는다.
// 3. 조건을 만족하는 부분 특수화 버전을 만든다.
//		그리고 enum { value = true } 를 넣는다.

template<typename T> struct is_ref
{
	enum { value = false };
};
template<typename T> struct is_ref<T&>
{
	enum { value = true };
};
template<typename T> struct is_ref<T&&>
{
	enum { value = true };
};

template<typename T> struct is_const2<T>
{
	enum { value = false };
};
template<typename T> struct is_const2<const T>
{
	enum { value = true };
};


template<typename T>
int is_reference2(T v)
{
	if (is_ref<T>::value) {
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	cout << is_ref<int>::value << endl;
	cout << is_ref<int&>::value << endl;

}