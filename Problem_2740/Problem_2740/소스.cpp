#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> a[MAX];
vector<int> b[MAX];
vector<int > res[MAX];

int main() {
	int n, m, k;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int c;
			cin >> c;
			a[i].push_back(c);
		}
	}

	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int c;
			cin >> c;
			b[i].push_back(c);
		}
	}

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < k; j++) {
			int temp = 0;
			for (int l = 0; l < m; l++) {
				temp += a[i][l] * b[l][j];
			}
			res[i].push_back(temp);		
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << res[i][j] <<' ';
		}
		cout << '\n';
	}

	return 0;
}