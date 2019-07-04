#include <iostream>
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
		//buff = new T[sz];// 103p. 이렇게 하지말라!
						// 이 경우 T에는 반드시 디폴트 생성자가 필요하다.

		//1. mem alloc first
		buff = static_cast<T*>( operator new(sizeof(T) * sz) );

		//2. call ctor
		int cnt = 0;
		try {			
			for (; cnt < sz; ++cnt) {
				// new (&buff[i]) T; // 디폴트 생성자 호출
				new(&buff[cnt]) T(value); // 복사생성자 호출
			}
		}
		catch (...)
		{
			// 복사 생성자 호출중 예외가 발생한 경우.
			// 생성이 완료된 객체는 소멸자 호출.
			for (int i = 0; i < cnt; ++i)
				buff[i].~T();

			// 메모리 해지
			operator delete(buff);

			// 발생된 예외를 밖으로 전달
			throw;
		}
	}
};

int main()
{
	Point p(0, 0);
	vector<Point> v(10, p);
}
