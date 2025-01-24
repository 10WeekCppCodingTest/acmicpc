/*
답 : http://boj.kr/4e97e76bb0dd438fba134d0aada1c531
*/

#include<bits/stdc++.h>
using namespace std;

int priceA, priceB, priceC;
int arrive, depart;
int cnt[104], ret;


int main() {
	cin >> priceA >> priceB >> priceC;
	
	for(int i=0; i<3; i++) {
		cin >> arrive >> depart;
		for(int j=arrive; j<depart; j++) cnt[j]++;			// {출발,도착) 시간에 +=1; 
	}
	ret = 0;
	for(int i=0; i<100; i++) {
		if(cnt[i]) {
			if(cnt[i]==1) ret += priceA;
			else if(cnt[i]==2) ret += (priceB*2);
			else if(cnt[i]==3) ret += (priceC*3);
		}
	} 
	cout << ret << "\n";
	return 0;
}