#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10

using namespace std;
int a[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int> > zero;

void bfs() {

}


void printST() {

	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	

	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) {
				visited[i][j] = true;
				zero.push_back({ i, j });
			}
		}
	}

	printST();

	return 0;
}