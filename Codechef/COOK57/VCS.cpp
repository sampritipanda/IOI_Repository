// Version Control System

#include <iostream>
#include <set>

using namespace std;

int main() {
	int T; cin >> T;
	
	while(T--){
		int N, M, K; cin >> N >> M >> K;
		set<int> ignored, tracked;
		while(M--){
			int a; cin >> a; ignored.insert(a);
		}
		while(K--){
			int a; cin >> a; tracked.insert(a);
		}
		
		int type1 = 0, type2 = 0;
		for(int i = 1; i <= N; i++){
			if(ignored.count(i) > 0 && tracked.count(i) > 0) type1++;
			else if(ignored.count(i) == 0 && tracked.count(i) == 0) type2++;
		}
		
		cout << type1 << " " << type2 << endl;
	}
}