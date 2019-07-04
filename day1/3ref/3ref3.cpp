#include <iostream>
#include <vector>
using namespace std;

class RefCountedBase
{
	int m_refCount = 0; // c++11 member field init 
public:
	void ref() {
		++m_refCount;
	}
	void deref() { // void deref( RefcountedBase* this )
		if (--m_refCount == 0) 
			delete this; 
	}

protected:
	// 핵심: 기반 클래스 포인터로 delete 하면 기반 클래스의 소멸자만 호출된다.
	// 파생클래스 소멸자를 호출되게 하려면
	// "소멸자를 가상함수로" 해야 한다.
	virtual ~RefCountedBase() { cout << "~ base" << endl; }
};

class Car : public RefCountedBase
{
public:
	~Car() { std::cout << "~Car" << std::endl; }	
};
int main()
{
	//Car c;

	{
		Car* p1 = new Car;
		p1->ref();
		Car* p2 = p1;
		p2->ref();

		p2->deref();
		p1->deref();
	}
}