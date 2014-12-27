// VIDEOGAME

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, H;
	cin >> N >> H;
	int stacks[N];
	for(int i = 0; i < N; i++){
		cin >> stacks[i];
	}
	int crane = 0;
	bool has_box = false;
	
	while(true) {
		int command;
		cin >> command;
		
		if(command == 1) {
			if(crane != 0) crane -= 1;
		}
		else if(command == 2) {
			if(crane != N-1) crane += 1;
		}
		else if(command == 3) {
			if(!has_box && stacks[crane] > 0){
				has_box = true;
				stacks[crane] -= 1;
			}
		}
		else if(command == 4) {
			if(has_box && stacks[crane] < H){
				has_box = false;
				stacks[crane] += 1;
			}
		}
		else {
			break;
		}
	}
	
	for(int i = 0; i < N; i++){
		cout << stacks[i];
		if(i < N-1) cout << " ";
	}
	cout << endl;
}