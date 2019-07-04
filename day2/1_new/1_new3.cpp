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


	v.resize(7); // 원리를 생각해 봅시다.
				// capacity
				// 진짜로 메모리가 줄어드는건 아니다. size 수치만 변경한다.
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
	v.resize(3); // 줄어든 메모리는 파괴되지 않습니다.
				// 하지만 소멸자를 호출해야 합니다.
				// 소멸자의 명시적 호출 필요.

	v.resize(4);// 늘어난 한개의 객체를 위한 memory는 이미 할당되어 있음.
				// 존재하는 메모리에 생성자만 다시 호출 필요.
				// placement new 사용해서 명시적 생성자 호출
	cout << "************\n";
}

