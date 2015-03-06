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
typedef pair<string,string> com;
vector<com> cm;
inline bool valid(char c){
	return VV.find(c) != -1;
}
inline void read_the_code(char * cc){
	ifstream cin(cc);
	string s;
	while(cin >> s){
		if(!s.size())
			continue;
		ln ++;
		For(i,0,s.size())
			if(!valid(s[i]))
				_ce(ln);
		if(s[0] != '(')
			_ce(ln);
		if(s[s.size()-1] != ')')
			_ce(ln);
		int x = s.find(',');
		if(x == -1)
			_ce(ln);
		string X,Y;
		For(i,1,x)
			X += s[i];
		For(i,x+1,s.size()-1)
			Y += s[i];
		if(!X.size())
			_ce(ln);
		if(X.find('(') + 1 or X.find(',') + 1 or X.find(')') + 1 or Y.find('(') + 1 or Y.find(',') + 1 or Y.find(')') + 1 )
			_ce(ln);
		cm.pb(com(X,Y));
	}
	if(!ln)
		_ce(ln);
}
inline vi prefix(string s){
	int m = s.size();
	vi p;
	p.pb(-1);
	int k = -1;
	For(q,1,m){
		while(k > -1 && s[k+1] != s[q])
			k = p[k];
		if(s[k + 1] == s[q])
			k++;
		p.pb(k);
	}
	return p;
}
string s;
inline int KMP(string p){
	int n = s.size(), m = p.size();
	vi v = prefix(p);
	int q = -1;
	For(i,0,n){
		while(q > -1 && p[q+1] != s[i])
			q=v[q];
		if(p[q+1] == s[i])
			q++;
		if(q == m-1){
			return i - m + 1;
			q=v[q];
		}
	}
	return -1;
}
inline void replace(int r){
	string t;
	if(r)
		t += s.substr(0, r);
	t += cm[ln].y;
	int x = r + cm[ln].x.size();
	if(x - s.size())
		t += s.substr(x,s.size() - x);
	s = t;
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
	read_the_code(argv[1]);
	cin >> s;
	if(deb)
		cout << "Current string: " << s << '\n';
	ln = 0;
	while(ln < cm.size()){
		int r = KMP(cm[ln].x);
		order += s.size() + cm[ln].x.size() + cm[ln].y.size();
		if(r + 1){
			replace(r);
			if(deb)
				cout << "Current string: " << s << '\n';
			ln = 0;
		}
		else
			ln ++;
	}
	cout << s << endl;
	cout << "Order = " << order << endl;
}

