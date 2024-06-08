#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 27

using namespace std;
pair<char, char> a[MAX];

void preorder(char ptr) {
	if (ptr == '.') {
		return;
	}
	cout << ptr;
	preorder(a[ptr - 'A'].first);
	preorder(a[ptr - 'A'].second);
}


void inorder(char ptr) {
	if (ptr == '.') {
		return;
	}
	inorder(a[ptr - 'A'].first);
	cout << ptr;
	inorder(a[ptr - 'A'].second);
}

void postorder(char ptr) {
	if (ptr == '.') {
		return;
	}
	postorder(a[ptr - 'A'].first);
	postorder(a[ptr - 'A'].second);
	cout << ptr;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char q, w, e;
		cin >> q >> w >> e;
		a[q - 'A'].first = w;
		a[q - 'A'].second = e;
	}


	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');

	return 0;
}