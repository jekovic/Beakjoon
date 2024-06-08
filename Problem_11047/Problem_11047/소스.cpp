#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> coin;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		coin.push_back(c);
	}
	
	sort(coin.begin(), coin.end(), compare);

	int cnt = 0;

	for (int i = 0; i != coin.size(); i++) {
		cnt += k / coin[i];
		k %= coin[i];
	}

	cout << cnt;

	return 0;
}