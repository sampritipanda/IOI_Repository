// Library and Headcount

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int T; cin >> T;
	
	while(T--){
	    set<string> names;
	    int n; cin >> n;
	    for(int i = 0; i < n; i++){
	        string s; cin >> s;
	        if(names.count(s) == 1) names.erase(s);
	        else names.insert(s);
	    }
	    cout << names.size() << endl;
	}
	return 0;
}
