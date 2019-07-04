#include <iostream>

// 함수객체: () 연산자를 재정의해서  함수처럼 사용가능한 것
int Add(int a, int b) { return a + b; }
struct Plus
{
	int operator() (int a, int b) { return a + b; }
};
int main()
{
	Plus p;
	int n1 = Add(1, 2);
	int n2 = p(1, 2); // p.operator()(1,2)

	// a + b;	// 사용자정의 타입이면 a.operator+(b)
	// a();		// a.operator()()
	// a(1,2)	// a.operator()(1,2)
}
