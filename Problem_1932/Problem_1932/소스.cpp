#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 501

using namespace std;
vector<int> a[MAX];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			int k;
			cin >> k;
			a[i].push_back(k);
		}		
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				a[i][j] += a[i - 1][j];
			}
			else if (i == j) {
				a[i][j] += a[i - 1][j - 1];
			}
			else {
				a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
			}
		}
	}
	sort(a[n - 1].rbegin(), a[n - 1].rend());
	cout << a[n - 1][0];
	return 0;
}