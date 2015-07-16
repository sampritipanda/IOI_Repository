// Infinite House of Pancakes

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T; cin >> T;
	
	for(int t = 1; t <= T; t++){
		int D; cin >> D;
		int dishes[D];
		int max_time = 0;
		for(int i = 0; i < D; i++){
			cin >> dishes[i];
			max_time = max(max_time, dishes[i]);
		}
		
		int min_pos_time = max_time;
		for(int i = 1; i <= max_time; i++){
			int curr_time = i;
			for(int j = 0; j < D; j++) curr_time += (dishes[j] - 1)/i;
			min_pos_time = min(min_pos_time, curr_time);
		}
		
		cout << "Case #" << t << ": " << min_pos_time << endl;
	}
}
