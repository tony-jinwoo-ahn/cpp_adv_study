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
	// 이 클래스는 복사되면 안됨. 컴파일러가 복사생성자 만들지못하게 한다.
	//RefCounted(const RefCounted&) = delete;
	//RefCounted& operator=(const RefCounted&) = delete;
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
//	Car() {}
	~Car() { std::cout << "~Car" << std::endl; }
};


int main()
{
	Car* p1 = new Car;	p1->ref();
	
//	Car* p3 = new Car(*p1); // 수명 관리 참조 계수는 복사하면 안됨

	p1->deref();
}