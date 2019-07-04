#include <iostream>
// 4 thin template - 237p

class VectorBase
{
protected:
	int size;
public:
	VectorBase(int sz) : size(sz) { }
	int getSize() const { return size; }
};

template<typename T> class Vector : public VectorBase
{
public:
	T* buff;
	Vector(int sz) : VectorBase(sz) {
		buff = (T*)(new T[sz]);
		Car* p1 = new Car;	
	}	
	T& front() { return static_cast<T&>(buff[0]); }
	T& last() { return static_cast<T&>(buff[size - 1]); }
};

