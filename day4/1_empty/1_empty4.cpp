#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	std::list<int> v = { 1,2,3,4,5 };
	auto p = v.begin();

	// p �� 3ĭ �����ϰ� �ͽ��ϴ�. ���� ���� �ڵ�� �����?
	//p = p + 3; // vector�� ������ list�� �ȵ�
	std::advance(p, 3); // ���������̸� +3, �������پƴϸ� ++ �� 3�� ����.
	// 1. ������ ������ advance() ����.
	// 2. �׷� �� �Լ��� ��� ����ɱ�?

}
