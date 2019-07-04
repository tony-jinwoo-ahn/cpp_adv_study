#include <iostream>
#include <memory>

int main()
{
	int *rp = nullptr;// raw pointer�� ������: ��ü�� �ı��� ����� �� �� ����.
	std::weak_ptr<int> wp; // �׷��� ���°� wp. ��������� �������� �ʴ� ����Ʈ������.
	
	{
		std::shared_ptr<int> sp1(new int);
		std::shared_ptr<int> sp2 = sp1; // ������� ����
		
		rp = sp1.get(); // ��¥ ������ ������
		wp = sp1;

		std::cout << sp1.use_count() << std::endl;
	}
	if (wp.expired())
	{
		std::cout << "wp: ��ü�� �ı���" << std::endl;
	}
	// weak ptr���� �� ������� ������ü�� ��μ� ���ŵ� �� �ִ�.

	// shared_ptr�� ������ü�� ���� 4���� ������
	// strong count: ��ü���� ī��Ʈ
	// weak count: ������ü �ڱ� �ڽ��� ���� ī��Ʈ (strong ptr, weak ptr ��)
	// �ڿ�
	// ������

	// make_shared ���� �ѹ��� ���ӵ� �޸𸮸� �Ҵ��ϴµ�, ������ü�� �������� ���� ���� ���־� �Ѵ�.
	// �׷��� �޸� �κ� ������ �Ұ��ϹǷ�
	// �޸� ������ ���ϰ� �ϴ�
	// �Ҹ��ڸ� �Ҹ���.
	// ���߿� weak ptr���� ���� ������� �޸� �����Ѵ�.


	// https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/RefBase.h
	// weakref_impl* const mRefs;
	// https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/RefBase.cpp#L148
	// class RefBase::weakref_impl : public RefBase::weakref_type


	if (rp != nullptr) 
	{
		std::cout << "��ü���" << std::endl;
	}

}
