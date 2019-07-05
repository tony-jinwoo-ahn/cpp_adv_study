// 7_reference_wrapper
#include <iostream>

// Cpp 참조: 개념적으로 const입니다. 참조가 이동하지 않고 값이 이동합니다.
int main()
{
	int n1 = 10;
	int n2 = 20;
	int& r1 = n1;
	int& r2 = n2;

	r2 = r1; // 이 한 줄의 의미를 잘 생각해 보세요 

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;

}

// cpp의 참조는 const이다. 절대 가리키는 대상을 못 바꾼다. 
// 값의 이동이 일어난다.
