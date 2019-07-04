// 참고용
// concept - cpp20 에 추가되는 문법 

// error 메시지가 이쁘게 심플하게 나오는게 주 목적!

#include <iostream>

// 1. concept 을 만듭니다.
template <typename T>
concept LessThenComparable(T a, T b)
{
	{a < b}->bool;
};

// 2. 템플릿을 만들 때 T가 가져야 하는 조건(개념)을 명시합니다.
template <typename T> 
requires LessThenComparable
T Max(T a, T b)
{
	return b < a ? a : b;
}

// 아래처럼 치환해서 사용하면 위에 T를 쓰는 버전이랑 똑같은 코드이다.
// 이것도 템플릿이다.
// 혹시 전달하는 타입이 LessThenComparable 이 아니라면, 에러 나온다.
LessThenComparable 
Max(LessThenComparable a, LessThenComparable b)
{
	return b < a ? a : b;
}

int main()
{
	Max(1, 2);
}

// 포인터일 때 일루온다
template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type
foo(T p) {}

// 포인터 아닐 때 일루온다
template<typename T>
typename std::enable_if<!std::is_pointer<T>::value>::type
foo(T p) {}

// ---------------- 
// 위의 복잡한 코드가 cpp20 에서는 아래처럼 된다

// g++ 소스이름.cpp -fconcepts 로 컴파일 가능
void foo(PointerConcept) {}   // 포인터일 때 일루온다
void foo(NotPointerConcept) {}// 포인터 아닐 때 일루온다
void goo(std::DefaultConstructible a)
{
	using T = std::DefaultConstructible;
	T b; // 디폴트 생성자 필요
}
