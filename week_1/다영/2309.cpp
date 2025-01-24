/*
답 : http://boj.kr/5cbef80aaad4484a8c3ea73bebf2c0ab
*/

#include<bits/stdc++.h>
using namespace std;

/*
9C2 = 36
100 = All - A - B -> A,B 두개 찾기 -> 9C2
 
*/

vector<int> v;	            // 일곱 난쟁이
int people[10];             // 공간 넉넉히, 9명 난쟁이 담을 배열
pair<int, int> ret;         // A, B
int sum;

void combi() {
	for(int i=0; i<9; i++) {
		for(int j=0; j<i; j++) {
			if(sum - (people[i] + people[j])== 100) {
				ret = {i, j};
				return;
			}
		}
	}
}

int main(){
	
	// 100 + A + B
	for(int i = 0; i<9; i++) {
		cin >> people[i];
		sum += people[i];
	}
	
	// combi
	combi();
	for(int i=0; i<9; i++) {
		if(ret.first == i || ret.second == i) continue;
		v.push_back(people[i]);
	}
	
	// sort
	sort(v.begin(), v.end());
	for(int i:v) cout << i << "\n";
	
	return 0;
}
