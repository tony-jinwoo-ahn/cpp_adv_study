#include <iostream>
// 템플릿: 클래스를 만드는 틀. 사용하지 않으면 클래스가 생성되지 않음.
// lazy instantiation : 사용된 템플릿만 인스턴스화 (실제 c++ code 생성)
template <typename T>
class A
{
	T data;
public:
	void foo(T a)
	{
		*a = 10;
	}
};
int main()
{
	A<int> a; // 여기까지는 컴파일 잘됨.
	a.foo(0); // 사용하는 코드가 있을 때 비로소 에러가 발생.

}
