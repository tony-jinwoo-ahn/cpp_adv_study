#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	// 주소를 나타낼 때는 0 대신 nullptr을 사용하자 - C++11
	Point* operator&() const { return NULL; }
};

template<typename T>
T* addressof_(T& obj)
{	
	/*
	return reinterpret_cast<T*>(
		&(reinterpret_cast<char&> (
			const_cast<T&>(obj))));
			*/

	return reinterpret_cast<T*>(
		&( const_cast<char&> (
			reinterpret_cast<const volatile char&>(obj))));
}

int main()
{
	
	const Point pt;
	const Point* p = std::addressof(pt);
	// T : const Point

	cout << p << endl;
}
