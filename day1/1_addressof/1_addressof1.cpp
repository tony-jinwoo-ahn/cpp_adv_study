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
	Point pt;
	//std::cout << &pt << endl; // pt.operator&()
	
	//char& c = pt;

	//char* p = reinterpret_cast<char*>(&pt); // 0
	//char* p = &(reinterpret_cast<char>(pt)); // 0
	//char* p = &(reinterpret_cast<char&>(pt)); // 0
	/*
	Point* p = reinterpret_cast<Point*> (
		&(reinterpret_cast<double&>(pt)));
		*/

	Point* p =  (Point*)(&(reinterpret_cast<double&>(pt)));
	
	cout << p << endl;	
}
