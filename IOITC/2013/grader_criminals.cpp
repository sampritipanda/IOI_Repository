#include <cstdio>
#include <iostream>
using namespace std;

long long criminalEstimate(int N, int M, int* a, int* b);

namespace{
	static int N;
	static int M;
	
}

int main()
{
	scanf("%d%d", &N, &M);
	int* a = new int[M];
	int* b = new int[M];
	
	for(int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		
		a[i] = x;
		b[i] = y;
	}
	
	printf("%lld\n", criminalEstimate(N, M, a, b));
}
