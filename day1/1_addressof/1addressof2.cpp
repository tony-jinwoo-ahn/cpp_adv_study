#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	// �ּҸ� ��Ÿ�� ���� 0 ��� nullptr�� ������� - C++11
	Point* operator&() const { return NULL; }

};

int main()
{
	//Point pt;
	const Point pt;
	Point* p = reinterpret_cast<Point*>(
		&(reinterpret_cast<char&> (
			const_cast<Point&>(pt))));



	cout << p << endl;
}
