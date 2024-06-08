#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define MAX 1001
#define INF 987654321

using namespace std;

int N, M, X;
int t[MAX][MAX];
int result[MAX];

void input() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		t[q][w] = e;
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				t[i][j] = 0;
				continue;
			}
			if (t[i][j] != 0) continue;
			else
				t[i][j] = INF;
		}
	}
}

void floyd() {
	vector<vector<int>>d(N+1, vector<int>(N+1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			d[i][j] = t[i][j];
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		result[i] = d[i][X] + d[X][i];
	}

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	input();

	init();

	floyd();

	sort(result, result + N + 1);
	
	cout << result[N];

	return 0;
}