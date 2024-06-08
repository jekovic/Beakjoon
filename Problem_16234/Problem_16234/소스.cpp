//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <stack>
//#define MAX 51
//
//using namespace std;
//
//int N, L, R;
//int map[MAX][MAX];
//int day = 0;
//int dx[] = { 0, 0, 1, -1 };
//int dy[] = { 1, -1, 0, 0 };
//bool posible;
//
//bool correct_zone(int x1, int y1, int x2, int y2) {
//	int temp = abs(map[x1][y1] - map[x2][y2]);
//	if (temp >= L and temp <= R)
//		return true;
//	else
//		return false;
//}
//int cnt = 1;
//
//// 벽 허물기
//void bfs_breaking(vector<vector<int>>& board) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			int cx = i;
//			int cy = j;
//			for (int k = 0; k < 4; k++) {
//				int nx = cx + dx[k];
//				int ny = cy + dy[k];
//				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
//				if (correct_zone(cx, cy, nx, ny)) {
//					if (board[cx][cy] == 0) {
//						board[cx][cy] = 1;
//					}					
//					board[nx][ny] = board[cx][cy];
//					posible = true;
//				}
//			}
//		}
//	}
//}
//
//void dfs(int x, int y, vector<vector<int>>& visited, vector<vector<int>>& board) {
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
//		if (!visited[nx][ny] and board[nx][ny]) {
//			visited[nx][ny] = 1;
//			//cnt++;
//			board[nx][ny] = cnt;
//			dfs(nx, ny, visited, board);
//		}
//	}
//}
//
//void making_map(vector<vector<int>>& board) {
//	vector<vector<int>> visited(N, vector<int>(N, 0));
//
//	for (int f = 0; f < N; f++) {
//		for (int g = 0; g < N; g++) {
//			if (visited[f][g] == false && board[f][g]) {
//				board[f][g] = cnt;
//				visited[f][g] = true;
//				dfs(f, g, visited, board);
//				cnt++;
//			}
//		}
//	}
//}
//
//void dfs_human(vector<vector<int>>& board) {
//	
//	for (int k = 1; k <= cnt - 1; k++) {
//		int count = 0;
//		int amount = 0;
//
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (board[i][j] == k) {
//					amount += map[i][j];
//					count++;
//				}
//			}
//		}
//		amount /= count; 
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (board[i][j] == k) {
//					map[i][j] = amount;
//				}
//			}
//		}	
//	}
//	day++;
//}
//
//void bfs_human(vector<vector<int>>& board) {
//	int c = 0;
//	int amount = 0;
//	vector<vector<int>> visited(N, vector<int>(N, 0));
//	queue<pair<int, int>> q;
//	q.push({ 0, 0 });
//	visited[0][0] = 1;
//	if (board[0][0] >= 1)
//	{
//		amount += map[0][0];
//		c++;
//	}
//
//	while (!q.empty()) {
//		int cx = q.front().first;
//		int cy = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nx = cx + dx[i];
//			int ny = cy + dy[i];
//
//			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
//			if (visited[nx][ny]) continue;
//			if (!visited[nx][ny] and board[nx][ny] == 0) {
//				visited[nx][ny] = 1;
//			}
//			if (!visited[nx][ny] and board[nx][ny] == 1) {
//				visited[nx][ny] = 1;
//				amount += map[nx][ny];
//				c++;
//			}
//			q.push({ nx, ny });
//		}
//	}//end of while
//
//	amount /= c;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (board[i][j] == 1) {
//				map[i][j] = amount;
//			}
//		}
//	}
//	day++;
//}
//
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N >> L >> R;
//	
//	
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	while (1) {
//		vector<vector<int>> board(N, vector<int>(N, 0));
//		posible = false;
//		cnt = 1;
//		bfs_breaking(board);
//		if (posible == false) {
//			break;
//		}
//		making_map(board);
//		dfs_human(board);
//		//bfs_human(board);
//	}
//	
//
//	cout << day;
//
//	return 0;
//}


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define MAX 51

using namespace std;

int N, L, R;
int map[MAX][MAX];
int day = 0;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;
int visited[MAX][MAX];
int sum;

bool correct_zone(int x1, int y1, int x2, int y2) {
	int temp = abs(map[x1][y1] - map[x2][y2]);
	if (temp >= L and temp <= R)
		return true;
	else
		return false;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N ) continue;
			if (visited[nx][ny]) continue;
			if (correct_zone(cx, cy, nx, ny)) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
				v.push_back({ nx, ny });
				sum += map[nx][ny];
			}
		}
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L >> R;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int flag = true;

	while (flag) {
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					v.clear();
					v.push_back({ i, j });
					sum = map[i][j];
					bfs( i, j );
				}

				if (v.size() >= 2) {
					flag = true;
					for (int k = 0; k != v.size(); k++) {
						map[v[k].first][v[k].second] = sum / v.size();
					}
				}
			}
		}

		if (flag) day++;
		for (int q = 0; q < N; q++) {
			for (int w = 0; w < N; w++) {
				visited[q][w] = false;
			}
		}
		//memset(visited, sizeof(visited), false);
	}
	
	cout << day;

	return 0;
}