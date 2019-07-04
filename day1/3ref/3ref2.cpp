#include <iostream>
#include <vector>
using namespace std;

class Car
{
	int m_refCount = 0; // c++11 member field init 
public:
	void ref() { 
		++m_refCount; 
		cout << "refCount: " << m_refCount << endl;	
	}
	void deref() { if (--m_refCount == 0) delete this; }

protected: // cannot make instance on stack.
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