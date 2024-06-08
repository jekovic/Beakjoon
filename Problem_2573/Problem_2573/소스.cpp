//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <stack>
//#include <cmath>
//#include <cstring>
//
//using namespace std;
//
//int N, M;
//int visited[301][301];
//int ice[301][301];
//int dx[] = { 0, 0, 1, -1 };
//int dy[] = { 1, -1, 0, 0 };
//int result;
//int cnt;
//int cnt_ice;
//vector<int> res;
//
//void input() {
//	cin >> N >> M;
//	
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> ice[i][j];
//		}
//	}
//}
//
//void init() {
//	cnt_ice = 0;
//	res.clear();
//	memset(visited, 0, sizeof(visited));
//}
//
//void bfs(int r, int c) {
//	int q = 0;
//	visited[r][c] = true;
//	for (int t = 0; t < 4; t++) {
//		int nr = r + dx[t];
//		int nc = c + dy[t];
//
//		if (nr < 1 || nc < 1 || nr > N || nc > M) continue;
//		if (visited[nr][nc]) continue;
//		if (ice[nr][nc] == 0) q++;
//	}
//	ice[r][c] -= q;
//	if (ice[r][c] < 0) ice[r][c] = 0;
//}
//
//void dfs(int r, int c) {
//	for (int t = 0; t < 4; t++) {
//		int nr = r + dx[t];
//		int nc = c + dy[t];
//
//		if (nr < 1 || nc < 1 || nr > N || nc > M) continue;
//		if (visited[nr][nc]) continue;
//		if (ice[nr][nc] > 0) {
//			visited[nr][nc] = true;
//			cnt++;
//			dfs(nr, nc);
//		}		
//	}
//}
//
//void solve() {
//	while (1) {
//		
//		for (int i = 1; i <= N; i++) {
//			for (int j = 1; j <= M; j++) {
//				if (ice[i][j] > 0) {
//					bfs(i, j);
//					if (ice[i][j] > 0) {
//						cnt_ice++;
//					}
//				}
//			}
//		}
//
//		result++;
//
//		memset(visited, 0, sizeof(visited));
//
//		for (int i = 1; i <= N; i++) {
//			for (int j = 1; j <= M; j++) {
//				if (visited[i][j] == false and ice[i][j] > 0) {
//					cnt = 1;
//					visited[i][j] = true;
//					dfs(i, j);
//					res.push_back(cnt);
//				}
//			}
//		}
//
//		if (res.size() > 1)
//			break;
//
//		if ( cnt_ice == 0) {
//			result = 0;
//			break;
//		}
//
//		init();
//		 
//	}
//}
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	input();
//
//	solve();
//
//	cout << result;
//
//	return 0;
//}



#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[301][301];
int visited[301][301];
int N, M;
int year_cnt;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int ice_cnt;
vector<int> res;
int cnt;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
}

void init() {
    memset(visited, 0, sizeof(visited));
}

void bfs(int r, int c) {
    int zero = 0;
    visited[r][c] = true;
    for (int t = 0; t < 4; t++) {
        int nx = r + dx[t];
        int ny = c + dy[t];
        if (nx<1 || ny<1 || nx>N || ny>M) continue;
        if (map[nx][ny] == 0) zero++;
    }
    map[r][c] -= zero;
    if (map[r][c] < 0) map[r][c] = 0;
}

void dfs(int r, int c) {
    for (int t = 0; t < 4; t++) {
        int nr = r + dx[t];
        int nc = c + dy[t];
        if (nr < 1 || nc < 1 || nr > N || nc > M) continue;
        if (visited[nr][nc]) continue;
        if (map[nr][nc] > 0) {
            visited[nr][nc] = true;
            cnt++;
            dfs(nr, nc);
        }
    }
}

void solve() {

    while (1) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++)
            {
                if (map[i][j] > 0) {
                    bfs(i, j);
                    if (map[i][j] > 0) {
                        ice_cnt++;
                    }
                }
            }
        }

        year_cnt++;

        memset(visited, 0, sizeof(visited));

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (visited[i][j] == false and map[i][j] > 0) {
                    cnt = 1;
                    visited[i][j] = true;
                    dfs(i, j);
                    res.push_back(cnt);
                }
            }
        }

        if (res.size() > 1)
            break;

        if (ice_cnt == 0) {
            year_cnt = 0;
            break;
        }

        init();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();

    solve();

    cout << year_cnt;

    return 0;
}