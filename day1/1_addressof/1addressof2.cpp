#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	// 주소를 나타낼 때는 0 대신 nullptr을 사용하자 - C++11
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
