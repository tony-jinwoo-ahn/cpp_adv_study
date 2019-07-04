//5_move2
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

	// 임시객체(rvalue)인 경우
	// move 생성자 
	People(People&& p) : name(p.name), age(p.age)
	{
		p.name = nullptr; // 자원 포기!
	}
	~People() { delete[] name; }

	// 깊은 복사로 구현한 복사 생성자
	People(const People& p) : age(p.age)
	{
		// pointer 변수는 메모리 자체를 복사
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
	People p2 = p1;	
	People p3 = foo();
}
