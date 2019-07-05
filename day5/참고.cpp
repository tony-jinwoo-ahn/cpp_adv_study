// 참고
template<typename T> struct Test
{
	typedef T types;
	template<typename U> struct Object {};
};
template<typename T> void foo(T a)
{
	// T 안에 type 형태의 변수 n 만들어 보세요
	// T Object "" o
	typename T::type n; // 템플릿에 의존적인 타입을 꺼낼 때.
//	typename T::Object<double> o; // error. Object가
									// 템플릿이라는 사실을 모른다.
	typename T::template Object<double> o; // ok. 템플릿에 의존적인 템플릿을 꺼낼 때.
}
int main()
{
	Test<int>::types n; // int
	Test<int>::Object<double> o;

	Test<int> t;
	foo(t);
}
