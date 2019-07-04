// p. 103 Generic Container Idioms

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)
	{
		cout << "Point()" << endl;
	}
	~Point()
	{
		cout << "Dtor~" << endl;
	}
};

int main()
{
	// 1. 0,0으로 초기화된 Point를 힙에 한개 만들어 보세요
	Point* p1 = new Point(0, 0);

	// 2. 0,0으로 초기화된 Point를 힙에 10개 만들어 보세요
	// Point* p2 = new Point[10]; // error. default ctor 필요

	// 메모리 할당과 생성자 호출을 분리하면 항상 편리하다.
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// 10개의 메모리에 대해서 생성자 호출 (마지막날 시험문제!)
	for (int i = 0; i < 10; ++i) {
		new(&p2[i]) Point(0, 0);
	}

	// 사용후에는 
	// 1. 소멸자 호출
	for (int i = 0; i < 10; ++i) {
		p2[i].~Point();
	}

	// 메모리만 해지
	operator delete(p2);

}
