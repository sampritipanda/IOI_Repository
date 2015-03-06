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
string VV = "~`!@#$%^&*()-_=+{}[]\\|;:\",’<>./abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
inline void _ce(int n){
	cerr << "Compilation error in line ";
	cerr << n << endl;
	exit(0);
}
int order, ln;
typedef pair<string,int> com;
vector<com> cm;
inline bool valid(char c){
	return VV.find(c) != -1;
}
inline void read_the_code(char * cc){
	ifstream cin(cc);
	string s;
	while(cin >> s){
		ln ++;
		if(!s.size())
			continue;
		int d;
		if(cin >> d);
		else
			_ce(ln);
		if((s == "I" or s == "D")){
		       if(!(1 <= d && d <= 4))
				_ce(ln);
		       -- d;
		}
		else if(s == "T");
		else
			_ce(ln);
		cm.pb(com(s, d));

	}
	if(!ln)
		_ce(ln);
}
int s[5];
int main(int argc, char ** argv){
	iOS(false);
	if(argc < 2){
		cerr << "Code not found !\n";
		exit(0);
	}
	bool deb = 0;
	if(argc > 2 && (string)argv[2] == (string)"-d")
		deb = 1;
	read_the_code(argv[1]);
	For(i,0,4){
		cin >> s[i];
		assert(s[i] >= 0);
	}
	ln = 0;
	if(deb)
		cout << "Storages : " << s[0] << ' ' << s[1] << ' ' << s[2] << ' ' << s[3] << endl;
	while(ln >= 0 && ln < cm.size()){
		++ order;
		if(deb)
			cout << "Lin : " << ln + 1 << endl;
		string t = cm[ln].x;
		int d = cm[ln].y;
		if(t == "I")
			++ s[d], ln ++;
		else if(t == "T")
			ln += d;
		else{
			if(!s[d])
				ln ++;
			else
				-- s[d], ln += 2;
		}
		if(deb)
			cout << "Storages : " << s[0] << ' ' << s[1] << ' ' << s[2] << ' ' << s[3] << endl;
	}
	For(i,0,4)
		cout << s[i] << ' ';
	cout << endl;
	cout << "Order = " << order << endl;
}


