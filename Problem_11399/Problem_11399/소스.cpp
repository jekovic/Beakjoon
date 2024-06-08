#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> c;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		c.push_back(k);
	}
	sort(c.begin(), c.end());
	int res = 0;
	int ret = 0;
	for (int i = 0; i != c.size(); i++) {
		res += c[i];
		ret += res;
	}
	cout << ret;
	return 0;
}