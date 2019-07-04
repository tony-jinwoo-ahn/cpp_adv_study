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

void foo(const Point& p) {} // �̰ž��� lvalue, rvalue �� ���� �� �־ ����.
//void foo(Point&& p) {} // �̷��� forward �ϸ� �ӽð�ü�� ���� �� �ִµ�, ���� ��¥ ��ü �ް���� �� �ƽ���.

int main()
{
	//Point pt(1, 2);
	//foo(pt);

	// �Լ� ���ڷ� �ӽð�ü�� �����ϴ� ��찡 ����. (��ȸ��)
	foo(Point(10,20));
	
	cout << "---------------" << endl;
}
