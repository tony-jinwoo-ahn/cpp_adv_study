#include <iostream>

// �Ϲ��Լ� ������
// ����Լ� ������
// poco

class Button
{
	//void(*handler)();
	void(Dialog::*handler)();
	Dialog* target;

public:
	void Click()
	{
		// Ŭ���� ����� �ܺο� �˸����� ��.
		handler();
	}
};

int main()
{
	Button btn;
	btn.Click(); // ����ڰ� ��ư�� ������ �� �Լ��� ȣ��ȴٰ� 
				// �����غ��ô�.

}
