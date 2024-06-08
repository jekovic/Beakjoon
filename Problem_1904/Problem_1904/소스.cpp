#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;
int arr[MAX];
//  % 15746
int ret(int n) {
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}
	return arr[n];
}

int main() {
	int n;
	cin >> n;
	cout << ret(n);

	return 0;
}