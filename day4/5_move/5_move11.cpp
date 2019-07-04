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

// 중요한 이야기
class Object
{
	Test data;
public:
	Object() {}
	//void setData(Test d) { data = d; }

	// setter 만들기 1. const 참조 - 항상 복사 사용
	//void setData(const Test& d) { data = d; } // 이거는 항상 복사이다

	// 아래 코드 역시 항상 복사 (const는 move될 수 없다.)
	void setData(const Test& d) { data = std::move(d); } // 이거도 move될 거 같지만 앞에 const가 붙어있어서 복사다.

	// setter 2. 2개를 만들자
	// const& 버전과 && 버전으로 2개 만들자
	void setData(const Test& d) { data = d; }
	void setData(Test&& d) { data = std::move(d); }

	// setter 3. call by value 는 아주 나쁠까?
	// void setData(Test d) { data = std::move(d); }
	// move 가 충분히 빠르다면 2개만들지말고 call by value로도 만들어도 괜찮다.
	// 2개 다 move 하는게 물론 가장 빠르다.

	// setter 4. forwarding reference
	template<typename T> void setData(T&& d) // 항상 d는 lvalue인데, 원본에 따라 다르게 하고싶으면 forward() 쓰라.
	{
//		data = d;				// 1 무조건 복사
//		data = std::move(d);	// 2 무조건 move
		data = std::forward<T>(d);	// 3 
	}
	// modern cpp에서 setter 만드는 법
	// 2개 만드는게 가장 훌륭하다. 
};


int main()
{
	Object obj;
	Test data;
	obj.setData(data);				// 복사 대입 1회
									// 복사생성 1회, move대입 1회 불린다.
	obj.setData(std::move(data));	// move 대입 1회. move로 옮겼으니 자원손실.
									// move생성 1회, move대입 1회
}
