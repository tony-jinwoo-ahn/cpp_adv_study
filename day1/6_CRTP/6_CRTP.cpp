// 6 CRTP - 195 page
#include <iostream>
using namespace std;

// Windows Template Library
template<typename T> class Window
{
public:
	void msgLoop()
	{
		//Click(); // this->Click(); // msgLoop( Window* this ) // Window::Click()

		static_cast<T*>(this)->Click();
	}
	void Click() { cout << "Window::Click 111" << endl; } // 1
};

class MyWindow : public Window<MyWindow>
{
public:
	void Click() { cout << "MyWindow::Click 22" << endl; } // 2
};

int main()
{
	MyWindow w;
	w.msgLoop();
}
