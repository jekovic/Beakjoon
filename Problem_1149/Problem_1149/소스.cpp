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

vector<vector<int>> home;
vector<vector<int>> res;
//vector<int> res;

void input() {
	cin >> N;

	home.assign(N, vector<int>(3, 0));
	res.assign(N, vector<int>(3, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> home[i][j];
		}
	}
}

void dp() {
	for (int i = 0; i < 3; i++) {
		res[0][i] = home[0][i];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				res[i][j] = min(home[i][j] + res[i - 1][1], home[i][j] + res[i - 1][2]);
			}
			else if (j == 1) {
				res[i][j] = min(home[i][j] + res[i - 1][0], home[i][j] + res[i - 1][2]);
			}
			else if (j == 2) {
				res[i][j] = min(home[i][j] + res[i - 1][1], home[i][j] + res[i - 1][0]);
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	dp();

	int result = 1e9;
	for (int i = 0;i < 3; i++) {
		result = min(res[N - 1][i], result);
	}

	cout << result;

	return 0;
}