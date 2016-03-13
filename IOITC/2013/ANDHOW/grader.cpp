#include <cstdio>

using namespace std;

void solve(int N, bool *ans);

namespace{
const int max_N = 25000; 
int Q = 300; 

bool included[max_N] = {0};

bool ans[max_N];

int N;

}

int main()
{
	int K;
	scanf("%d %d", &N, &K);
	if(K > N)
	{
		printf("Invalid input : the number of included variables cannot be more than the total number of variables.\n");
		return 0;
	}
	for(int i=0; i<K; ++i)
	{
		int x;
		scanf("%d", &x);
		if(x < 0 || x >= N)
		{
			printf("Invalid input : %d is not in the range [0, %d).\n", x, N);
			return 0;
		}
		included[x] = true; //Indices are 0-based!
	}
	
	solve(N, ans);
	
	for(int i=0; i<N; ++i)
		if(ans[i] != included[i])
		{
			fprintf(stderr, "Answer is wrong for variable %d.\n", i);
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
}

bool query(const bool *q)
{
	if( --Q < 0)
	{
		fprintf(stderr, "Too many queries.\n");
		printf("NO");
	}
	bool res = true;
	for(int i=0; i<N; ++i)
		if(included[i])
			res = res && q[i];
	return res;
}
