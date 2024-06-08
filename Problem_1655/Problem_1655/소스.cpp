#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	priority_queue<int, vector<int>, greater<int>> min_heap;	//오른차순
	priority_queue<int> max_heap;	// 내림차순

	for (int i = 1; i <=N; i++) {
		int t;
		cin >> t;
		if (min_heap.size() == max_heap.size()) {
			max_heap.push(t);
		}
		else {
			min_heap.push(t);
		}
		if (!min_heap.empty() and !max_heap.empty() and max_heap.top() > min_heap.top()) {
			int max_val, min_val = 0;
			max_val = max_heap.top();
			min_val = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(min_val);
			min_heap.push(max_val);
		}
		cout << max_heap.top() << '\n';
	}

	return 0;
}