
int main()
{
	int n = 10;
	int& r = n;
	//int& & r2 = r; // ������ �־���. ���۷����� ���۷���. 
					// ���۷����� ���۷����� ���� �ڵ�� ǥ���� �� ����.

	// typedef�� �Ȱ����Ŵ�.
	using LREF = int&;
	using RREF = int&&;

	// typedef �� ���� �̷��� ���۷����� ���۷����� ǥ�� ����.
	// webkit�� scope ������ ������ �ݵ�� �̰� �˾ƾ� ��.
	// reference collapsing (�ر�) ��Ģ
	LREF& ll  = n ;	// & & => &
	LREF&& lr = n ;	// & && => &
	RREF& rl  = n ;	// && & => &
	RREF&& rr = 10;	// && && => &&

}