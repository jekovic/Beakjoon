#include <iostream>
#include <vector>

using namespace std;
long long int arr[101];

long long int f(int n) {
	if (arr[n] != 0) return arr[n];
	return arr[n] = f(n - 2) + f(n - 3);
}

int main() {
	int t;
	cin >> t;
	arr[1] = arr[2] = arr[3] = 1;
	arr[4] = arr[5] = 2;
	arr[6] = 3;
	

	while (t--) {
		int n;
		cin >> n;

		printf("%lld\n", f(n));
	}

	return 0;
}