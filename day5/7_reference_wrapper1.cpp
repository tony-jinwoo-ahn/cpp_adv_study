// 7_reference_wrapper
#include <iostream>

// Cpp ����: ���������� const�Դϴ�. ������ �̵����� �ʰ� ���� �̵��մϴ�.
int main()
{
	int n1 = 10;
	int n2 = 20;
	int& r1 = n1;
	int& r2 = n2;

	r2 = r1; // �� �� ���� �ǹ̸� �� ������ ������ 

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;

}

// cpp�� ������ const�̴�. ���� ����Ű�� ����� �� �ٲ۴�. 
// ���� �̵��� �Ͼ��.
