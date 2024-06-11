#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int result;
vector<int> men_p, men_n, women_p, women_n;

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp > 0) {
            men_p.push_back(temp);
        }
        else {
            men_n.push_back(abs(temp));
        }
    }

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp > 0) {
            women_p.push_back(temp);
        }
        else {
            women_n.push_back(abs(temp));
        }
    }

    sort(men_p.begin(), men_p.end());
    sort(men_n.begin(), men_n.end());
    sort(women_p.begin(), women_p.end());
    sort(women_n.begin(), women_n.end());
}

void solve() {
    int i = 0, j = 0;

    while (i < men_p.size() and j < women_n.size()) {
        if (men_p[i] < women_n[j]) {
            result++;
            i++;
            j++;
        }
        else {
            j++;
        }
    }

    i = 0; j = 0;

    while (i < men_n.size() and j < women_p.size()) {
        if (men_n[i] > women_p[j]) {
            result++;
            i++;
            j++;
        }
        else {
            i++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();

    solve();

    cout << result;

    return 0;
}