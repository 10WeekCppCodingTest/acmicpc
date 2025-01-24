#include<bits/stdc++.h>
using namespace std;

// 답
/* 
counting start -> map(string), array(int) 
*/

string str;
int cnt[26];

int main() {
	cin >> str;
	
	/*
	문자 'a'는 'a' - 'a' = 0 → cnt[0]
	문자 'b'는 'b' - 'a' = 1 → cnt[1]
	문자 'z'는 'z' - 'a' = 25 → cnt[25]
	*/
	for(char a: str) {
		cnt[a-'a']++;
	}
	
	for(int i=0; i<26; i++) cout << cnt[i] << " ";
	return 0;
}

// 풀이 

/*
1. pair 형태의 first: 알파벳, second: cnt로 초기화
: 65~ 90 : A~Z
: 97 ~ 122 : a~z
: 

2. pari.first와 string값 문자 비교 후, second 값에 +1

3. pari.second값 출력 
 
*/

//string str;
//vector<pair<string, int>> pi(26);
//
//int main(){
//	int cnt;
//	cin >> str;
//	
//	// initialize
//	for(int i=0; i<pi.size(); i++) {
//		pi[i].first = char('a' + i);
//		pi[i].second = 0;
//	}
//	
//	// for(const auto &p: pi) cout << p.first << " " << "\n";
//	
//	// count
//	for(int i=0; i<pi.size(); i++) {
//		for(int j=0; j<str.size(); j++) {
//			if(pi[i].first == string(1, str[j])) pi[i].second += 1;		// string(1, str[j]) : 1 길이의 문자열 변환 
//		}
//	}
//	
//	// print
//	for(const auto &p: pi) cout << p.second << " ";
//	
//	return 0;
//}
