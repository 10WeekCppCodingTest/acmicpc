/*
답 : http://boj.kr/c7b230ec84bf4153a125b858a5ef77e2
*/

#include<bits/stdc++.h>
using namespace std;

string str;

int main() {
	cin >> str;
	string a = str;
	
	reverse(a.begin(), a.end());
	
	if(str==a) cout << true;
	else cout << false;
	
	return 0;
}