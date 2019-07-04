// 5_move3

#include <iostream>

class People
{
	char* name;
	int age;
public:

	People(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	// �ӽð�ü(rvalue)�� ���
	// move ������ 
	People(People&& p) : name(p.name), age(p.age)
	{
		p.name = nullptr; // �ڿ� ����!
	}
	~People() { delete[] name; }

	// ���� ����� ������ ���� ������
	People(const People& p) : age(p.age)
	{
		// pointer ������ �޸� ��ü�� ����
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
};

People foo()
{
	People p("lee", 30);
	return p;
}

int main() {
	People p1("kim", 10);
	People p2 = p1;	// ���� ����
	People p3 = foo(); // move ������
	People p4 = static_cast<People&&> (p1); // move. ���� ���� ���ϱ� ǥ�ؿ��� move ���� ����.
	People p5 = std::move(p1); // ��ó�� ĳ�����ϴ� �Լ�.
}
