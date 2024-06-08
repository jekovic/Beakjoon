#include <iostream>
#define MAX 51

using namespace std;

int res[MAX][MAX][MAX];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (res[a][b][c] != 0) return res[a][b][c];
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (a < b && b < c) return res[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return res[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		int k = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << k << '\n';
	}

	return 0;
}
