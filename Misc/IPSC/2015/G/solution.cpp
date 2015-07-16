#include <bits/stdc++.h>
#define MOD 1000000007
#define NMAX 100050

using namespace std;

int N ,C , Q , T;
vector<int>adjList[NMAX];
long long VAL[NMAX];

void dfs(int node , int dep ,int imp){
	if(dep==-1)return;
	VAL[node] = imp;
	int sz = adjList[node].size();
	for(int i = 0 ; i < sz ; i++){
		int ne = adjList[node][i];
		dfs(ne,dep-1,imp);
	}
}
int main(){
	cin >> T;

	while(T--){

		cin >> N >> C >> Q;
		
		for(int i = 0 ; i <= N ; i++)
			adjList[i].clear();

		for(int i = 2 ; i <= N ; i++){
			int par ; cin >> par;			
			adjList[par].push_back(i);
		}

		for(int i = 1 ; i <=N ; i++) VAL[i] = 1LL;

	    long long idx = 1 ;
		long long ans = 0 ;

		while(Q--){
			int a , b , c;
			cin >> a >> b >> c;
			if(c==0) ans = (ans+((VAL[a]*idx) % MOD))%MOD;
		    else   dfs(a,b,c);
		    idx++;
	   }
       cout << ans << endl;
   }
}
