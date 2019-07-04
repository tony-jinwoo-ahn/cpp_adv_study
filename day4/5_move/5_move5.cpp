#include <iostream>
#include <string>

// Ŭ������ �ڿ��� �Ҵ����� ������ - �Ҹ��ڰ� ��� �ȴ�.
// Ŭ������ �ڿ��� �Ҵ��ϸ�
// C++98
// "�Ҹ���", "���������", "���Կ�����"�� �ʿ��ϴ�. - rule of 3
// C++11 ���ʹ� 2�� �߰�
// rule of 3 +
// "move ������", "move ���Կ�����" - rule of 5

// move �迭�Լ��� �������� ������
// "���� �迭 �Լ��� ȣ��ǰ� �ȴ�."

class Test
{
	int data;
	int* resource;
public:

	Test() {} // resource = new int
	~Test() {}
	Test(const Test& t) {
		std::cout << __FUNCSIG__ << std::endl;
	}
	Test& operator=(const Test& t) { return *this; }

	Test(Test&& t) {}
	Test& operator=(Test&& t) { return *this; }
};

int main()
{
	Test t1;
	Test t2 = t1;
	t2 = t1;

	Test t3 = std::move(t1); // static_cast<Test&&>(t1)
	t3 = std::move(t1);
}
