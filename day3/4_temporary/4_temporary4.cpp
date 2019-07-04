#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};

// call by value: 복사본이 생성된다
void foo(Point p) {}

Point pt(0, 0);

// return by value : 리턴용 임시객체 생성.
Point goo() { return pt; } // 진짜 pt를 준거 아니다. 복사본이 반환된다.
// 근데 이 복사본은 임시객체이다. 이름이 없으니까.

Point& hoo() { return pt; } // 임시객체를 만들지 말라는 의도.

int main()
{
//	Point p(1, 2);
//	foo(p);
//	goo().x = 10; // error. 임시 리턴값이다.
	hoo().x = 10; // 잘된다. 임시객체가 아니다.
}
