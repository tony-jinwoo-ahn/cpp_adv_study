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

// �Ϲ��Լ� �����͸� �����ϴ� Ŭ����
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
	using HANDLER = void(T::*)(); // cpp11. typedef�� ����
	
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

int main()
{
	IAction* p1 = new FunctionAction(&foo);
	p1->Execute(); // foo() ����

	Dialog dlg;
	IAction* p2 = new MemberFunctionAction<Dialog>(
		&Dialog::Close, &dlg);

	p2->Execute();
}
