#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define INF 1e9

using namespace std;

vector<int> d;
int N;

void dp() {
	for (int i = 1; i <= N; i++) {
		d[i] = i;
	}

	for (int i = 2; i <= N; i++) {
		if (i % 3 == 0) {
			d[i] = min(d[i], d[i / 3]);
		}
		if (i % 2 == 0) {
			d[i] = min(d[i], d[i / 2]);
		}
		d[i] = min(d[i], d[i - 1]) + 1;
	}

	cout << d[N] - 1 << '\n';

	while (N != 0) {
		cout << N << ' ';
		if (d[N] == d[N - 1] + 1)
			N = N - 1;
		else if (N % 2 == 0 and d[N] == d[N / 2] + 1)
			N /= 2;
		else if (N % 3 == 0 and d[N] == d[N / 3] + 1)
			N /= 3;
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	d.assign(N+1, 0);

	dp();

	return 0;
}