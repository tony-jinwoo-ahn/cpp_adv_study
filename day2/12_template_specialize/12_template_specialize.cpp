//템플릿 부분 특수화
#include <iostream>

// primary template
template<typename T> class Stack
{
public:
	void push(T a) { std::cout << "T" << std::endl; }
};

// partial specialization
template<typename T> class Stack<T*>
{
public:
	void push(T* a) { std::cout << "T *" << std::endl; }
};

// specialization
template</* empty */> class Stack<char*>
{
public:
	void push(char* a) { std::cout << "char *" << std::endl; }
};

// 템플릿은 틀일 뿐.
// 스택 클래스는 3개가 만들어짐
// 최종적으로 인스턴스는 3개.
int main()
{
	Stack<int>   s1; s1.push(0);
	Stack<int*>  s2; s2.push(0);
	Stack<char*> s3; s3.push(0);

}
