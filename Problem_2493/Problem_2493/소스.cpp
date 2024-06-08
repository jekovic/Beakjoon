#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	vector<int> v(N, 0); 
	vector<int> s;

	for (int i = 0; i < N; i++) {
		cin >> v[i];

		while (!s.empty() and v[s.back()] < v[i])
			s.pop_back();
		if (!s.empty()) cout << s.back() + 1 << ' ';
		else cout << 0 << ' ';
		s.push_back(i);
	}


	return 0;
}