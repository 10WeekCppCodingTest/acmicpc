/*
답 : http://boj.kr/a7e74bfb990641249d917c73a9246796
*/

#include<bits/stdc++.h>
using namespace std;

/* 
1. 띄어쓰기 포함한 문자열이므로 getline() 으로 받아야 함.
2. ROT13 : 문자열 아스키코드의 + 13, 끝까지 온다면 다시 A, a부터 시작함 
3. s[i] = s[i] + 13 -26 (-26: 다시 원점)
*/ 

int main() {
	string s;
	getline(cin, s); 
	
	for(int i=0; i<s.size(); i++) {
		if(s[i] >=65 && s[i] <= 90) {
			if(s[i]+13 > 90) s[i] = s[i] + 13 - 26;
			else s[i] += 13;	
		}
		else if(s[i] >= 97 && s[i] <= 122) {
			if(s[i]+13 > 122) s[i] = s[i] + 13 - 26;
			else s[i] += 13;
		} 
	}
	cout << s;
	return 0;
}
