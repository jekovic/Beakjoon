#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 51
using namespace std;
// 0 north --- 1 east --- 2 south --- 3 west
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int map[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
int sx, sy;
int d;
int result;


void bfs() {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	//result++;

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		if (map[curx][cury] == 0) {
			map[curx][cury] = 2;
			result++;
		}

		bool ok = true;
		for (int i = 0;i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx >= 0 and ny >= 0 and nx < n and ny < m and map[nx][ny] != 1) {
				if (map[nx][ny] == 0) { // 청소 안됨
					ok = false;
				}
			}
		}//end of for

		if (ok == false) {
			d += 3;
			d %= 4;
			curx += dx[d];
			cury += dy[d];
			if (map[curx][cury] == 1 || map[curx][cury] == 2) { // 벽이거나 이미 청소함
				curx -= dx[d];
				cury -= dy[d];
			}
			else if (map[curx][cury] == 0){
				map[curx][cury] = 2;
				result++;
			}
			
			q.push({ curx, cury });
		}
		else {
			if (d == 0) {
				curx++;
			}
			else if (d == 1) {
				cury--;
			}
			else if (d == 2) {
				curx--;
			}
			else if (d == 3) {
				cury++;
			}

			if (map[curx][cury] != 1) {
				q.push({ curx, cury });
			}
			else {
				return;
			}

		}

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> sx >> sy >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}


	bfs();


	cout << result;


	return 0;
}
//
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <stack>
//#define MAX 51
//using namespace std;
//// 0 north --- 1 east --- 2 south --- 3 west
//int dx[] = { -1, 0, 1, 0 };
//int dy[] = { 0, -1, 0, 1 };
//int map[MAX][MAX];
//bool visited[MAX][MAX];
//int n, m;
//int sx, sy;
//int d;
//int result;
//
//
//void bfs() {
//	stack<pair<int, int>> q;
//	q.push({ sx, sy });
//	//result++;
//
//	while (!q.empty()) {
//		int curx = q.top().first;
//		int cury = q.top().second;
//		q.pop();
//
//		if (map[curx][cury] == 0) {
//			map[curx][cury] = 2;
//			result++;
//		}
//
//		bool ok = true;
//		for (int i = 0;i < 4; i++) {
//			int nx = curx + dx[i];
//			int ny = cury + dy[i];
//			if (nx >= 0 and ny >= 0 and nx < n and ny < m and map[nx][ny] != 1) {
//				if (map[nx][ny] == 0) { // 청소 안됨
//					ok = false;
//				}
//			}
//		}//end of for
//
//		if (ok == false) {
//			d += 1;
//			d %= 4;
//			curx += dx[d];
//			cury += dy[d];
//			if (map[curx][cury] == 1 || map[curx][cury] == 2) { // 벽이거나 이미 청소함
//				curx -= dx[d];
//				cury -= dy[d];
//			}
//			else if (map[curx][cury] == 0) {
//				map[curx][cury] = 2;
//				result++;
//			}
//			q.push({ curx, cury });
//		}
//		else {
//			if (d == 0) {
//				curx++;
//			}
//			else if (d == 1) {
//				cury++;
//			}
//			else if (d == 2) {
//				curx--;
//			}
//			else if (d == 3) {
//				cury--;
//			}
//
//			if (map[curx][cury] != 1) {
//				q.push({ curx, cury });
//			}
//			else {
//				return;
//			}
//
//		}
//
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	cin >> sx >> sy >> d;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//
//	bfs();
//
//
//	cout << result;
//
//
//	return 0;
//}