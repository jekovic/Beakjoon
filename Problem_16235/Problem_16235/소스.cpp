//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <stack>
//#include <cstring>
//#define MAX 11
//
//using namespace std;
//
//int N, M, K;
//int A[MAX][MAX]; // 겨울에 줄 양분
//int Y[MAX][MAX]; //양분
//// 8개 방향
//// 12시부터 시계방향
//int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
////vector<int> map[MAX][MAX];
//deque<int> tr[MAX][MAX];
//
//class tree {
//public:
//	int x, y, z;
//	bool alive;
//	tree(int q, int w, int e) {
//		this->x = q;
//		this->y = w;
//		this->z = e;
//		this->alive = true;
//	}
//	bool operator < (tree& t) {
//		if (this->x == t.x and this->y == t.y) {
//			return this->z < t.z;
//		}
//		return this->x < t.z and this->y < t.y;
//		//return this->z < t.z;
//	}
//};
//vector<tree> t;
//
//int alive_tree() {
//	int cnt = 0;
//	for (int i = 0; i != t.size(); i++) {
//		if (t[i].alive) {
//			cnt++;
//		}
//	}
//	return cnt;
//}
//
//void spring() {
//
//	sort(t.begin(), t.end());
//
//	for (int i = 0; i != t.size(); i++) {
//		int x = t[i].x;
//		int y = t[i].y;
//		int z = t[i].z;
//		
//		if (Y[x][y] >= z and t[i].alive) {
//			Y[x][y] -= z;
//			t[i].z++;
//		}
//		else {
//			Y[x][y] += z / 2;
//			t.erase(t.begin() + i);
//		}
//	}
//}
////
////void summer() {
////	for (int i = 0; i < t.size(); i++)
////	{
////		int x = t[i].x;
////		int y = t[i].y;
////		int z = t[i].z;
////
////		if (!t[i].alive) {
////			
////		}
////	}
////
////}
//
//void fall() {
//	for (int i = 0; i < t.size(); i++)
//	{
//		int x = t[i].x;
//		int y = t[i].y;
//		int z = t[i].z;
//
//		if (z % 5 == 0 and t[i].alive) {
//			for (int j = 0; j < 8; j++) {
//				int nx = x + dx[j];
//				int ny = y + dy[j];
//				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
//				t.push_back(tree(nx, ny, 1));
//			}
//		}
//	}
//	sort(t.begin(), t.end());
//}
//
//void winter() {
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			Y[i][j] += A[i][j];
//		}
//	}
//}
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N >> M >> K;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> A[i][j];
//		}
//	}
//
//	//양분 초기화
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			Y[i][j] = 5;
//		}
//	}
//
//	//심은 나무 좌표, 나이
//	for (int i = 0; i < M; i++) {
//		int x, y, z;
//		cin >> x >> y >> z;
//		tr[x - 1][y - 1].push_back(z);
//		t.push_back(tree(x-1, y-1, z));
//	}
//
//	//K년 동안 일하기 
//	for (int p = 0; p < K; p++) {
//		spring();
//		//summer();
//		fall();
//		winter();
//	}
//
//	cout << alive_tree();
//
//	return 0;
//}
//
//


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define MAX 11

using namespace std;

int N, M, K;
int A[MAX][MAX]; // 겨울에 줄 양분
int Y[MAX][MAX]; //양분
// 8개 방향
// 12시부터 시계방향
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//vector<int> map[MAX][MAX];
deque<int> tr[MAX][MAX];


class tree {
public: 
	int x, y, z;
	tree(int q, int w, int e)
	{
		this->x = q;
		this->y = w;
		this->z = e;
	}
};

vector<tree> dead, ali;

void spring() {
	dead.clear();
	ali.clear();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tr[i][j].size() == 0) continue;

			sort(tr[i][j].begin(), tr[i][j].end());
			int n = tr[i][j].size();

			for (int k = 0; k < n; k++) {
				int cnt = tr[i][j].front();
				tr[i][j].pop_front();
				if (Y[i][j] >= cnt) {
					Y[i][j] -= cnt;
					tr[i][j].push_back(cnt + 1);

					if ((cnt + 1) % 5 == 0) {
						ali.push_back(tree(i, j, cnt + 1));
					}
				}
				else {
					dead.push_back(tree(i, j, cnt));
				}
			}
		}	
	}
}

void summer()
{
	for (int i = 0; i != dead.size(); i++) {
		int x = dead[i].x;
		int y = dead[i].y;
		int z = dead[i].z;

		Y[x][y] += z / 2;
	}
}

void fall() {
	for (int i = 0; i != ali.size(); i++) {
		int x = ali[i].x;
		int y = ali[i].y;
		int z = ali[i].z;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			tr[nx][ny].push_back(1);
		}
	}
}

void winter() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Y[i][j] += A[i][j];
		}
	}
}

int  count_tree() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result += tr[i][j].size();
		}
	}
	return result;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			Y[i][j] = 5;
		}
	}

	//심은 나무 좌표, 나이
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tr[x - 1][y - 1].push_back(z);
	}

	//K년 동안 일하기 
	for (int p = 0; p < K; p++) {
		spring();
		summer();
		fall();
		winter();
	}

	cout << count_tree();

	return 0;
}