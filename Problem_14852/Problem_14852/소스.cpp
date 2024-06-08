#include <iostream>
#include <vector>

using namespace std;

int d[1000001];
long long int k[1000001][2];

int f(int x) {
	if (x == 0) return 1;
	if (x == 1) return 2;
	if (x == 2) return 7;
	if (d[x] != 0) return d[x];
	int ret = f(x - 2) * 3 + f(x - 1) * 2;
	for (int i = 3; i <= x; i++) {
		ret += (2 * f(x - i)) % 1000000007;
	}

	return ret;
}

long long int dp(int x) {
	k[0][0] = 0;
	k[1][0] = 2;
	k[2][0] = 7;
	k[2][1] = 1;

	for (int i = 3; i <= x; i++) {
		k[i][1] = (k[i - 1][1] + k[i - 3][0]) % 1000000007;
		k[i][0] = (k[i - 2][0] * 3 + k[i - 1][0] * 2 + k[i][1] * 2) % 1000000007;
	}
	return k[x][0];
}

int main() {

	int n;
	cin >> n;

	//cout << f(n)

	printf("%lld", dp(n));

	return 0;
}