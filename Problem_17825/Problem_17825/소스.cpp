#include <iostream>
#include <queue>
#include <vector>

using namespace std;
//1 2 3 4 1 2 3 4 1 2

vector<int> dice;
int piece[4];

int arr[34];	// 다음에 갈 위치
int score[34];	// 점수
int turn[34];	// 파란색
bool check[34];	// 말이 있는지

int result;


void make_map() {
	for (int i = 0; i <= 20; i++) {
		arr[i] = i + 1;
	}
	arr[21] = 21;
	for (int i = 22; i <= 26; i++) {
		arr[i] = i + 1;
	}
	arr[27] = 20; arr[28] = 29; arr[29] = 30;
	arr[30] = 25; arr[31] = 32; arr[32] = 25;

	turn[5] = 22; turn[10] = 31; turn[15] = 28;

	for (int i = 0; i <= 20; i++) {
		score[i] = i * 2;
	}
	score[22] = 13; score[23] = 16; score[24] = 19;
	score[25] = 25; score[26] = 30; score[27] = 35;
	score[28] = 28; score[29] = 27; score[30] = 26;
	score[31] = 22; score[32] = 24;
}

void dfs(int cnt, int n) {
	if (cnt == 10) {
		result = max(result, n);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int prev = piece[i];
		int cur = prev;
		int move = dice[cnt];

		if (turn[cur] > 0) {
			cur = turn[cur]; // 한 칸 이동
			move--;
		}

		while (move--) cur = arr[cur];

		if (cur != 21 and check[cur]) continue;

		check[prev] = false;
		check[cur] = true;
		piece[i] = cur;

		dfs(cnt + 1, n + score[cur]);

		piece[i] = prev;
		check[prev] = true;
		check[cur] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int c = 10;
	while (c--) {
		int t;
		cin >> t;
		dice.push_back(t);
	}

	make_map();

	dfs(0, 0);

	cout << result;

	return 0;
}