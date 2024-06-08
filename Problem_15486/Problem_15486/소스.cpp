#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define INF 1e9

using namespace std;

int N;
int res[1500051];
int D[1500051];
int M[1500051];

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> D[i] >> M[i];
	}
}

void dp() {

	for (int i = 1; i <= N; i++) {
		if (res[i] < res[i-1])
			res[i] = res[i - 1];
		res[i + D[i] - 1] = max(res[i + D[i] - 1], res[i - 1] + M[i]);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	dp();

	cout << res[N];

	return 0;
}