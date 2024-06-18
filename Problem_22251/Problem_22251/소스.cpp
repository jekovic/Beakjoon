#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N; // 건물 층수
int K; // 디스플레이 자리수
int P; // 최대 반전시킬 수 있는 LED 갯수
int X; // 현재 층

bool pattern[10][7] = {
	{1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 1},
	{1, 0, 1, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 1}
};

void input() {
	cin >> N >> K >> P >> X;
}

int solve() {
	int res = 0;

	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		int cnt = 0;
		int from = X, to = i;
		for (int j = 0; j < K; j++) {
			for (int q = 0; q < 7; q++) {
				if (pattern[from % 10][q] != pattern[to % 10][q]) cnt++;
			}
			from /= 10;
			to /= 10;
		}
		if (cnt <= P) res++;
	}

	return res;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	cout << solve();

	return 0;
}