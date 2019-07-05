#include <iostream>
class Vector
{
public:
	explicit Vector(int size) {}
	explicit Vector(int size, int value) { std::cout << "1" << std::endl; }
	Vector(std::initializer_list<int> s) { std::cout << "2" << std::endl; }
};

int main()
{
	Vector v4 = 10; // error
	Vector v5 = { 10 }; // ok

	Vector v1(10, 3); //  1번 생성자
	Vector v2{ 10, 3 };// 2번 생성자, 없으면 1번 사용
	Vector v3{ 10, 3,1,2,3,4,5,6,7 };
}
