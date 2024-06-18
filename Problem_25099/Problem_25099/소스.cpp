#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;
vector<string> res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    set<string> s_;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        string temp = s;
        sort(temp.begin(), temp.end());
        if (s_.empty()) {
            s_.insert(temp);
            res.push_back(s);
        }
        else {
            if (s_.find(temp) == s_.end()) // 일치하는 것 없음
            {
                s_.insert(temp);
                res.push_back(s);
            }
        }
    }

    for (string s : res) {
        cout << s << '\n';
    }

    return 0;
}