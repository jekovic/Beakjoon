#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10001

using namespace std;
int n;
vector<int> v;
int node[MAX];

void postorder(int start, int end) {
	if (start >= end) {
		return;
	}

	if (start == end - 1) {	// root Ãâ·Â
		cout << v[start] << '\n';
		return;
	}
	
	int idx = start + 1;
	while (idx < end) {
		if (v[start] < v[idx])
			break;
		idx++;
	}
	postorder(start + 1, idx);
	postorder(idx, end);
	cout << v[start] << '\n';
}

int cnt = 0;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	while (cin >> n) {
		v.push_back(n);
	}	

	postorder(0, v.size());

	return 0;
}