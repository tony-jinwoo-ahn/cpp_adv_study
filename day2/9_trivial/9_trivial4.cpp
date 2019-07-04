#include <iostream>
#include <atomic>
#define _ENABLE_ATOMIC_ALIGNMENT_FIX


struct Point
{
	int x, y, z;
	Point() {}

	// ����ڰ� ������ ���� ������
	Point(const Point& p) : x(p.x), y(p.y), z(p.z) {} 
	
};
std::atomic<int> an;
std::atomic<Point> ap;
// ��������ڰ� �ϴ����� ����� atomic �����ִ�. 
// trivial �ؾ� �Ѵ�.
// ���������� static_assert �Ἥ trivial ������ üũ�ϰ� ������.

int main()
{
	int n = an.load(); // multi thread�� �����ϰ� load.

	Point pt = ap.load(); // ��Ƽ�����忡 ����. ������ lock free�� �ƴ�
						// �������� ����ȭ ����� �����.
						// ��κ� "busy waiting" �մϴ�.

	std::cout << an.is_lock_free() << std::endl;
	std::cout << ap.is_lock_free() << std::endl;

	/*
	// n = n+1�� ���
	__asm
	{
		mov eax, n
		add eax, 1
		mov n, eax
	}
	// ��Ƽ�����忡 �����ϰ� 1 ����
	// ���� �迭 cpu�� lock prefix ���
	__asm
	{
		lock inc n // �ϳ��� cpu�� ����� �� �ٸ� cpu�� ���� ��� �Ұ�. 
		// �ü���� ���� �ƴ�. lock free ���. OS�� lock�� ������� �ʴ´ٴ� �ǹ�.
		// cpu�� ���� ���°���.
	}
	*/

}