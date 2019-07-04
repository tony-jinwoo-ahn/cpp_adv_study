#include <iostream>
#include <type_traits>

class Point
{
	int x, y;
public:
//	Point() {}
	Point(int a, int b) : x(a), y(b) {}
	int foo() { return 0; }
};

// Point& declval(); // �ٽ�: ������ �����ϴ�.

template<typename T> T& declval();

int main()
{
//	int n = sizeof(Point().foo()); // ����: �ݵ�� ����Ʈ �����ڰ� �־�� ������ �ڵ�.

//	int n = sizeof(declval().foo()); // �򰡵��� �ʴ� �Լ��̹Ƿ� ������ �ʿ����. 
	// �����Ϸ��� Point ��ü�� ��ȯ�Ǿ�´ٰ� ������.

//	int n = sizeof(declval<Point>().foo());

	int n = sizeof(std::declval<Point>().foo());
	// �򰡵��� �ʴ� ǥ���Ŀ��� ��ü ���̵� ����Ʈ �����ڸ� �θ��� ���� �� ���.
	// ������ �ð��� �����ϰ� ������ ���� �� ����� �޸�Ʈ �ִ� ���.

}
