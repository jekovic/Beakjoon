#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> inorder;
vector<int> postorder;
int index[MAX];
vector<int> res;
int n;
/*
	1. inorder가 루트를 만나기 전까지는 왼쪽

*/
void preorder(int in_s, int in_e, int post_s, int post_e) {
	if (in_s > in_e || post_s > post_e) {
		return;
	}

	int rootidx = index[postorder[post_e]];
	int leftidx = rootidx - in_s;
	int rightidx = in_e - rootidx;
	cout << inorder[rootidx] << ' ';

	preorder(in_s, rootidx-1, post_s, post_s + leftidx-1);
	preorder(rootidx+1, in_e, post_s + leftidx, post_e-1);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		inorder.push_back(temp);
		index[temp] = i;
	}

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		postorder.push_back(temp);
	}

	
	preorder(0, n-1, 0, n-1);


	return 0;
}