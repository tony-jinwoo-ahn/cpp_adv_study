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
	AutoPtr<Car> p1 = new Car;	
	p1->Go(); // p1.operator->() ÀÇ ¿ø¸®.
	AutoPtr<Car> p2 = p1;

	

}