// 2 traits 
// 115 page int-to-type ���ó���
#include <iostream>
#include <type_traits>
using namespace std;


int main()
{
	cout << is_reference<int>::value << endl;
	cout << is_reference<int&>::value << endl;

	cout << is_const<int>::value << endl;
	cout << is_const<const int>::value << endl;
}