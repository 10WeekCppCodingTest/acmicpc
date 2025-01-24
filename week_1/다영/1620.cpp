/*
답 : http://boj.kr/cb68e0961c7e4d8e812bf965943f4b10
*/

#include<bits/stdc++.h>
using namespace std;

/* 
1. map: O(logN), array(N) 
2. atoi(s.c_str) == 0 : s는 string
*/ 

int n, m;
string s;
map<string, int> mp;
map<int, string> mp2;
string a[1000004];

int main() {
	// 없으면 시간 초과 에러.. 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	
	// initialize
	for(int i=0; i<n; i++) {
		cin >> s;
		mp[s] = i +1;   // mp.insert({s, i});
		mp2[i+1] = s;   // mp2.insert({i, s});
		a[i+1] = s;
	}
	
	// find
	for(int i=0; i<m; i++) {
		cin >> s;
		if(atoi(s.c_str()) == 0) {
			cout << mp[s] << "\n";
		}
		else {
			//  cout << a[atoi(s.c_str())] << "\n;
			cout << mp2[atoi(s.c_str())] << "\n";
		}
	}
	return 0;
}
