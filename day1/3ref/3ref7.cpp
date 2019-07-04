#include <iostream>
using namespace std;
// 237 page. thin template: 
// class template �� �ʹ� ���� Ÿ�Կ� ���ؼ� �ν��Ͻ�ȭ�� �� 
// �ڵ尡 Ŀ�� �� �ִ� - code bloat
// �̸� �������� ���

// T�� ������� ���� ��� �Լ��� ���ø��� �ƴ� ��� Ŭ������ ����� ��ӹ���.

// class template�� ���鶧
// ���ø� �Ķ���� T �� ������� ���� ��� �Լ���
// ���ø��� �ƴ� ��� Ŭ������ ���� ��ӹ���

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