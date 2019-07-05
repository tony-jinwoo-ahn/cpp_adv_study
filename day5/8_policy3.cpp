#include <iostream>
#include <vector>

struct Point
{
	int x, y;
	Point(int a=0, int b=0) { std::cout << __FUNCSIG__ << std::endl; }
	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};
int main()
{
	std::allocator<Point> ax;
	Point* p1 = ax.allocate(2);

	ax.construct(&p1[0], 1, 2); // 생성자 호출
	ax.construct(&p1[1], 1, 2);

	ax.destroy(&p1[0]);
	ax.destroy(&p1[1]);

	ax.deallocate(p1, 2);
	//std::vector<
}
