#include <iostream>
using namespace std;


template<typename T> class RefCountedBase
{
	// mutable 멤버 데이터: 상수함수 안에서도 값을 수정할 수 있다.
	mutable int m_refCount = 0;
public:

	// const 객체라도 수명 관리 필요.
	// 참조계수를 조작하는 함수는 반드시 "상수 멤버함수"여야 함.
	void ref() const {
		++m_refCount;
	}
	void deref() const {
		// 일반 멤버 함수에서 this: RefCountedBase* this
		// 상수 멤버 함수에서 this: const RefCountedBase* this
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