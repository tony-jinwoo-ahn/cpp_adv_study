#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>


//�ݺ��� ī�װ� 5����
// �Է¹ݺ���: �Է�, ++
// ��¹ݺ���: ���, ++
// ������ �ݺ���: �Է�, ++, ��Ƽ�н� ����,     �̱۸���Ʈ �ݺ���
// ����� �ݺ���: �Է�, ++, --, ��Ƽ�н� ����, ������Ʈ �ݺ���
// �������� �ݺ���: �Է�, ++, --, +, -, [], ��Ƽ�н� ���� => ���ӵ� �޸𸮿� ���� (vector)


// �ݺ����� ����
// 1. Ŭ������ ������� ��ü ����
// 2. raw pointer
// �� 2���� �������� �ذ��ϴ� ����
template<typename T> struct iterator_traits
{
	using iterator_category = typename T::iterator_category;
};
template<typename T> struct iterator_traits<T*>
{
	//using iterator_category = ???
	// �����ʹ� �������� �ٵǴ� �������� �ݺ����̴�. ���� �Ʒ��� ����...
	using iterator_category = std::random_access_iterator_tag;	
};

template <typename T>
void advance(T& p, int n)
{
	advance_imp(p, n, typename std::iterator_traits<T>::iterator_category());
}

int main()
{
	int v[5] = { 1,2,3,4,5 };
	auto p = std::begin(v);
	std::advance(p, 3);
}
