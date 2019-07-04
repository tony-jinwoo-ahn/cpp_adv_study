#include <iostream>
#include <type_traits>
#include <vector>
#include <complex>

template<typename T> struct has_front_function
{
	typedef char YES[1]; // 143 page ArrayOfOne
	typedef char NO[2]; // short가 항상 2바이트라는 보장이 없다. 환경에 따라서. 확실하게 2개짜리로 만들자.

	// T() : T 타입의 객체 생성
	// decltype(표현식) arg: 표현식의 타입과 동일한 타입의 변수 arg

	template<typename U>
	static YES& Test(decltype(std::declval<U>().front())* arg); // 멤버함수가 있는지 디텍트 하는 기법.

	template<typename U>
	static NO& Test(...);

	static constexpr bool value =
		(sizeof(Test<T>(0)) == sizeof(YES));
};

int main()
{
	// front() 함수를 갖고있는지 조사하는 코드.

	bool b_vector = has_front_function<std::vector<int>>::value;
	bool b_complex = has_front_function<std::complex<double>>::value;// 복소수는 컨테이너가 아니므로 front() 함수가 없다.
	std::cout << b_vector << std::endl;
	std::cout << b_complex << std::endl;
}