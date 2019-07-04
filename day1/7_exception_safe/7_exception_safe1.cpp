// 7 예외 안전성1 - 59 page
#include <iostream>
#include <exception>
using namespace std;

template<typename T> class Stack
{
	T buff[10];
	int idx = 0;
public:
	void push(const T& a) { buff[idx++] = a; }
	T pop()
	{
		--idx;
		if (idx < 0)	
			throw std::out_of_range("stack empty");

		return buff[idx];
	}
};

int main()
{
	Stack<int> s;

	try	
	{
		s.pop();
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}	
	// 여기서 s 를 계속 사용해도 될까?
	// 계속 쓰고 싶다. 쓸수있게! 
	//예외안전성 (exception safety)
	//1. 완전보장: 예외가 없다. ex) int n=0 혹은 int* p = nullptr; 절대 예외가 안나옴.
	//2. 강력보장: 예외가 있지만 잡아서 처리하면 객체의 상태는 예외발생 이전 상태가 된다. 계속 사용 가능.
	//3. 기본보장: 예외가 발생해도 잡으면 자원 누수는 없다. 메모리 낭비같은건 없다.
	//				단, 객체의 상태는 알 수 없다. 더이상 사용 불가.

}
