#include <iostream>
using namespace std;
// 237 page. thin template: 
// class template 이 너무 많은 타입에 대해서 인스턴스화될 때 
// 코드가 커질 수 있다 - code bloat
// 이를 막기위한 기술

// T를 사용하지 않은 멤버 함수는 템플릿이 아닌 기반 클래스를 만들어 상속받자.

// class template을 만들때
// 템플릿 파라미터 T 를 사용하지 않은 멤버 함수는
// 템플릿이 아닌 기반 클래스를 만들어서 상속받자

class RefCountedBase
{
protected:
	mutable int m_refCount = 0;
public:

	void ref() const {
		++m_refCount;
	}
	~RefCountedBase() { cout << "~BASE" << endl; }

};

template<typename T> class RefCounted : public RefCountedBase
{
public:	
	void deref() const {
		if (--m_refCount == 0)
			delete static_cast<const T*> (this);
		/*
		delete static_cast<T*> (const_cast<RefCountedBase*>(this));
		*/
	}

protected:
	~RefCounted() { cout << "~RefCounted" << endl; }
};

class Car : public RefCounted<Car>
{
public:
	~Car() { std::cout << "~Car" << std::endl; }
};

class Truck : public RefCounted<Truck>
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	const Car* p1 = new Car;
	p1->ref();
	p1->deref();
}