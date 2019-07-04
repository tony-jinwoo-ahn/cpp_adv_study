#include <iostream>

void foo(int&  arg) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& arg) { std::cout << __FUNCSIG__ << std::endl; }

// cast 둘다 넣어서 모양 통일! 이제 템플릿화 가능. 
//void forwarding(int&  n) { foo(static_cast<int&>(n)); }
//void forwarding(int&& n) { foo(static_cast<int&&>(n)); }

// 정리. perfect forwarding
// 전달받은 인자를 다른 곳으로 완벽히 전달하는 기술.

// 1. 함수 인자를 T&& 로 받아서
// 2. 다른 곳에 보낼때는 std::forward<T>(arg) 로 묶어서 전달

template <typename T>
void forwarding(T&& n) 
{ 
//	foo(static_cast<T&&>(n)); // 근데 이렇게 캐스팅 쓰면 좀 의미가 안맞는 느낌이라서 cpp진영에서 새 함수 만듦
	foo(std::forward<T>(n)); // forward 안에서 위처럼 캐스팅.
}

// 10 => T : int  이며 T&& : int&&
// n  => T : int& 이며 T&& : int&
int main()
{
	int x = 10;
	forwarding(x);
	forwarding(10);
}
