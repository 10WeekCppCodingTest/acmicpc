/*
답 : http://boj.kr/5bf6553f957e4a4586dace497284f319
*/

#include<bits/stdc++.h>
using namespace std;

int cnt[26], num;
string str, ret;

int main() {
	cin >> num;
	
	for(int i=0; i<num; i++) {
		cin >> str;
		cnt[str[0] - 'a']++;
	} 
	
	for(int i=0; i<26; i++) {
		if(cnt[i] >=5) ret += (i+'a');
	}
	if(ret.size()) cout << ret << "\n";
	else cout << "PREDAJA" << "\n";
	
	return 0;
}