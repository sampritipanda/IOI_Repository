// Electronic Pets

#include <iostream>
#include <string>

using namespace std;

class ElectronicPetEasy {
    public:
    string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2);
};

string ElectronicPetEasy::isDifficult(int st1, int p1, int t1, int st2, int p2, int t2){
	string difficult = "Difficult";
	string easy = "Easy";
	
	while(t1 > 0 && t2 > 0){
		if(st1 == st2) {
			return difficult;
		}
		else {
			st1 += p1;
			st2 += p2;
			t1--;
			t2--;
		}
	}
	return easy;
}

int main() {
	ElectronicPetEasy test;
	cout << test.isDifficult(3,	0,	0,	3,	0,	0) << endl;
}
