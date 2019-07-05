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
				// new (&buff[i]) T; // ����Ʈ ������ ȣ��
				new(&buff[cnt]) T(value); // ��������� ȣ��
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
		if (capacity > newSize) // memory ���Ҵ��� �ʿ���� ��.
		{
			if (newSize < size) // size�� �پ�� ��
			{				
				for (int i = size - 1; i >= newSize; i--)
					buff[i].~T();
			}
			else // size ������ ��
			{
				for (int i = size; i < newSize; ++i)
					new(&buff[i]) T(value); // �������. ����Ʈ ������ ���°ź��� �̰� �� ����.
					// ���� ����Ʈ ������ �䱸���� ����. ���� �����ڰ� �� ���� �ڵ��.
			}

		}
		else // memory ���Ҵ� �ʿ�. ����
		{
			// 1. �޸𸮸� ���� �Ҵ�
			T* temp = static_cast<T*>(
				operator new(sizeof(T) * newSize));

			// 2. ���� ���� ���� ��������
			if (std::is_trivially_copy_constructible_v<T>) {
				memcpy(temp, buff, sizeof(T) * size);
			}
			else {
				for (int i = 0; i < size; ++i) {
					//				temp[i] = buff[i]; // ���Կ�����. ���� ����������. �� �ڸ��� �޸𸮸� �ְ� ���� �ڿ��� ����.
					//				new (&temp[i]) T(buff[i]); // ���� ������. ������ ������ �ʿ�����Ƿ� �������纸�� move�� ����.
					//				new (&temp[i]) T(std::move(buff[i])); // move ������. ���� �߻��ϸ� ��¿����?
					new (&temp[i]) T(std::move_if_noexcept(buff[i])); // �ٵ� ���� ������ trivial �ϴٸ� ��¿��? �׷��� ���� if�� �߰��ؼ� memcpy �Ѵ�.
				}
			}
			// ���� �߰��� ��Ҵ� ����Ʈ(�Ǵ� ���ڷι��� ��ü�� ���� ����)
			for (int i = size; i < newSize; ++i) {
				new(&temp[i]) T(value);
			}

			// ���� ���� ����
			for (int i = 0; i < size; ++i)
				buff[i].~T();
			operator delete(buff);

			// ���ο� �޸𸮸� ���ۿ� ����
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
	v.resize(15); // �� ������ ������ ���ô�.
}

