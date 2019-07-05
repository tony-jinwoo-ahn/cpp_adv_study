// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h"
using namespace cppmaster;

#include <map>

// �ٽ�2. this�� �ڷᱸ���� �����ϴ� ���
class Window
{
	int hwnd;
	static std::map<int, Window*> this_map;

public:
	void Create()
	{
		hwnd = ec_make_window(&handler);

		// ������ ��ȣ�� Ű������ this ����
		this_map[hwnd] = this;
	}

	// �ٽ� 1. �Ʒ� �Լ��� �ݵ�� static ��� �Լ��� �Ǿ�� �մϴ�. 
	//(�Ķ���Ϳ� this �� �Ѿ���� ���ϰ�.)
	//Window* this �� �߰��Ǹ� ���ڰ� 5���� �Ǿ�����ϱ�.
	static int handler(int handle, int msg, int a, int b)
	{
		// ���� ������ ��ȣ�� ������ this�� ���´�.
		Window* self = this_map[handle];

		switch (msg)
		{
		case WM_LBUTTONDOWN: 
			self->LButtonDown();  // this->LButtonDown() �ε�, �̰� static �Լ��� this ����.
			break;
		case WM_KEYDOWN: self->KeyDown(); break;
		}
		return 0;
	}
	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};
std::map<int, Window*> Window::this_map;

class MyWindow : public Window
{
public:
	virtual void LButtonDown() override
	{
		std::cout << "MyWindow LButton" << std::endl;
	}
	virtual void KeyDown() override
	{
		std::cout << "MyWindow KeyDown" << std::endl;
	}
};

int main()
{
	Window w;
	w.Create();
	ec_process_message();
}
