// 6_SFINAE1 - 215 PAGE
#include <iostream>

//void foo(int n) { std::cout << "int" << std::endl; }
//void foo(float n) { std::cout << "float" << std::endl; }
//void foo(double n) { std::cout << "double" << std::endl; }
void foo(...) { std::cout << "..." << std::endl; }

//template<typename T>
//void foo(T n) { std::cout << "T" << std::endl; }

int main()
{
	float f = 3.4f;

	// overloading resolution
	// 동일 이름의 함수가 여러개 있을 때 함수 찾는 순서
	foo(f); // 1. exactly matching - float
			// 2. template 사용해서 float 생성 - T
			// 3. promotion: 데이터 손실이 없는 변환 - double
			// 4. standard conversion: 표준 타입끼리 변환 - int
			// 5. 어떠한 후보도 없을 때 가변인자 사용 - ...
}
