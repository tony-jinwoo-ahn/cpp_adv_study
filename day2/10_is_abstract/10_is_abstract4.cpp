// 143 page ��� ������

#include <iostream>
#include <type_traits>

class Shape
{
public:
	virtual void Draw() = 0;
};

template<typename T> struct is_abstract
{
	typedef char YES[1]; // 143 page ArrayOfOne
	typedef char NO[2]; // short�� �׻� 2����Ʈ��� ������ ����. ȯ�濡 ����. Ȯ���ϰ� 2��¥���� ������.

	template<typename U> static NO& Test(U(*arr)[1]);
	template<typename U> static YES& Test(...);

	static constexpr bool value = 
		(sizeof(Test<T>(0)) == sizeof(YES));
};
int main()
{
	bool b = is_abstract<Shape>::value;	
	std::cout << b << std::endl;
}
