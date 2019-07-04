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
		//buff = new T[sz];// 103p. �̷��� ��������!
						// �� ��� T���� �ݵ�� ����Ʈ �����ڰ� �ʿ��ϴ�.

		//1. mem alloc first
		buff = static_cast<T*>( operator new(sizeof(T) * sz) );

		//2. call ctor
		int cnt = 0;
		try {			
			for (; cnt < sz; ++cnt) {
				// new (&buff[i]) T; // ����Ʈ ������ ȣ��
				new(&buff[cnt]) T(value); // ��������� ȣ��
			}
		}
		catch (...)
		{
			// ���� ������ ȣ���� ���ܰ� �߻��� ���.
			// ������ �Ϸ�� ��ü�� �Ҹ��� ȣ��.
			for (int i = 0; i < cnt; ++i)
				buff[i].~T();

			// �޸� ����
			operator delete(buff);

			// �߻��� ���ܸ� ������ ����
			throw;
		}
	}
};

int main()
{
	Point p(0, 0);
	vector<Point> v(10, p);
}
