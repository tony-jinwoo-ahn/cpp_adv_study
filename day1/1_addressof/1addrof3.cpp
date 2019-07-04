#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	// �ּҸ� ��Ÿ�� ���� 0 ��� nullptr�� ������� - C++11
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
