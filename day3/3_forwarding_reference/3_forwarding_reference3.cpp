
int main()
{
	int n = 10;
	int& r = n;
	//int& & r2 = r; // 공백을 넣었다. 레퍼런스의 레퍼런스. 
					// 레퍼런스의 레퍼런스를 직접 코드로 표현할 수 없다.

	// typedef랑 똑같은거다.
	using LREF = int&;
	using RREF = int&&;

	// typedef 일 때는 이렇게 레퍼런스의 레퍼런스를 표현 가능.
	// webkit의 scope 같은거 보려면 반드시 이거 알아야 함.
	// reference collapsing (붕괴) 규칙
	LREF& ll  = n ;	// & & => &
	LREF&& lr = n ;	// & && => &
	RREF& rl  = n ;	// && & => &
	RREF&& rr = 10;	// && && => &&

}