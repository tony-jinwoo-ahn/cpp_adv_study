// 7 예외 안전성2 - 59 page

// 상태바꾸기 전에 조사부터 하자.
#include <iostream>
#include <exception>
using namespace std;

template<typename T> class Stack
{
	T buff[10];
	int idx = -1;
public:
	void push(const T& a) { buff[++idx] = a; }
	/*
	T pop()
	{		
		if (idx < 1)
			throw std::out_of_range("stack empty");

		--idx;
		return buff[idx];
	}
	*/
	// 제거와 반환을 동시에 하면 강력 보장을 지킬 수 없다.
	// 제거와 반환은 분리한다.
	T& top() { return buff[idx]; } // 반환만.
	void pop() { --idx; }//제거만.
};

class People {};

int main()
{
	Stack<People> s;
	People p;
	s.push(p);

	try
	{
/*
		People p = s.pop(); // 1. s.pop() 호출
							// 2. People 의 복사 생성자 호출
							//	=> 여기서 예외가 발생하면 스택에 item은 남겨져 있어야 하는데 이미 꺼내고 없다.
							// 그래서 강력보장이 안됨.
*/

		People p = s.top(); // 꺼내기만. 은행에서 돈부터 받아서 손에 쥐고 그담에 계좌에서 돈이 빠져나가야 한다.
		s.pop(); // 제거만. 위에서 복사생성자에 문제가 생겼더라도 스택은 상태가 변하지 않은채 안전하게 보존되어 있다.
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}
	// STL에서 pop 하면 반환과 리턴을 동시에 하는경우가 없다. 제거/반환 중에 한번에 하나만 한다.
	//1. 예외 안전성의 강력보장을 지키기 위해
	//2. 참조반환을 통해서 임시객체를 제거하기 위해
}
