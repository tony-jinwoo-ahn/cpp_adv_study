// ����
template<typename T> struct Test
{
	typedef T types;
	template<typename U> struct Object {};
};
template<typename T> void foo(T a)
{
	// T �ȿ� type ������ ���� n ����� ������
	// T Object "" o
	typename T::type n; // ���ø��� �������� Ÿ���� ���� ��.
//	typename T::Object<double> o; // error. Object��
									// ���ø��̶�� ����� �𸥴�.
	typename T::template Object<double> o; // ok. ���ø��� �������� ���ø��� ���� ��.
}
int main()
{
	Test<int>::types n; // int
	Test<int>::Object<double> o;

	Test<int> t;
	foo(t);
}
