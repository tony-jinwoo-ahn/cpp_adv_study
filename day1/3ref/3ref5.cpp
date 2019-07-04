#include <iostream>
using namespace std;


template<typename T> class RefCountedBase
{
	// mutable ��� ������: ����Լ� �ȿ����� ���� ������ �� �ִ�.
	mutable int m_refCount = 0;
public:

	// const ��ü�� ���� ���� �ʿ�.
	// ��������� �����ϴ� �Լ��� �ݵ�� "��� ����Լ�"���� ��.
	void ref() const {
		++m_refCount;
	}
	void deref() const {
		// �Ϲ� ��� �Լ����� this: RefCountedBase* this
		// ��� ��� �Լ����� this: const RefCountedBase* this
		if (--m_refCount == 0)
			delete static_cast<const T*> (this);
			/*
			delete static_cast<T*> (const_cast<RefCountedBase*>(this));
			*/
	}

protected:
	~RefCountedBase() { cout << "~ base" << endl; }
};

class Car : public RefCountedBase<Car>
{
public:
	~Car() { std::cout << "~Car" << std::endl; }
};
int main()
{
	const Car* p1 = new Car;
	p1->ref();	
	p1->deref();
}