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
	// �Ʒ� ������ �����ұ��? �������� ã�� ������
	goo(std::unique_ptr<Point>(new Point(1, 2)), foo()); 
	// Point�� ���� �������� foo()�� ���� ������� �˼�����
	// ���� Point ������ unique_ptr�� �� �ּҸ� �ޱ� ���� foo()�� ���� ����Ǵٰ� exception ���ٸ�,
	// unique_ptr�� �ùٸ��� �ʱ�ȭ�� ���� ���ϰ�,
	// �޸� ������ ���߿� ����� �ȵ� ���̴� 
	//-----------
	// 1. new Point(1,2)
	// 2. foo() => ���⼭ ���ܰ� ������ 1�� �ڵ尡 �޸� ����
	// 3. unique_ptr ����
}
