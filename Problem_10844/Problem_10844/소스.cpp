#include <iostream>

using namespace std;

//int a[101];

long long int a[101][10];		// [자리 수] [ 끝나는 수(1의 자리 수)]

int n;

void dp() {
	for (int i = 1; i < 10; i++) {
		a[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				a[i][j] = (a[i - 1][1]) % 1000000000;
			}
			else if( j == 9) {
				a[i][j] = (a[i - 1][8]) % 1000000000;
			}
			else {
				a[i][j] = (a[i - 1][j + 1] + a[i - 1][j - 1]) % 1000000000;
			}
		}
	}
}

int main() {

	cin >> n;

	dp();
	
	long long int cnt = 0;

	for (int i = 0; i < 10; i++) {
		cnt += a[n][i];
	}

	cout << cnt % 1000000000;

	return 0;
}