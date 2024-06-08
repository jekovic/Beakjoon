#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int map[501][501];
int visited[501][501];
int H, W;
int dx[] = { 0, 0 };
int dy[] = { 1, -1 };

void input() {
	cin >> H >> W;
	
	for (int i = 1; i <= W; i++) {
		int t;
		cin >> t;
		for (int j = H; j > H-t; j--)
		{
			map[j][i] = 1;
		}
	}
}

bool check(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > H + 1 || ny > W) continue;
		if (map[nx][ny] == 1 || visited[nx][ny] == 1) {
			cnt++;
		}
	}
	if (cnt == 2)return true;
	else return false;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();




	return 0;
}