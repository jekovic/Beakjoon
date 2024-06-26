#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
vector<vector<int>> color;
const int INF = 1e9;
vector<vector<int>> res;
int result = 1e9;

void input() {
	cin >> N;

	color.assign(N, vector<int>(3, 0));
	res.assign(N, vector<int>(3, INF));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[i][j];
		}
	}
}

void dp() {

	for (int rgb = 0; rgb < 3; rgb++) {
		for (int i = 0; i < 3; i++) {
			if (i == rgb) res[0][i] = color[0][i];
			else res[0][i] = INF;
		}

		for (int i = 1; i < N; i++) {
			res[i][0] = color[i][0] + min(res[i - 1][1], res[i - 1][2]);
			res[i][1] = color[i][1] + min(res[i - 1][0], res[i - 1][2]);
			res[i][2] = color[i][2] + min(res[i - 1][0], res[i - 1][1]);
		}

		for (int i = 0; i < 3; i++) {
			if (i == rgb) continue;
			result = min(result, res[N - 1][i]);
		}
	}	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	dp();

	cout << result;

	return 0;
}	