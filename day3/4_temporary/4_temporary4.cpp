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

// call by value: ���纻�� �����ȴ�
void foo(Point p) {}

Point pt(0, 0);

// return by value : ���Ͽ� �ӽð�ü ����.
Point goo() { return pt; } // ��¥ pt�� �ذ� �ƴϴ�. ���纻�� ��ȯ�ȴ�.
// �ٵ� �� ���纻�� �ӽð�ü�̴�. �̸��� �����ϱ�.

Point& hoo() { return pt; } // �ӽð�ü�� ������ ����� �ǵ�.

int main()
{
//	Point p(1, 2);
//	foo(p);
//	goo().x = 10; // error. �ӽ� ���ϰ��̴�.
	hoo().x = 10; // �ߵȴ�. �ӽð�ü�� �ƴϴ�.
}
