#include <iostream>

template<typename T>
class Test
{
public:
	// 아래 코드는 forwarding reference일까요? 
	// NO.
	// 클래스가 템플릿이지, 함수는 템플릿이 아니다. 결국 int&&이 될 뿐이다.
	// 클래스 생성시 이미 T의 타입이 결정된다.
	void foo(T&& arg) {} 
	
	// 아래 코드가 forwarding reference 입니다.
	template<typename U> // 새로운 타입 U로 만들면 됨.
	void goo(U&& arg) {} // 모든 타입을 다 빨아들일 수 있다.	
};

int main()
{
	int n = 0;
	Test<int> t;
	t.foo(10);
	t.foo(n);
}