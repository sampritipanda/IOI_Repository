// SMS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MOD 100000007

int keys_3[1000001];
int keys_4[1000001];

int main() {
	int T; cin >> T;
	string seq[26] = { "2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999" };
	int num_keys[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
	
	keys_3[0] = 0; keys_3[1] = 1; keys_3[2] = 2;
	for(int i = 3; i <= 1000000; i++) keys_3[i] = (1 + keys_3[i - 1] + keys_3[i - 2] + keys_3[i - 3]) % MOD;
	keys_4[0] = 0; keys_4[1] = 1; keys_4[2] = 2; keys_4[3] = 4; 
	for(int i = 3; i <= 1000000; i++) keys_4[i] = (1 + keys_4[i - 1] + keys_4[i - 2] + keys_4[i - 3] + keys_4[i - 4]) % MOD;
	
	while(T--){
		string s; cin >> s;
		int N = s.length();
		string keys = "";
		for(auto c: s) keys += seq[c - 'a'];
		vector<pair<char, int> > letters;     // key, length
		int i = 1; char prev = keys[0];
		int curr_length = 1;
		while(i < keys.length()) {
			if(keys[i] == prev){
				curr_length++;
				i++;
			}
			else{
				letters.push_back({prev, curr_length});
				curr_length = 1;
				prev = keys[i];
				i++;
			}
		}
		if(curr_length > 0) letters.push_back({prev, curr_length});
		
		long long ans = 1;
		for(auto it: letters) ans = (ans * (num_keys[it.first - '0'] == 3 ? keys_3[it.second] : keys_4[it.second])) % MOD;
		
		cout << ans << endl;
	}
}
