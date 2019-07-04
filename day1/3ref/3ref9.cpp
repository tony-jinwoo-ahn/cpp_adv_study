#include <iostream>
using namespace std;


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

#define WTF_MAKE_NONCOPYABLE(classname) \
	classname(const classname&) = delete; \
	classname& operator=(const classname) = delete;

template<typename T> class RefCounted : public RefCountedBase
{	
	WTF_MAKE_NONCOPYABLE(RefCounted);

protected:
	RefCounted() {}

public:
	void deref() const {
		if (--m_refCount == 0)
			delete static_cast<const T*> (this);

	}

protected:
	~RefCounted() { cout << "~RefCounted" << endl; }
};

class Car : public RefCounted<Car>
{
public:
	~Car() { std::cout << "~Car" << std::endl; }
	void Go() { std::cout << "Car::go" << endl; }
};

// 객체를 참조계수 기반으로 관리하기로 결정했다면
// raw pointer를 사용하게 할지말자!
// 스마트 포인터를 도입해야 한다.

template<typename T> class AutoPtr
{
	T* m_obj;
public:
	AutoPtr(T* p = 0) : m_obj(p) {
		if (m_obj) m_obj->ref();
	}
	AutoPtr(const AutoPtr& p) : m_obj(p.m_obj)
	{
		if (m_obj) m_obj->ref();
	}
	~AutoPtr() {
		if (m_obj)
			m_obj->deref();
	}
	T* operator->() { return m_obj; }
	T& operator*() { return *m_obj; }
};

int main()
{
	//Car* p1 = new Car; p1->ref();
	AutoPtr<Car> p1 = new Car; // AutoPtr<Car> p1( new Car )
		
	// Car* p2 = p1; p2->ref();
	AutoPtr<Car> p2 = p1;
	p2->Go();
	//p2->deref();
	//p1->deref();
	
}