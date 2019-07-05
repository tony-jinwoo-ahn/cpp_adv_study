// 3 make
#include <iostream>
#include <memory>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}
};
int foo() { return 0; }
void goo(const std::unique_ptr<Point>& p, int n) {}

int main()
{
	// 아래 한줄은 안전할까요? 문제점을 찾아 보세요
	goo(std::unique_ptr<Point>(new Point(1, 2)), foo()); 
	// Point가 먼저 생성될지 foo()가 먼저 실행될지 알수없다
	// 만일 Point 생성후 unique_ptr이 그 주소를 받기 전에 foo()가 먼저 실행되다가 exception 났다면,
	// unique_ptr은 올바르게 초기화가 되지 못하고,
	// 메모리 해지가 나중에 제대로 안될 것이다 
	//-----------
	// 1. new Point(1,2)
	// 2. foo() => 여기서 예외가 나오면 1의 코드가 메모리 누수
	// 3. unique_ptr 생성
}
