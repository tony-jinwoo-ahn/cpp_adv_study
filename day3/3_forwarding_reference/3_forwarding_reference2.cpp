#include <iostream>
// __FUNCSIG__ : 함수이름 + signature, VC++ 전용. g++ 에서 안됨
// __PRETTY_FUNCTION__ : g++용 함수이름+signature
//void foo2(int& a) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

void foo(int& a)		{ std::cout << __FUNCSIG__ << std::endl; }
void foo(const int& a)  { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& a)		{ std::cout << __FUNCSIG__ << std::endl; }


int main()
{
	int n = 0;
//	foo(n); // 1번 호출, 없으면 2번.
//	foo(10);// 3번 호출, 없으면 2번.

//	int& r = n;
//	foo(r); // 1번 호출, 없으면 2번

	int&& r2 = 10; // 이 순간 r2 메모리를 잡고 10을 가리킨다.
					// 10은 rvalue지만 r2라는 이름이 있고
					// 왼쪽에 올수있다. 따라서 lvalue 이다.

	//10 = 20; // 에러. 10은 rvalue 이다. 값이다.
	//r2 = 20; // ok

	foo(r2); // 1번 부른다.

	foo(static_cast<int&&>(r2)); // 3번으로 간다. 요즘 오픈소스는 필수로 알아야 한다.

	r2 = static_cast<int&&>(r2);
	foo(r2); // 1번 부른다.
}