// Chef In Debt

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
	int N[10];
	string people[10] = { "Dhaval", "Shivang", "Bhardwaj", "Rishab", "Maji", "Gaurav", "Dhruv", "Nikhil", "Rohan", "Ketan" };
	set<int> moneys;
	for(int i = 0; i < 10; i++){
		cin >> N[i];
		moneys.insert(N[i]);
	}
	
	int index = 0;
	while(!moneys.empty()){
		int curr;
		if(index % 2 == 1){
			curr = *moneys.begin();
			moneys.erase(moneys.begin());
		}
		else {
			curr = *moneys.rbegin();
			moneys.erase(curr);
		}
		for(int i = 0; i < 10; i++){
			if(N[i] == curr) cout << people[i] << endl;
		}
		
		index++;
	}
}