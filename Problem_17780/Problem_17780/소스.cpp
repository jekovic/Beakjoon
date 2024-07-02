#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <map> 
#include <algorithm>
#include <cmath>

using namespace std;

struct Information {
	int y, x;
	int dir;
};

int N, K, answer = 0;
int adj[13][13];
vector<int> board[13][13];
Information Horse[11];

const int dy[] = { 0, 0,0,-1,1 };
const int dx[] = { 0, 1,-1,0,0 };

void Input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> adj[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		cin >> Horse[i].y >> Horse[i].x >> Horse[i].dir;
		board[Horse[i].y][Horse[i].x].push_back(i);
	}
}

bool isValid(int y, int x) {
	return (1 <= y && y <= N && 1 <= x && x <= N);
}

bool isEndGame() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j].size() >= 4) return true;
		}
	}
	return false;
}

void Game_Start(int depth) {
	if (depth >= 1000) {
		answer = -1;
		return;
	}
	if (isEndGame()) {
		answer = depth;
		return;
	}

	for (int i = 1; i <= K; i++) {
		int y = Horse[i].y, x = Horse[i].x;
		if (board[y][x].front() != i) continue;
		int ny = y + dy[Horse[i].dir];
		int nx = x + dx[Horse[i].dir];

		if (!isValid(ny, nx) || adj[ny][nx] == 2) {
			if (Horse[i].dir == 1) {
				Horse[i].dir = 2;
			}
			else if (Horse[i].dir == 2) {
				Horse[i].dir = 1;
			}
			else if (Horse[i].dir == 3) {
				Horse[i].dir = 4;
			}
			else {
				Horse[i].dir = 3;
			}
			ny = y + (dy[Horse[i].dir]);
			nx = x + (dx[Horse[i].dir]);

			if (isValid(ny, nx) && adj[ny][nx] != 2) {
				if (adj[ny][nx] == 0) {
					for (int ps = 0; ps < board[y][x].size(); ps++) {
						Horse[board[y][x][ps]].y = ny;
						Horse[board[y][x][ps]].x = nx;
						board[ny][nx].push_back(board[y][x][ps]);
					}
					board[y][x].clear();
				}
				else {
					reverse(board[y][x].begin(), board[y][x].end());
					for (int ps = 0; ps < board[y][x].size(); ps++) {
						Horse[board[y][x][ps]].y = ny;
						Horse[board[y][x][ps]].x = nx;
						board[ny][nx].push_back(board[y][x][ps]);
					}
					board[y][x].clear();
				}
				Horse[i].y = ny;
				Horse[i].x = nx;
			}
		}
		else {
			if (adj[ny][nx] == 0) {
				for (int ps = 0; ps < board[y][x].size(); ps++) {
					Horse[board[y][x][ps]].y = ny;
					Horse[board[y][x][ps]].x = nx;
					board[ny][nx].push_back(board[y][x][ps]);
				}
				board[y][x].clear();
			}
			else {
				reverse(board[y][x].begin(), board[y][x].end());
				for (int ps = 0; ps < board[y][x].size(); ps++) {
					Horse[board[y][x][ps]].y = ny;
					Horse[board[y][x][ps]].x = nx;
					board[ny][nx].push_back(board[y][x][ps]);
				}
				board[y][x].clear();
			}
			Horse[i].y = ny;
			Horse[i].x = nx;
		}
	}

	Game_Start(depth + 1);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	Input();
	Game_Start(0);
	cout << answer << endl;

	return 0;
}