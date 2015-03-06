#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//#include "testlib.h"
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c)	for(auto &(i) : (c))
#define x     first
#define y     second
#define pb  push_back
#define PB  pop_back()
#define iOS  ios_base::sync_with_stdio
#define sqr(a)  (((a) * (a)))
#define all(a)  a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl                                                                 
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a) << endl
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define umap	unordered_map
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
//template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1e6 + 100;
string VV = "~`!@#$%^&*()-_=+{}[]\\|;:\",’<>./abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
inline void _ce(int n){
	cerr << "Compilation error in line ";
	cerr << n << endl;
	exit(0);
}
int order;
int e[maxn][30],n,cur,ln;
bool ac[maxn];
inline bool valid(char c){
	return VV.find(c) != -1;
}
inline void read_the_code(char * cc){
	ifstream cin(cc);
	string s;
	while(cin >> s){
		if((!ln && s != "N") or (ln == 1 && s != "I") or (ln == 2 && s != "A") or (ln > 2 && s != "E"))	_ce(ln + 1);
		ln ++ ;
		if(s == "N"){
			cin >> n;
			if(n < 1 or n > (int)1e6)
				_ce(ln);
			order += n;
		}
		else if(s == "I"){
			cin >> cur;
			if(cur < 1 or cur > n)
				_ce(ln);
			order ++ ;
		}
		else if(s == "A"){
			int k;
			cin >> k;
			order += k;
			if(k < 1 or k > n)
				_ce(ln);
			while(k--){
				int v;
				cin >> v;
				if(v < 1 or v > n)
					_ce(ln);
				ac[v] = 1;
			}
		}
		else{
			order ++;
			int v,u;
			char c;
			cin >> v >> c >> u;
			if(v < 1 or v > n or u < 1 or u > n or !valid(c))
				_ce(ln);
			e[v][c - 'a'] = u;
		}
	}
	if(ln < 3)
		_ce(ln);
}
int main(int argc, char ** argv){
	iOS(false);
	if(argc < 2){
		cerr << "Code not found !\n";
		exit(0);
	}
	bool deb = 0;
	if(argc > 2 && (string)argv[2] == (string)"-d")
		deb = 1;
	memset(e,-1,sizeof e);
	read_the_code(argv[1]);
	string s;
	cin >> s;
	For(i,0,s.size()){
		if(deb)
               cout << "Current state = " << cur << '\n';                      
		int x = s[i] - 'a';
		if(e[cur][x] + 1)
			cur = e[cur][x];
	}
	cout << (ac[cur] ? "Accepted" : "Rejected") << endl;
	cout << "Order = " << order << endl;
}
