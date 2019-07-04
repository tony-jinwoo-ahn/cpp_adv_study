#include <iostream>
// page 73 - empty base optimization
// empty class가 기반 클래스가 되면 크기가 0으로 계산된다.
// 함수객체는 거의 다 empty이다. 기반 클래스로 쓰자.
// 이걸로 만든게 unique_ptr 이다.

class Empty {};

class AAA
{
	Empty a; // 주소같은거 잡아야하니까 1 바이트
	int b; // 4 바이트
}; // 구조체는 4 단위 배수로 align
class BBB : public Empty // empty base class는 optimization 되어서 크기를 0으로 해준다.
{
	int b;
};
int main()
{
	std::cout << sizeof(AAA) << std::endl; // ???
	std::cout << sizeof(BBB) << std::endl; // ???
}
