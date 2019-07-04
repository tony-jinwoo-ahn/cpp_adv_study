#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

// 5���� �߻����� ������ �ڵ�� �������? empty ��� ���
//�ݺ��� ī�װ� 5����
// �Է¹ݺ���: �Է�, ++
// ��¹ݺ���: ���, ++
// ������ �ݺ���: �Է�, ++, ��Ƽ�н� ����,     �̱۸���Ʈ �ݺ���
// ����� �ݺ���: �Է�, ++, --, ��Ƽ�н� ����, ������Ʈ �ݺ���
// �������� �ݺ���: �Է�, ++, --, +, -, [], ��Ƽ�н� ���� => ���ӵ� �޸𸮿� ���� (vector)

// �ݺ��� ī�װ� ������ Ÿ��ȭ �մϴ�
/*
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};


// �� �����̳��� �ݺ��� ����� �ڽ��� ���� ������ �ݺ�������
// �˷��־�� �մϴ�
template<typename T> class vector_iterator
{
public:
	// ��� �ݺ��� �ȿ��� �ݵ�� iterator_category�� ���ǵǾ�� �մϴ�.
	// typedef random_access_iterator_tag iterator_category; ���� ��Ÿ���̴�
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	using iterator_category = bidirectional_iterator_tag;
};
*/

template<typename T>
void advance_imp(T& p, int n, std::random_access_iterator_tag)
{
	std::cout << "��������" << std::endl;
	p = p + n;
}
template<typename T>
void advance_imp(T& p, int n, std::input_iterator_tag)
{
	std::cout << "�������� �ƴ�" << std::endl;
	while (n--) ++p;
}

template <typename T>
void advance(T& p, int n)
{
	// T: �ݺ���
	//p = p + n;
	advance_imp( p, n, typename T::iterator_category() );
}

int main()
{
	std::list<int> v = { 1,2,3,4,5 };
	auto p = v.begin();
	std::advance(p, 3);
}
