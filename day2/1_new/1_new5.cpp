#include <iostream>
#include <memory>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)
	{
		cout << "Point()" << endl;
	}
	~Point()
	{
		cout << "Dtor~" << endl;
	}
};

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, T value = T()) : size(sz), capacity(sz)
	{
		
		//1. mem alloc first
		buff = static_cast<T*>(operator new(sizeof(T) * sz));

		//2. call ctor
		try
		{
			// buff ~ buff+10 공간에 있는 객체에 value를 사용해서 복사 생성자 호출.
			// 			
			std::uninitialized_fill_n(buff, 10, value);
		}
		catch (...)
		{
			operator delete(buff);
		}

	}
};

int main()
{
	Point p(0, 0);
	cout << "******" << endl;
	vector<Point> v(10, p);
}
