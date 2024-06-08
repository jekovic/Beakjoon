#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[31];

int f(int x) {
	if (x == 0) return 1;
	if (x == 1)return 0;
	if (x == 2) return 3;
	if (a[x] != 0) return a[x];
	int result = 3 * f(x - 2);
	for (int i = 3; i <= x; i++) {
		if (i % 2 == 0) {
			result += 2 * f(x - i);
		}
	}
	return a[x] = result;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	printf("%d", f(n));


	return 0;
}