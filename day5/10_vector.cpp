#include <iostream>
#include <type_traits>

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, T value = T()) : size(sz), capacity(sz)
	{		
		buff = static_cast<T*>(operator new(sizeof(T) * sz));		
		int cnt = 0;
		try {
			for (; cnt < sz; ++cnt) {
				// new (&buff[i]) T; // 디폴트 생성자 호출
				new(&buff[cnt]) T(value); // 복사생성자 호출
			}
		}
		catch (...)
		{			
			for (int i = 0; i < cnt; ++i)
				buff[i].~T();			
			operator delete(buff);			
			throw;
		}
	}
	~vector()
	{
		for (int i = 0; i < size; ++i) {
			buff[i].~T();
		}
		operator delete(buff);
	}
	void resize(size_t newSize, const T& value = T())
	{
		if (capacity > newSize) // memory 재할당이 필요없을 때.
		{
			if (newSize < size) // size가 줄어들 때
			{				
				for (int i = size - 1; i >= newSize; i--)
					buff[i].~T();
			}
			else // size 증가할 때
			{
				for (int i = size; i < newSize; ++i)
					new(&buff[i]) T(value); // 복사생성. 디폴트 생성자 쓰는거보다 이게 더 낫다.
					// 절대 디폴트 생성자 요구하지 마라. 복사 생성자가 더 좋은 코드다.
			}

		}
		else // memory 재할당 필요. 증가
		{
			// 1. 메모리만 먼저 할당
			T* temp = static_cast<T*>(
				operator new(sizeof(T) * newSize));

			// 2. 기존 버퍼 내용 가져오기
			if (std::is_trivially_copy_constructible_v<T>) {
				memcpy(temp, buff, sizeof(T) * size);
			}
			else {
				for (int i = 0; i < size; ++i) {
					//				temp[i] = buff[i]; // 대입연산자. 절대 대입하지마. 이 자리는 메모리만 있고 아직 자원이 없다.
					//				new (&temp[i]) T(buff[i]); // 복사 생성자. 어차피 기존꺼 필요없으므로 깊은복사보다 move가 낫다.
					//				new (&temp[i]) T(std::move(buff[i])); // move 생성자. 예외 발생하면 어쩔려구?
					new (&temp[i]) T(std::move_if_noexcept(buff[i])); // 근데 기존 내용이 trivial 하다면 어쩔래? 그래서 위에 if문 추가해서 memcpy 한다.
				}
			}
			// 새로 추가된 요소는 디폴트(또는 인자로받은 객체로 복사 생성)
			for (int i = size; i < newSize; ++i) {
				new(&temp[i]) T(value);
			}

			// 기존 버퍼 제거
			for (int i = 0; i < size; ++i)
				buff[i].~T();
			operator delete(buff);

			// 새로운 메모리를 버퍼에 연결
			buff = temp;
			size = newSize;
			capacity = newSize;
		}
	}
};

int main()
{
	vector<int> v(10);
	//v.resize(7); // cap: 10, size: 7
	v.resize(15); // 이 순간을 생각해 봅시다.
}

