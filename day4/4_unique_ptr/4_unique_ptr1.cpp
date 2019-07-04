//4_unique_ptr1
#include <iostream>

class Car
{	
public:
	void Go() { std::cout << "Car Go" << std::endl; }
	~Car() { std::cout << "~Car" << std::endl; }
};

// 핵심: -> * 재정의해서 포인터처럼 보이게
// 장점: raw pointer가 아니라 객체이므로 소멸자등을 활용해서 자동삭제 기능

class unique_ptr
{
	Car* obj;
public:
	unique_ptr(Car* p = 0) : obj(p) {}
	~unique_ptr() { delete obj; }

	Car* operator->() { return obj; }
	Car& operator*()  { return *obj; }
};
int main()
{
	unique_ptr p1(new Car);
	p1->Go(); // (p1.operator->())Go()
			  // (p1.operator->())->Go() 마치 화살표가 있는 것처럼 해석해준다.

	(*p1).Go(); // p1.operator* 재정의 필요


}
