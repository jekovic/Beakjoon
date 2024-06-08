#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[1001];

int f(int x) {
	if (x == 1) return 1;
	if (x == 2) return 3;
	if (a[x] != 0) return a[x];
	return a[x] = (f(x - 1) + 2 * f(x - 2)) % 10007;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	printf("%d", f(n));


	return 0;
}