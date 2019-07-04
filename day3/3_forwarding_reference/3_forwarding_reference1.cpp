// 3 forwarding reference1
#include <iostream>

int main()
{
	int n = 0;
	n = 10; // lvalue: 등호의 왼쪽에 올수 있는 표현식
			// rvalue: 등호의 왼쪽에 올수 없는 표현식
//	n + 1 = 10;		// n + 1 : rvalue
//	(n = 10) = 20; // n = 10 : lvalue
//	foo();

	// 규칙 1. lvalue reference 는 lvalue만 가리킬 수 있다.
	int& r1 = n; // ok
	int& r2 = 10;// error

	// 규칙 2. const lvalue reference는 lvalue와 rvalue를 모두 가리킨다.
	const int& r3 = n;	// ok
	const int& r4 = 10;	// ok. 가리킬수는 있지만 상수성이 추가된다.
		// Point() 임시객체도 rvalue이지만, 상수는 아니잖아.

	// 규칙 3. cpp11의 rvalue reference는 rvalue만 가리킬 수 있다.
	int&& r5 = n; // error
	int&& r6 = 10;// OK.

}
