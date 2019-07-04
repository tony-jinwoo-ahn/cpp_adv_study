#include <iostream>
#include <atomic> // cpp11 multithread safe type

using namespace std;


template<typename T> class RefCountedBase
{	
	//mutable int m_refCount = 0;
	mutable std::atomic<int> m_refCount = 0;
public:

	void ref() const {
		m_refCount.fetch_add(1);
	}
	void deref() const {
		m_refCount.fetch_sub(1);
		int cnt = m_refCount.load();
		if (cnt == 0)
			delete static_cast<const T*> (this);
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