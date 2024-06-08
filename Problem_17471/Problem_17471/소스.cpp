//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <stack>
//#include <cmath>
//#include <cstring>
//#define MAX 11
//#define INF 1e9
//
//using namespace std;
//
//int N;
//int map[MAX][MAX];
//int people[MAX];
//int result = INF;
//vector<bool> visited;
//
////먼저 선거구 나누기
//// 만약 안눠지면 -1 출력하고 종료
////1개부터 N-1개까지 고르기
////인구차이 계산
//
//void input() {
//	cin >> N;
//	visited.assign(N + 1, false);
//
//	for (int i = 1; i <= N; i++) {
//		cin >> people[i];
//	}
//
//	for (int i = 1; i <= N; i++) {
//		int q;
//		cin >> q;
//		for (int j = 0; j < q; j++) {
//			int temp;
//			cin >> temp;
//			map[i][temp] = true;
//			map[temp][i] = true;
//		}
//	}
//}
//
//bool bfs(vector<int>& a, bool c) {
//	vector<int> v(N+1, 0);
//	queue<int> temp_q;
//	temp_q.push(a[0]);
//	v[a[0]] = 1;
//	int cnt = 1;
//
//	while (!temp_q.empty()) {
//		int t = temp_q.front();
//		temp_q.pop();
//
//		for (int i = 1; i <= N; i++) {
//			if (visited[i] == c and map[t][i] == true and v[i] == false) {
//				v[i] = true;
//				temp_q.push(i);
//				cnt++;
//			}
//		}
//	}
//	if (cnt == a.size()) return true;
//	else return false;
//}
//
//bool cango(vector<int>& a, vector<int>& b) {
//	if (bfs(a, true) != true) return false;
//	if (bfs(b, false) != true) return false;
//	return true;
//}
//
//void cal_res(vector<int>& a, vector<int>& b) {
//	int X = 0;
//	int Y = 0;
//
//	for (const auto& i : a) {
//		X += people[i];
//	}
//	for (const auto& j : b) {
//		Y += people[j];
//	}
//
//	int d = abs(X - Y);
//
//	result = min(d, result);
//}
//
//void dfs(int x, int cnt) {
//	if (cnt >= 1) {
//		//선택한것들 중에서 연결되었는지 확인하기
//		vector<int> a;
//		vector<int> b;
//		for (int i = 1; i <= N; i++) {
//			if (visited[i])
//				a.push_back(i);
//			else
//				b.push_back(i);
//		}
//		
//		//연결 가능하면 계산 
//		if (cango(a, b)) {
//			cal_res(a, b);
//		}
//	}
//
//	if (cnt == N - 1) return;
//
//	for (int i = x; i <= N; i++) {
//		if (!visited[i]) {
//			visited[i] = true;
//			dfs(i, cnt+1);
//			visited[i] = false;
//		}
//	}
//}
//
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	input();
//
//	dfs(1, 0);
//
//	if (result == INF) cout << -1;
//	else cout << result;
//
//	return 0;
//}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 11
#define INF 1e9

using namespace std;

int N;
int map[MAX][MAX];
int result = INF;
int people[MAX];
int visited[MAX];

void input() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> people[i];
    }

    for (int i = 1; i <= N; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int t;
            cin >> t;
            map[i][t] = true;
        }
    }
}

bool bfs(vector<int>& v, bool c) {
    vector<int> vi(N + 1, 0);
    queue<int> q;
    q.push(v[0]);
    vi[v[0]] = 1;
    int cnt = 1;

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (visited[i] == c and map[t][i] == true and vi[i] == false) {
                vi[i] = true;
                cnt++;
                q.push(i);
            }
        }
    }
    if (cnt == v.size()) return true;
    else return false;
}

bool check() {
    vector<int> a, b;
    for (int i = 1; i <= N; i++) {
        if (visited[i])
            a.push_back(i);
        else
            b.push_back(i);
    }

    if (bfs(a, true) != true) return false;
    if (bfs(b, false) != true) return false;

    return true;
}

void cal_res() {
    int X = 0;
    int Y = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) X += people[i];
        else Y += people[i];
    }
    int sum = abs(X - Y);
    result = min(result, sum);
}

void dfs(int x, int cnt) {
    if (cnt >= 1) {
        if (check()) {
            cal_res();
        }
    }

    if (cnt == N - 1) return;

    for (int i = x; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();

    dfs(1, 0);

    if (result == INF) cout << -1;
    else cout << result;

    return 0;
}