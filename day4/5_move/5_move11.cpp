#include <iostream>
#include <string>
#include <vector>


class Test
{
	int data;
	std::string s = "hello";
public:
	Test() {}
	~Test() {}
	Test(const Test& t) : data(std::move(t.data)), s(std::move(t.s))
	{
		std::cout << __FUNCSIG__ << std::endl;
	}
	Test& operator=(const Test& t) {
		data = t.data;
		s = std::move(t.s);

		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}
	

	Test(Test&& t) noexcept (
		std::is_nothrow_move_constructible<std::string>::value)
		: data(t.data), s(std::move(t.s))
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	Test& operator=(Test&& t) noexcept (
		std::is_move_assignable<std::string>::value)
	{
		data = t.data;
		s = std::move(t.s);
		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}
};

// �߿��� �̾߱�
class Object
{
	Test data;
public:
	Object() {}
	//void setData(Test d) { data = d; }

	// setter ����� 1. const ���� - �׻� ���� ���
	//void setData(const Test& d) { data = d; } // �̰Ŵ� �׻� �����̴�

	// �Ʒ� �ڵ� ���� �׻� ���� (const�� move�� �� ����.)
	void setData(const Test& d) { data = std::move(d); } // �̰ŵ� move�� �� ������ �տ� const�� �پ��־ �����.

	// setter 2. 2���� ������
	// const& ������ && �������� 2�� ������
	void setData(const Test& d) { data = d; }
	void setData(Test&& d) { data = std::move(d); }

	// setter 3. call by value �� ���� ���ܱ�?
	// void setData(Test d) { data = std::move(d); }
	// move �� ����� �����ٸ� 2������������ call by value�ε� ���� ������.
	// 2�� �� move �ϴ°� ���� ���� ������.

	// setter 4. forwarding reference
	template<typename T> void setData(T&& d) // �׻� d�� lvalue�ε�, ������ ���� �ٸ��� �ϰ������ forward() ����.
	{
//		data = d;				// 1 ������ ����
//		data = std::move(d);	// 2 ������ move
		data = std::forward<T>(d);	// 3 
	}
	// modern cpp���� setter ����� ��
	// 2�� ����°� ���� �Ǹ��ϴ�. 
};


int main()
{
	Object obj;
	Test data;
	obj.setData(data);				// ���� ���� 1ȸ
									// ������� 1ȸ, move���� 1ȸ �Ҹ���.
	obj.setData(std::move(data));	// move ���� 1ȸ. move�� �Ű����� �ڿ��ս�.
									// move���� 1ȸ, move���� 1ȸ
}
