#include <iostream>
#include <vector>
using namespace std;

/*
int main()
{
	// 1. vector's memory management technique!
	std::vector<int> v(100);
	cout << v.size() << endl;
	cout << v.capacity() << endl;


	v.resize(7); // ������ ������ ���ô�.
				// capacity
				// ��¥�� �޸𸮰� �پ��°� �ƴϴ�. size ��ġ�� �����Ѵ�.
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.push_back(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.shrink_to_fit();
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.push_back(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.shrink_to_fit();
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.push_back(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

}
*/

class DBConnect
{
public:
	DBConnect() { cout << "connect DB" << endl; }
	~DBConnect() { cout << "DisConnect DB~" << endl; }
};

int main()
{
	vector<DBConnect> v(5);
	v.resize(3); // �پ�� �޸𸮴� �ı����� �ʽ��ϴ�.
				// ������ �Ҹ��ڸ� ȣ���ؾ� �մϴ�.
				// �Ҹ����� ����� ȣ�� �ʿ�.

	v.resize(4);// �þ �Ѱ��� ��ü�� ���� memory�� �̹� �Ҵ�Ǿ� ����.
				// �����ϴ� �޸𸮿� �����ڸ� �ٽ� ȣ�� �ʿ�.
				// placement new ����ؼ� ����� ������ ȣ��
	cout << "************\n";
}

