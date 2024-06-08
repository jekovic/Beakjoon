#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;
int n;
int a[MAX];

void dp(int k) {
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	for (int i = 4; i <= k; i++) {
		if (i % 6 == 0) a[i] = min(min(a[i / 2], a[i / 3]), a[i - 1]) + 1;
		else if (i % 3 == 0) a[i] = min(a[i / 3] + 1, a[i-1] + 1);
		else if (i % 2 == 0) a[i] = min(a[i / 2] + 1, a[i-1] + 1);
		else a[i] = a[i - 1] + 1;
	}
	
}

/*
	빼기를 이용해서
	3의 배수로 만들기
	2의 배수로 만들기
*/
int main() {

	cin >> n;
	int cnt = 0;
	
	dp(n);

	cout << a[n];

	return 0;
}