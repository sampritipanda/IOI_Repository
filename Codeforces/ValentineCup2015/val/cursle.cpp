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
struct com{
	string s;
	char x;
	int d;
};
vector<com> cm;
string VV = "~`!@#$%^&*()-_=+{}[]\\|;:\",’<>./abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
inline void _ce(int n){
	cerr << "Compilation error in line ";
	cerr << n << endl;
	exit(0);
}
int order,ln;
inline bool valid(char c){
	return VV.find(c) != -1;
}
inline void read_the_code(char * cc){
	ifstream cin(cc);
	string s;
	while(cin >> s){
		ln ++;
		com C;
		C.s = s;
		if(s == "C"){
			char x;
			cin >> x;
			if(!valid(x))
				_ce(ln);
			C.x = x; 
		}
		else if(s == "T"){
			int d;
			cin >> d;
			C.d = d;
		}
		else if(s == "X");
		else if(s == "A"){
			char x;
			cin >> x;
			if(!valid(x))
				_ce(ln);
			C.x = x;
		}
		else if(s == "N");
		else if(s == "P");
		else
			_ce(ln);
		cm.pb(C);
	}
}
deque<char> a,b;
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
	string s;
	cin >> s;
	int cur = 0;
	For(i,0,s.size())
		b.pb(s[i]);
	if(deb)
	       cout << "Curren string: " << s << " ,Current position of pointer: " << cur + 1 << endl;
	while(a.size() + b.size() && cur > -1 && cur < cm.size()){
		string t = cm[cur].s;
		++ order;
		char c = b.front();
		if(t == "C"){
			if(c == cm[cur].x)
				cur ++;
			else
				cur += 2;
		}
		else if(t == "T")
			cur += cm[cur].d;
		else if(t == "X"){
			b.pop_front();
			if(!a.size() && !b.size())
				break;
			if(!b.size()){
				b.pb(a.back());
				a.PB;
			}
			cur ++;
		}
		else if(t == "A")
			a.pb(cm[cur++].x);
		else if(t == "N"){
			if(b.size() > 1){
				a.pb(b.front());
				b.pop_front();
			}
			cur ++;
		}
		else{
			if(a.size()){
				b.push_front(a.back());
				a.PB;
			}
			cur ++;
		}
		if(deb)
	       cout << "Curren string: " << s << " ,Current position of pointer: " << cur + 1 << endl;
	}
	For(i,0,a.size())
		cout << a[i];
	For(i,0,b.size())
		cout << b[i];
	cout << endl << "Order = " << order << endl;

}
