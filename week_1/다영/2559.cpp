#include<bits/stdc++.h>
using namespace std;

/* 
1. 연속의 온도 합이 "최대" 되는 값 : 구간합 prefix sum -> psum[i] = psum[i-1] + a[i]; 
2. 최댓값 : ret = max(ret, value);
3. 최솟값 : ret = min(ret, value); -> -1000004 
*/ 

int main() {
	int N, K, temp, psum[100001], ret = -10000004;		// N=<100000
	
	cin >> N >> K;
	
	// i=0 : i-1 -> -1이 됨으로 틀림 
	for(int i=1; i<=N; i++) {
		cin >> temp;
		// psum[i] = psum[이전값] + 새로운 값 
		psum[i] = psum[i-1] + temp;
	}
	
	//
	for(int i=K; i<=N; i++) {
		// psum[i] - psum[i-K] : (i-K+1)번째 요소부터 i번째 요소까지의 부분합
		// psum[i] : 1부터 i까지 누적합
		//  psum[i-K] : 1부터 (i-K)까지 누적합
//		cout << i-K << "\n"; 
		ret = max(ret, psum[i] - psum[i-K]);
	}
	cout << ret;
	
	return 0;
}
