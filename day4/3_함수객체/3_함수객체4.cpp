//3 함수객체4
#include <iostream>

template<typename T> void foo(T f)
{
	std::cout << __FUNCSIG__ << std::endl;
	f(1, 2);
}
int main()
{
	// cpp11 람다표현식 : 
	foo([](int a, int b) {return a + b; });
	// 컴파일러가 어떤 class를 만드는거다. 그리고 이 클래스에 대해서 임시객체를 만드는 원리다.
	// class xx{int operator()(int, int)}; xx();

	[](int a, int b) { return a + b; }(1, 2); // 람다표현식이만든임시객체(1,2);

	auto f = [](int a, int b) { return a + b; };	
	f(1, 2);

	// **********************************************
	// 문제!!!
//	auto& a1 = [](int a, int b) { return a + b; };			// 1: rvalue인 임시객체는 참조로 받을 수 없다.
	const auto& a2 = [](int a, int b) { return a + b; };	// 2: ok. const 참조는 다 받을 수 있다.
	auto&& a3 = [](int a, int b) { return a + b; };			// 3: ok.

	// 첫날 시험문제
	// f가 람다를 나타내는 임시객체 xx 타입이라고 할 때,
	/*
	decltype(f) f2; // ??? 이건 에러.	
	// f랑 똑같은 타입의 변수 f2가 만들어지나? 
	// 안된다. 람다표현식이 만드는 클래스에는
	// 디폴트 생성자를 사용할 수 없습니다.

	ClosureType::ClosureType()
	ClosureType() = delete;  (until C++14)
	ClosureType() = default; (since C++20)(only if no captures are specified)

	이게 cpp20부터는 또 가능해진다.

	*/

	decltype(f) f3(f); // ok. 
	// 디폴트 생성자는 없지만 복사 생성자는 있음.
	// void foo(T f) // T f = 람다표현식() 이렇게 받아야 하므로 복사생성자는 필요함.

	int n = 10;
	//int&& r   = 10; // rvalue reference이다. 데이터타입 확정.
	// T&& r    = 함수인자; 이거는 T가 레퍼런스를 안고 있을 수 있으므로 인자에 따라 달라짐; forwarding reference
	// auto&& r = 우변; 이거도 우변이 뭐냐에 따라 달라지는 forwarding reference 이다. auto는 항상 T랑 같다. 뭐가올지 모름.
	auto&& a5 = 10; // int&& a5 = 10
	auto&& a6 = n;  // int& a6 = n

}
