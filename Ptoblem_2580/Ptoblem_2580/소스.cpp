#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int cnt = 0;
vector<pair<int, int>> zeros;
bool isposible = false;
int map[9][9];

void print_map() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool check(int x, int y, int val) {
	for (int i = 0; i < 9; i++) {
		if (map[x][i] == val) return false;
		if (map[i][y] == val) return false;
	}
	int cx = x / 3;
	int cy = y / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[cx * 3 + i][cy * 3 + j] == val) return false;
		}
	}
	return true;
}

void dfs(int cur) {
	if (isposible == true) return;
	if (cur == cnt) {
		print_map();
		isposible = true;
	}
	else {
		int nx = zeros[cur].first;
		int ny = zeros[cur].second;
		for (int i = 1; i <= 9; i++) {
			if (check(nx, ny, i)) {
				map[nx][ny] = i;
				dfs(cur + 1);
				map[nx][ny] = 0;
			}
		}
	}
}
//
//void bfs(vector<vector<int>>& map) {
//	
//	queue<pair<int, int>> q;
//	for (int i = 0; i != zeros.size(); i++) {
//		q.push({ zeros[i].first , zeros[i].second });
//	}
//	
//	while (!q.empty()) {
//		int cx = q.front().first;
//		int cy = q.front().second;
//		q.pop();
//		
//		// 가로
//		vector<int> g(10, 0);
//		int tg = 0;
//		for (int i = 0; i < 9; i++) {
//			g[map[cx][i]] = 1;
//		}
//		for (int i = 1; i <= 9; i++) {
//			if (g[i] == 0) {
//				tg = i;
//			}
//		}
//
//		//세로
//		vector<int> s(10, 0);
//		int ts = 0;
//		for (int i = 0; i < 9; i++) {
//			s[map[i][cy]] = 1;
//		}
//		for (int i = 1; i <= 9; i++) {
//			if (s[i] == 0){
//				ts = i;
//			}
//		}
//		
//		//네모
//		int tn = 0;
//		vector<int> n(10, 0);
//		int t1 = cx / 3;
//		int t2 = cx % 3;
//		int t3 = cy / 3;
//		int t4 = cy % 3;
//
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				n[map[t1*3+i][j+3*t3]] = 1;
//			}
//		}
//
//		for (int i = 1; i <= 9; i++) {
//			if (n[i] == 0) {
//				tn = i;
//			}
//		}
//
//		//다끝나도 빈칸 못찾으면 다시 큐에 넣기 
//		if (ts == tn and tn == tg) {
//			map[cx][cy] = ts;
//		}
//		else {
//			q.push({ cx, cy });
//		}
//	}
//}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

//	vector<vector<int>> map(9, vector<int>(9, 0));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int t;
			cin >> t;
			map[i][j] = t;
			if (t == 0) {
				zeros.push_back({ i, j });
			}
		}
	}
	cnt = zeros.size();
	dfs(0);
	/*bfs(map);
		
	print_map(map);*/

	return 0;
}