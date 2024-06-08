#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 10001

class Edge {
public:
	int node;
	int val;
	Edge(int a, int b) {
		this->node = a;
		this->val = b;
	}
};

vector<Edge> a[MAX];	// 임계경로 판단 
vector<Edge> b[MAX];	// 역추적하면서 count

int n, result[MAX], isDegree[MAX], value[MAX];
int start_point, finish_point;

void topology_sort()
{
	queue<int> q;
	q.push(start_point);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int j = 0; j != a[x].size(); j++) {
			Edge y = Edge(a[x][j].node, a[x][j].val);
			if (result[y.node] <= y.val + result[x]) {
				result[y.node] = y.val + result[x];
			}
			if (--isDegree[y.node] == 0) {
				q.push(y.node);
			}
		}
	}
	int count = 0;
	q.push(finish_point);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < b[x].size(); i++) {
			Edge y = Edge(b[x][i].node, b[x][i].val);
			if (result[x] - result[y.node] == y.val) {
				count++;

				if (value[y.node] == 0) {
					q.push(y.node);
					value[y.node] = 1;
				}
			}
		}
	}

	cout << result[finish_point] << '\n' << count;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;

		isDegree[t2]++;

		a[t1].push_back(Edge(t2, t3));
		b[t2].push_back(Edge(t1, t3));
	}

	cin >> start_point >> finish_point;

	topology_sort();

	return 0;
}