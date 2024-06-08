#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c[100000];
vector<int> k[100001];
int res[100001];
int cnt = 0;

void dfs(int n) {
    if (c[n]) {
        return;
    }
    c[n] = true;
    cnt++;
    res[n] = cnt;
    //cout << n << '\n';
    for (int i = 0; i < k[n].size(); i++) {
       // sort(k[n].begin(), k[n].end());
        int y = k[n][i];
        dfs(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        k[a].push_back(b);
        k[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        sort(k[i].begin(), k[i].end());
    }
    dfs(r);/*
    cout << 0;*/
    for (int i = 1; i <= n; i++) {
        cout << res[i] << '\n';
    }
}