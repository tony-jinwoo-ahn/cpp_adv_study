#include <iostream>
#include <type_traits>
#include <vector>
#include <complex>

template<typename T> struct has_front_function
{
	typedef char YES[1]; // 143 page ArrayOfOne
	typedef char NO[2]; // short�� �׻� 2����Ʈ��� ������ ����. ȯ�濡 ����. Ȯ���ϰ� 2��¥���� ������.

	// T() : T Ÿ���� ��ü ����
	// decltype(ǥ����) arg: ǥ������ Ÿ�԰� ������ Ÿ���� ���� arg

	template<typename U>
	static YES& Test(decltype(std::declval<U>().front())* arg); // ����Լ��� �ִ��� ����Ʈ �ϴ� ���.

	template<typename U>
	static NO& Test(...);

	static constexpr bool value =
		(sizeof(Test<T>(0)) == sizeof(YES));
};

int main()
{
	// front() �Լ��� �����ִ��� �����ϴ� �ڵ�.

	bool b_vector = has_front_function<std::vector<int>>::value;
	bool b_complex = has_front_function<std::complex<double>>::value;// ���Ҽ��� �����̳ʰ� �ƴϹǷ� front() �Լ��� ����.
	std::cout << b_vector << std::endl;
	std::cout << b_complex << std::endl;
}