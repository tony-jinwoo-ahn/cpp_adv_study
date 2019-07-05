
template <typename T, typename Ax = std::allocator<T> > // 우리가 할당기를 지정해주지 않으면 표준꺼를 쓴다.
class vector
{
	Ax ax; // 메모리 할당기
	T* buff;
	int size;
public:
	void push_back(const T& a)
	{
		// 메모리가 부족해서 재할당해야 합니다. 어떻게 할까요?
		// new? malloc? brk? HeapAlloc?
		// 사용자가 원하는 할당기 사용가능. 이때, 해지 방법도 그에 따라 달라져야 한다. (policy)
		buff = ax.allocate(size * 1.5);
		ax.deallocate(buff, size * 1.5);
	}
};
