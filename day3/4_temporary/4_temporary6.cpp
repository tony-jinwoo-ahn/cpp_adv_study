#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// ��������� ��� 1. call by value
	// Point(Point p) {} // Point p = p1 �� �ҷ��� �ϰ� �׷��� �� ��������ڰ� �ҷ��� �ϰ�... 
	// ��������� ���� ȣ�� ����.

	// 2. ���� ���
	// rvalue�� ����������. ��, ���� ��ȯ�ϴ� �Լ��� ��ȯ���� ������ ����.
//	Point(Point& p) {} // Point& p = p1 // ��ü�� ����°� �ƴϹǷ� �ٽ� �Լ��� �θ��� ����. �չ����� ǥ��.

	// 3. const lvalue reference
	//		lvalue�� rvalue�� ��� ���� �� �ִ�.
	//      const lvalue, const rvalue�� ��� ���� �� �ִ�! 
	Point(const Point& p) { // ���⼭ const ���� �ǳ�? �ȵȴ�. �׷��� const ���ڷ� �Ѿ���� �ָ� ���޴´�.
		cout << "lvalue�� ��. ���������" << endl;
	}	

	Point(Point&& p) { // R-value ����������. �켱������ �ϴ� ����� �θ���.
		// �׷��� ���⿡ const�� �Ѿ���� �ִ� ��� �ϳ�? �� �޴´�.
		// const�� �Ǿ������� �ּҸ� �ٲ㼭 �ڿ����Ⱑ �Ұ�. 

		// �ӽð�ü�� �ڿ��� �������. ������ �� �ı��ɰ��ݾ�.
		cout << "R-value�� ��. Move ������" << endl;
	}
	
};

Point goo() // ���������� �ϸ�ȵȴ�. ���������� �ݵ�� �ı��ǹǷ�. �ӽð�ü ��ȯ�� ���ۿ� ����.
{
	Point pt;
	return pt; // �ӽð�ü ��ȯ
}

int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p1); // Point(Point) �� �ʿ��ϴ�. ������ �����Ϸ��� ��������� �������.

	Point p4 = goo(); // Point p4 ( goo() ); �� ���� ���. rvalue�� ���� �� ����.
}

