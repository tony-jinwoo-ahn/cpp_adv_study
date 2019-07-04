// 7 예외 안전성3 - 59 page
// copy and swap
// 대입연산자 짤때는 copy & swap이 가장 훌륭하다.

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class String2
{
public:
	char* buff;

public:
	String2(const char* str)
	{
		buff = new char[strlen(str) + 1];
		strcpy(buff, str);
	}
	String2(const String2& s)
	{
		buff = new char[strlen(s.buff) + 1];
		strcpy(buff, s.buff);
	}
	~String2() { delete[] buff; }	
	void swap(String2& s)
	{
		char* temp = s.buff;
		s.buff = buff;
		buff = temp;
	}
/*
	// deep copy
	String2& operator=(const String2& s)
	{
		// 자신과 대입일 경우 (s1 == s1)
		if (&s == this) return *this;

		// 자신버퍼 제거
		delete[] buff;
		// 새로운 버퍼 할당
		buff = new char[strlen(s.buff) + 1]; // memory 부족시 예외발생
		// deep copy
		strcpy(buff, s.buff);	
		return *this;
	}
*/

	String2& operator=(const String2& s)
	{
		// 자신과 대입일 경우 (s1 == s1)
		if (&s == this) return *this;

		// s의 복사본을 만든다. (copy)
		String2 temp(s); // RAII

		// 이런식으로 메모리 할당하면 나중에 직접 delete 해야하니까 실수할까봐 부담된다.
		// char* temp = new char[];

		// s의 버퍼와 자신의 버퍼를 교체한다.(swap)
		temp.swap(*this);// 이제 나는 새로 받은 s 를 갖게 되었다. 
						// temp는 옛날꺼를 갖게 되었다.

		return *this;
	}// 저절로 temp가 파괴되면서 소멸자가 불리면서 buff가 자동적으로 삭제된다.(RAII)
};
using namespace std;
int main()
{
	String2 s1("hello");
	String2 s2("AAA");
	s1 = s2;
	cout << s1.buff << endl;
	cout << s2.buff << endl;
}
