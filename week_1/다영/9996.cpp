/*
답 : http://boj.kr/7c429b5497b149a3a42c4a2d02b9a4b5
*/

#include<bits/stdc++.h>
using namespace std;

/* 
1. 조건 : 접두사 prefix, 접미사 suffix
   -> fileName[i].begin(), fileName[i].end()로 하면 안됨.
2. s.substr(0, pos)== pos && s.substr(s.size()-suf) == suf
*/ 

int main() {
	int N, idx;
	string s, pattern, pre, suf;
//	vector<string> fileName;
	
	cin >> N;
	cin >> pattern;
	
	// prefix, suffix 찾기 
	idx = pattern.find("*");
	pre = pattern.substr(0, idx);
	suf = pattern.substr(idx+1);
	
	for(int i=0; i<N; i++) {
		cin >> s;
		if(pre.size() + suf.size() > s.size()) cout << "NE\n";
		else {
			if(s.substr(0, pre.size()) == pre && s.substr(s.size()-suf.size()) == suf) cout << "DA\n";
			else cout << "NE\n";
		}
	}
	
//	for(int i=0; i<N; i++) {
//		cin >> s;
//		fileName.push_back(s);
//	};
//	
//	for(int i=0; i<fileName.size(); i++) {
//		if(fileName[i].substr(0,pre.size()) == pre && fileName[i].substr(fileName[i].size()- suf.size()) == suf) cout << "DA" << "\n";
//		else cout << "NE" << "\n";
//	}
	return 0;
}
