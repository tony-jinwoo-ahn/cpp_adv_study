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
	// �ٽ�: ��� Ŭ���� �����ͷ� delete �ϸ� ��� Ŭ������ �Ҹ��ڸ� ȣ��ȴ�.
	// �Ļ�Ŭ���� �Ҹ��ڸ� ȣ��ǰ� �Ϸ���
	// "�Ҹ��ڸ� �����Լ���" �ؾ� �Ѵ�.
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