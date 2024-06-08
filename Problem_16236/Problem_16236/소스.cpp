//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define MAX 21
//using namespace std;
//int n;
//int map[MAX][MAX];
//int visited[MAX][MAX];
//int dx[] = { 1, -1 , 0, 0 };
//int dy[] = { 0, 0, 1, -1 };
//int sx, sy;
//int shark_size = 2;
//int sec;
//int eat_cnt = 0;
//
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 9) {
//				sx = i;
//				sy = j;
//			}
//		}
//	}
//	while (1) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				visited[i][j] = -1;
//			}
//		}
//		visited[sx][sy] = 0;
//		map[sx][sy] = 0;
//
//
//		queue<pair<int, int>> q;
//		vector<pair<int, int>> fish;
//
//		if (eat_cnt >= shark_size) {
//			eat_cnt = 0;
//			shark_size++;
//		}
//
//		q.push({ sx, sy });
//
//		while (!q.empty()) {
//			int cur_x = q.front().first;
//			int cur_y = q.front().second;
//			q.pop();
//
//			for (int i = 0; i < 4; i++) {
//				int nx = cur_x + dx[i];
//				int ny = cur_y + dy[i];
//
//				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
//
//				if (visited[nx][ny] != -1) continue;
//				if (map[nx][ny] > shark_size) continue;
//
//				else if (map[nx][ny] == shark_size || map[nx][ny] == 0) {
//					visited[nx][ny] = visited[cur_x][cur_y] + 1;
//					q.push({ nx,ny });
//				}
//				else if (map[nx][ny] < shark_size and map[nx][ny] >= 1) {
//					visited[nx][ny] = visited[cur_x][cur_y] + 1;
//					q.push({ nx,ny });
//					fish.push_back({ nx,ny });
//				}
//			
//			}
//		}
//		if (fish.size() == 0) {
//			cout << sec;
//			return 0;
//		}
//		else if (fish.size() == 1) {
//			sx = fish[0].first;
//			sy = fish[0].second;
//			map[sx][sy] = 0;
//			eat_cnt++;
//			sec += visited[sx][sy];
//		}
//		else {
//			int minlen = 987654321;
//			for (auto& x : fish) {
//				minlen = min(minlen, visited[x.first][x.second]);
//			}
//
//			int mincnt = 0;
//			vector<pair<int, int>> minfish;
//			for (auto& x : fish) {
//				if (minlen == visited[x.first][x.second]) {
//					minfish.push_back({ x.first, x.second });
//				}
//			}
//			if (minfish.size() == 1) {
//				sx = minfish[0].first;
//				sy = minfish[0].second;
//				map[sx][sy] = 0;
//				sec += visited[sx][sy];
//				eat_cnt++;
//			}
//			else {
//				sort(minfish.begin(), minfish.end());
//				sx = minfish[0].first;
//				sy = minfish[0].second;
//				map[sx][sy] = 0;
//				sec += visited[sx][sy];
//				eat_cnt++;
//			}
//		}
//
//	}
//
//	return 0;
//}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 21
using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];
int sx, sy;
int shark_size = 2;
int eat_cnt = 0;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int sec;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                sx = i;
                sy = j;
            }
        }
    }

    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = -1;
            }
        }
        visited[sx][sy] = 0;
        map[sx][sy] = 0;

        queue<pair<int, int>> q;
        vector<pair<int, int >> fish;

        if (eat_cnt >= shark_size) {
            eat_cnt -= shark_size;
            shark_size++;
        }

        q.push({ sx, sy });

        while (!q.empty()) {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (map[nx][ny] > shark_size) continue;
                if (visited[nx][ny] != -1) continue;
                else if (map[nx][ny] == shark_size || map[nx][ny] == 0) {
                    //지나갈 수 있음
                    visited[nx][ny] = visited[cur_x][cur_y] + 1;
                    q.push({ nx,ny });
                }
                else if (map[nx][ny] < shark_size and map[nx][ny] >= 1) {
                    visited[nx][ny] = visited[cur_x][cur_y] + 1;
                    q.push({ nx,ny });
                    fish.push_back({ nx,ny });
                }
            }//end of for(4)
        }//end of while(queue)
        if (fish.size() == 0) {
            cout << sec;
            return 0;
        }
        else if (fish.size() == 1) {
            sx = fish[0].first;
            sy = fish[0].second;
            map[sx][sy] = 0;
            sec += visited[sx][sy];
            eat_cnt++;
        }
        else {
            int minlen = 987654321;
            for (auto& x : fish) {
                minlen = min(minlen, visited[x.first][x.second]);
            }

            vector<pair<int, int>> minfish;

            for (auto& x : fish) {
                if (visited[x.first][x.second] == minlen) {
                    minfish.push_back({ x.first, x.second });
                }
            }

            if (minfish.size() == 1) {
                sx = minfish[0].first;
                sy = minfish[0].second;
                map[sx][sy] = 0;
                sec += visited[sx][sy];
                eat_cnt++;
            }
            else {
                sort(minfish.begin(), minfish.end());
                sx = minfish[0].first;
                sy = minfish[0].second;
                map[sx][sy] = 0;
                sec += visited[sx][sy];
                eat_cnt++;
            }
        }
    }

    return 0;
}