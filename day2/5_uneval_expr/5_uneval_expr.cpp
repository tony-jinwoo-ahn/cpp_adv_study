//5 평가 안되는 표현식
#include <iostream>

short foo(int n)
{
	std::cout << "foo~~~" << std::endl;
	return 0;
}

int main()
{
	int n = 0;
	std::cout << sizeof(n) << std::endl;
	std::cout << sizeof(&foo) << std::endl;
//	std::cout << sizeof(foo) << std::endl;

	//foo(0); // 함수호출. 평가되는 표현식.
	sizeof(foo(0)); // 평가되지 않는 표현식. 함수 호출이 되는것은 아님.
	std::cout << sizeof(foo(0)) << std::endl; // 함수가 진짜호출은 안됨.
	
	// cpp에서 평가되지 않은 표현식은 4개가 있음.
	// unevaluated expression
	sizeof(foo(0)); // 반환값 크기
	decltype(foo(0));//반환값 타입
	noexcept(foo(0));//함수가 예외가 있는지 조사
	typeid(foo(0));//  반환값의 타입 정보

}
