#include <iostream>
#include <vector>

using namespace std;
int arr[41];
int cnt1 = 0;
int cnt2 = 0;

int fibo(int n) {
	if (n <= 2) {
		cnt1++;
		return 1;
	}
	else return fibo(n - 1) + fibo(n - 2);
}

int fibonacci(int n) {
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		cnt2++;
	}
	return arr[n];
}

int main() {
	int n;
	cin >> n;

	int k = fibo(n);
	int t = fibonacci(n);

	cout << cnt1 << ' ' << cnt2;

	return 0;
}