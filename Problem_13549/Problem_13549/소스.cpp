#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 100001
using namespace std;
int n, x;
bool visited[MAX];

int d(int k) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> pq;
	//priority_queue<pair<int, int>> pq;
	pq.push({ 0, k });
	visited[k] = true;

	while (!pq.empty()) {
		int dis = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cur == x) return dis;

		if (cur * 2 < MAX && !visited[cur*2]) {
			pq.push({ dis, cur * 2 });
			visited[cur * 2] = true;
		}
	
		if (cur + 1 < MAX && !visited[cur+1]) {
			pq.push({ (dis + 1), cur + 1 });
			visited[cur + 1] = true;
		}

		if (cur - 1 >= 0 && !visited[cur-1]) {
			pq.push({ (dis + 1) , cur - 1 });
			visited[cur - 1] = true;
		}	
	}
}

int main() {
	cin >> n >> x;
	
	int res = d(n);

	cout << res;

	return 0;

}