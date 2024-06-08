#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define MAX 51

using namespace std;

int arr[MAX][MAX];
int N, M, K;
vector<int> v;
int result = 1e9;
vector<int> seq;
int map[MAX][MAX];

class rot {
public:
	int x;
	int y;
	int s;
	rot(int q, int w, int e) {
		this->x = q;
		this->y = w;
		this->s = e;
	}
};
vector<rot> r;

void input() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			arr[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		r.push_back(rot(q, w, e));
	}
	v.assign(K, 0);
	seq.assign(K, 0);
}

void cal_res() {
	int res = 1e9;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += arr[i][j];
		}
		res = min(res, sum);
	}
	result = min(result, res);
}

void rotate_arr(int x, int y, int s) {
	int start = s;
	while (1) {
		if (start <= 0)
			break;
		//
		int q = arr[x - start][y - start];
		int w = arr[x - start][y + start];
		int e = arr[x + start][y + start];
		int r = arr[x + start][y - start];

		//left-> right
		for (int i = y + start; i >= y - start + 1; i--) {
			arr[x - start][i] = arr[x - start][i - 1];
		}
		//up->down
		for (int i = x + start; i >= x - start + 2; i--) {
			arr[i][y + start] = arr[i - 1][y + start];
		}
		arr[x - start + 1][y + start] = w;
		//right -> left
		for (int i = y - start; i <= y + start - 2; i++) {
			arr[x + start][i] = arr[x + start][i + 1];
		}
		arr[x + start][y + start - 1] = e;
		//down -> up
		for (int i = x - start; i <= x + start - 2; i++) {
			arr[i][y - start] = arr[i + 1][y - start];
		}
		arr[x + start - 1][y - start] = r;
		//
		start--;
	}
}

void copy_arr() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			arr[i][j] = map[i][j];
		}
	}
}

void dfs(int cnt) {
	if (cnt == K) {
		copy_arr();
		for (int i = 0; i < K; i++) {
			int idx = seq[i];
			rotate_arr(r[idx].x, r[idx].y, r[idx].s);
		}
		cal_res();
		return;
	}
	for (int i = 0; i != r.size(); i++) {
		if (v[i]) continue;
		v[i] = true;
		seq[cnt] = i;
		dfs(cnt + 1);
		v[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	dfs(0);

	cout << result;

	return 0;
}