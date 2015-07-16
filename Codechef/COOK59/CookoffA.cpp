#include <bits/stdc++.h>
#define MOD 1000000007
#define rf freopen("inp.in","r",stdin)
#define wf freopen("outp.out","w",stdout)
#define NMAX 100050
#define INF 1000000006

using namespace std;

long long A[NMAX];
int T , N ;
long long ANS[NMAX];
map<int,vector<int> > M;

int main(){
	cin >> T;

	while(T--){

		M.clear();
		cin >> N;
		memset(ANS,0,sizeof ANS);
		long long sum = 0;
		for(int i = 1 ; i <=N;i++){
			 cin >> A[i];
			 sum = sum xor A[i];
			 for(int j = 0 ; j < M[sum].size() ;j++) ANS[ (i - (M[sum][i] + 1) ) +1 ]++;
			 M[sum].push_back(i);
		}
		for(int i = 1 ; i <= N ; i++) cout << ANS[i] << " ";
		cout << endl;
	}
}
