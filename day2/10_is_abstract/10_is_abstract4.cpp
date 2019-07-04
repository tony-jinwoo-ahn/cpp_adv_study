// 143 page 멤버 디텍터

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
	typedef char NO[2]; // short가 항상 2바이트라는 보장이 없다. 환경에 따라서. 확실하게 2개짜리로 만들자.

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
