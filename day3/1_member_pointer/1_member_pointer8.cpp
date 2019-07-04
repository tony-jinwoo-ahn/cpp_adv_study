#include <iostream>

void foo() { std::cout << "foo" << std::endl; }

class Dialog
{
public:
	void Close() { std::cout << "dialog close" << std::endl; }
};

struct IAction
{
	virtual void Execute() = 0;
	virtual ~IAction() {}
};

// 일반함수 포인터를 관리하는 클래스
class FunctionAction : public IAction
{
	typedef void(*HANDLER)();
	HANDLER handler;
public:
	FunctionAction(HANDLER h) : handler(h) {}
	virtual void Execute() override
	{
		handler();
	}

};


template<typename T>
class MemberFunctionAction : public IAction
{
	using HANDLER = void(T::*)(); // cpp11. typedef와 유사

	HANDLER handler;
	T* target;
public:
	MemberFunctionAction(HANDLER h, T* t)
		: handler(h), target(t) {}

	virtual void Execute() override
	{
		(target->*handler)();
	}
};

// object generator 라는 기술
// 클래스 템플릿을 직접 사용하지 말고 함수 템플릿을 통해서 만들자
template<typename T>
IAction* makeAction(void(T::*handler)(), T* target) //  함수템플릿은 인자 추론 가능. 
{
	return new MemberFunctionAction<T>(handler, target);
}


IAction* makeAction(void(*handler)())
{
	return new FunctionAction(handler);
}

int main()
{
	IAction* p1 = new FunctionAction(&foo);
	p1->Execute(); // foo() 실행

	Dialog dlg;
/*
	IAction* p2 = new MemberFunctionAction<Dialog>(
		&Dialog::Close, &dlg);
*/
	//IAction* p2 = makeAction<Dialog>(&Dialog::Close, &dlg); // 원래 이렇게 타입 <Dialog> 써줘야 하는데
	IAction* p2 = makeAction(&Dialog::Close, &dlg); // 함수템플릿은 이렇게 생략 가능하므로 코드가 간결해짐.
	p2->Execute();
}
// webkit 소스 참고
// https://github.com/WebKit/webkit/blob/master/Source/WTF/wtf/Scope.h
// make 버전을 꼭 만들어줘야 함 (makeScopeExit)

/*
// 함수 템플릿
square<int>(3); // 정확한 표현.
square(3);		// 템플릿 인자 생략 가능.

// 클래스 템플릿
list<int> s(10, 3);
list s(10, 3); // cpp17 부터는 템플릿 인자 생략해도 추론 가능.
				// cpp14 까지는 반드시 표기해야 한다.
*/


