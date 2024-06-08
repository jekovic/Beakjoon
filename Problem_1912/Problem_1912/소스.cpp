#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

//vector<int> a;


int a[MAX];
int cnt[MAX];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		cnt[i] = k;
		a[i] = k;
	}
	int ret = a[0];
	for (int i = 1; i < n; i++) {
		a[i] = max(a[i], a[i - 1] + cnt[i]);
		if (a[i] > ret) ret = a[i];
	}
	cout << ret;
	return 0;
}