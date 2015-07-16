// Black-white Board Game 

#include <iostream>
#include <algorithm>

using namespace std;

int inversion_count(vector<int>& permut){
	int count = 0;
	int N = permut.size();
	for (int i = 0; i < (N - 1); i++){
		for (int j = i + 1; j < N; j++){
			if (permut[i] > permut[j]) count++;
		}
	}
	return count;
}

int main() {
	int T; cin >> T;

	while (T--){
		int alex = 0, fedor = 0;

		int N; cin >> N;
		bool black[N + 1][N + 1];
		for (int i = 0; i <= N; i++){
			for (int j = 0; j <= N; j++){
				black[i][j] = false;
			}
		}

		for (int i = 1; i <= N; i++){
			int L, R; cin >> L >> R;
			for (int j = L; j <= R; j++) black[i][j] = true;
		}

		vector<int> permut; for (int i = 1; i <= N; i++) permut.push_back(i);
		do {
			bool flag = true;
			for (int i = 0; i < N; i++){
				if (!black[i + 1][permut[i]]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				if (inversion_count(permut) % 2 == 0) alex++;
				else fedor++;
			}
		} while (next_permutation(permut.begin(), permut.end()));

		if (alex > fedor) cout << "Alex" << endl;
		else if (fedor > alex) cout << "Fedor" << endl;
		else cout << "Draw" << endl;
	}
}