#include <iostream>

// �Լ� ��ü�� ���� 1. ���¸� ������ �Լ�
// �Ϲ� �Լ��� ���۸� �ְ� ���¸� ���� �� ����. (�������� �����)
// �Լ� ��ü�� Ŭ����(����ü) �̹Ƿ� ��� �����Ϳ� ����Լ� Ȱ�밡��

int Add(int a, int b) { return a + b; }
struct Plus
{
	int base;
	Plus(int a = 0) : base(a) {}
	int operator() (int a, int b) { return a + b + base; }
};
int main()
{
	Plus p(100);
	int n1 = Add(1, 2);
	int n2 = p(1, 2); 
}
