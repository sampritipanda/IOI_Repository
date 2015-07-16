// Dijkstra

#include <iostream>
#include <string>

using namespace std;

inline int abs(int a) {
	return (a < 0) ? -a : a;
}

int main() {
	int T; cin >> T;
	// 1 = 1, 2 = i, 3 = j, 4 = k
	int multiple_table[5][5] = {
		{0, 0, 0, 0, 0},
		{0, 1, 2, 3, 4},
		{0, 2, -1, 4, -2},
		{0, 2, -3, -1, 2},
		{0, 3, 2, -2, -1}
	};
	
	for(int t = 1; t <= T; t++){
		int L, X; cin >> L >> X;
		string part; cin >> part;
		string str = "";
		int expr[L * X];
		for(int i = 0; i < X; i++) str += part;
		for(int i = 0; i < str.length(); i++) {
			if(str[i] == 'i') expr[i] = 2;
			else if(str[i] == 'j') expr[i] = 3;
			else expr[i] = 4;
		}
		int len = L*X;
		
		bool flag = false;
		for(int i = 1; i < len - 1; i++){
			for(int j = i + 1; j < len; j++){
				int first_val = expr[0];
				for(int k = 1; k < i; k++){
					int curr_sign = first_val/abs(first_val);
					first_val = multiple_table[abs(first_val)][expr[k]] * curr_sign;
				}
				
				int second_val = expr[i];
				for(int k = i; k < j; k++){
					int curr_sign = second_val/abs(second_val);
					second_val = multiple_table[abs(second_val)][expr[k]] * curr_sign;
				}
				
				int third_val = expr[j];
				for(int k = j; k < len; k++){
					int curr_sign = third_val/abs(third_val);
					third_val = multiple_table[abs(third_val)][expr[k]] * curr_sign;
				}
				
				cout << i << " " << j << ": " << first_val << " " << second_val << " " << third_val << endl;
				
				if(first_val == 2 && second_val == 3 && third_val == 4){
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		
		if(flag) cout << "Case #" << t << ": " << "YES" << endl;
		else cout << "Case #" << t << ": " << "NO" << endl;
	}
}