#include <iostream>
using namespace std;

// CRTP (Curiously Recurring Template Pattern) - 71
// base class�� ���ø��ε� �Ļ�Ŭ������ ���鶧 
// �ڽ��� �̸��� ���ø����ڷ� �������ִ� ���.
// �̷��� ������� �Ļ�Ŭ������ �̸��� �̸� ����Ҽ� �ִ�.
template<typename T> class RefCountedBase
{
	int m_refCount = 0;
public:
	void ref() {
		++m_refCount;
	}
	void deref() {
		if (--m_refCount == 0)
			delete static_cast<T*> (this);
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
	
		Car* p1 = new Car;
		p1->ref();
		Car* p2 = p1;
		p2->ref();

		p2->deref();
		p1->deref();
}