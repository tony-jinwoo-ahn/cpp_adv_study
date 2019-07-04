#include <iostream>
#include <type_traits>

class Point
{
	int x, y;
public:
//	Point() {}
	Point(int a, int b) : x(a), y(b) {}
	int foo() { return 0; }
};

// Point& declval(); // 핵심: 구현이 없습니다.

template<typename T> T& declval();

int main()
{
//	int n = sizeof(Point().foo()); // 약점: 반드시 디폴트 생성자가 있어야 가능한 코드.

//	int n = sizeof(declval().foo()); // 평가되지 않는 함수이므로 구현이 필요없다. 
	// 컴파일러는 Point 객체가 반환되어온다고 생각함.

//	int n = sizeof(declval<Point>().foo());

	int n = sizeof(std::declval<Point>().foo());
	// 평가되지 않는 표현식에서 객체 없이도 디폴트 생성자를 부르고 싶을 때 사용.
	// 컴파일 시간에 조사하고 싶은게 있을 때 상당한 메리트 있는 기법.

}
