#include <iostream>
using namespace std;

class AAA
{
public:
	enum { value = 10 };
	typedef int DWORD;
};
int p = 0;

template<typename T> void foo(T a)
{
	// 컴파일러는 아래 한줄을 어떻게 해석해야 할까요?
	// (1) DWORD는 "값" ( static 변수 또는 enum 상수 ) 이다. => 곱셈연산 수행하겠지?
	// (2) DWORD는 T 안에 내포된 "타입"이다. => 포인터변수 p 선언이겠지?
	// T::DWORD * p; // DWORD 를 값으로 보고 곱하기 p 하는 코드. cpp에서는 무조건 값으로 본다.

	typename T::DWORD * p; // DWORD 를 타입으로 해석해달라는 의미.

	// **********************************************************
	// 핵심: 템플릿 인자(T)에 의존된 타입을 사용할 때는 반드시
	//		앞에 typename을 붙여야 한다!!!
	// **********************************************************

	typename AAA::DWORD *p2; // typename이 필요없다! 
							// T가 아니라 명확한 이름(AAA) 사용!
							// 이럴때는 typename 을 붙이면 안된다.
}

int main()
{
	AAA aaa;
	foo(aaa);

	return 0;
}
