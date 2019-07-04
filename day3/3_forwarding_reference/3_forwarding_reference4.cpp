#include <iostream>

// 함수 인자로
// int&  : int의 lvalue만 전달 가능.
// int&& : int의 rvalue만 전달 가능.
// T&    : 모든 타입의 lvalue만 전달 가능.

// T&&   : 모든 타입의 lvalue와 rvalue 전달 가능.

// lvalue(n) 을 보내면 T : int& 이고, 함수 최종버전은 (int&) 이다.
// rvalue(0) 을 보내면 T : int  이고, 함수 최종버전은 (int&&)이다.


void f1(int&  a) {} // 이 함수에는 lvalue 밖에 못 보낸다. 10을 못 보냄.
void f2(int&& a) {} // 이 함수에는 rvalue 밖에 못 보낸다. n을 못 보냄.

// 결국 붕괴규칙에 의해서 하나만 남는다. 결국 n 밖에 못 받음.
template<typename T> void f3(T&  a) {} // 뒤에 하나의 &만 있으면 앞에 몇개를 안고 있어도 결국은 하나다.
// f3<int>( n );
// f3<int&>( n );
// f3<int&&>( n );


template<typename T> void f4(T&& a) {}

int main()
{
	int n = 0;

	// 사용자가 타입을 직접 전달하면 어떤 함수가 생성될까요?
	// 생성되는 함수의 모양을 예측해보세요.
	f4<int>  ( 0 ); // T : int 이고    T&& : int&&  이니까    f4(int&&)
	f4<int&> ( n ); // T : int&  이고  T&&: int& && 이니까    f4(int&)
	f4<int&&>( 0 ); // T : int&& 이고  T&&: int&& &&  이니까  f4(int&&)

	// 사용자가 타입을 지정하지 않으면 컴파일러가 타입을
	// 결정해야 한다. 어떻게 결정할까?
	f4(n); // T : int& 으로 결정하고, 최종 함수를 f4(int&) 로 생성한다.
	f4(0); // T : int    로 결정하고, 최종 함수는 f4(int&&)로 생성한다.

}

