//2 상수멤버함수
#include <iostream>
using namespace std;


class Rect
{
	int x = 0, y = 0, w = 10, h = 10;
public:
	int getArea() const // 상수 멤버함수
	{
//		x = 10; // error
		return w * h;
	}
	void setX(int a) { x = a; }
};

void foo(const Rect& r)
{
	int n = r.getArea();
}

int main()
{
	const Rect r; // const instance
	//r.setX(100);
	int n = r.getArea();
	// 핵심: 상수객체는 상수함수만 호출가능합니다.
	// 객체의 상태를 변경하지 않는 
	// 모든 멤버함수(getter)는 
	// 반드시 상수 member 함수가 되어야 함.
}
