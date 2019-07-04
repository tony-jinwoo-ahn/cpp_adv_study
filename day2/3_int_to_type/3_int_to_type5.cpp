// 0과 1을 어떻게 다른 타입으로 만들어서 오버로딩을 성립시킬까?

#include <iostream>
#include <type_traits>

// 템플릿 인자로는 타입뿐 아니라 정수를 보낼수도 있음. 
// 115 page code
template<int N> struct my_int2type
{
	enum {value = N};
};

int main()
{
	foo(0);
	foo(1); // 0, 1은 같은 타입. foo(0), foo(1)은 동일 함수 호출.
	my_int2type<0> t0; // 구조체에 0이 들어간 타입.
	my_int2type<1> t1; // 구조체에 1이 들어간 타입. 둘은 다른 타입이 되었다.
	foo(t0); 
	foo(t1); // t0, t1은 다른 타입. foo(t0), foo(t1)은 다른 함수 호출.
}

// int to type 덕분에 숫자만 가지고도 함수 오버로딩이 된다.
