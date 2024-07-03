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

	string s;
	cin >> s;

	int zero = 0, one = 0;

	for (int i = 0; i != s.size(); i++) {
		if (s[i] != s[i + 1]) {
			if (s[i] == '1')	one++;
			else zero++;
		}
	}

	int result = min(one, zero);

	cout << result;

	return 0;
}