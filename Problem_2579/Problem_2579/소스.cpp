#include <iostream>
#include <vector>
#define MAX 301

using namespace std;

int DP[MAX];
int stage[MAX];

/*
	1번째 MAX = 1계단
	2번째 MAX = 1+1 계단
	3번째 MAX = max(1+2, 2+1)
	4번째부터는 max(2번째 아래 + 본인, 3번째 아래 + 1번째 아래+ 본인)
*/

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		stage[i] = k;
	}
	
	DP[1] = stage[1];
	DP[2] = stage[2] + stage[1];
	DP[3] = max(stage[3] + stage[1], stage[2] + stage[3]);
	for (int i = 4; i <= n; i++) {
		DP[i] = max(DP[i - 2] + stage[i], DP[i - 3] + stage[i - 1] + stage[i]);
	}
	cout << DP[n];
	return 0;
}