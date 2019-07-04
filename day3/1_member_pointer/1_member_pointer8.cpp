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

// object generator ��� ���
// Ŭ���� ���ø��� ���� ������� ���� �Լ� ���ø��� ���ؼ� ������
template<typename T>
IAction* makeAction(void(T::*handler)(), T* target) //  �Լ����ø��� ���� �߷� ����. 
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
	p1->Execute(); // foo() ����

	Dialog dlg;
/*
	IAction* p2 = new MemberFunctionAction<Dialog>(
		&Dialog::Close, &dlg);
*/
	//IAction* p2 = makeAction<Dialog>(&Dialog::Close, &dlg); // ���� �̷��� Ÿ�� <Dialog> ����� �ϴµ�
	IAction* p2 = makeAction(&Dialog::Close, &dlg); // �Լ����ø��� �̷��� ���� �����ϹǷ� �ڵ尡 ��������.
	p2->Execute();
}
// webkit �ҽ� ����
// https://github.com/WebKit/webkit/blob/master/Source/WTF/wtf/Scope.h
// make ������ �� �������� �� (makeScopeExit)

/*
// �Լ� ���ø�
square<int>(3); // ��Ȯ�� ǥ��.
square(3);		// ���ø� ���� ���� ����.

// Ŭ���� ���ø�
list<int> s(10, 3);
list s(10, 3); // cpp17 ���ʹ� ���ø� ���� �����ص� �߷� ����.
				// cpp14 ������ �ݵ�� ǥ���ؾ� �Ѵ�.
*/


