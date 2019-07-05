// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h"
using namespace cppmaster;

#include <map>

class Window
{
	int hwnd;
	static std::map<int, Window*> this_map;

public:
	void Create()
	{
		hwnd = ec_make_window(&handler);		
		this_map[hwnd] = this;
	}

	template <typename T>
	static int handler(int handle, int msg, int a, int b)
	{			
		T * self = static_cast<T*>(this_map[handle]);
		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->LButtonDown();
			break;
		case WM_KEYDOWN: self->KeyDown(); break;
		}
		return 0;
	}
	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};

template<typename T>
std::map<int, Window<T>*> Window<T>::this_map;

class MyWindow : public Window
{
public:
	void LButtonDown()
	{
		std::cout << "MyWindow LButton" << std::endl;
	}
};

int main()
{
	Window w;
	w.Create();
	ec_process_message();
}
