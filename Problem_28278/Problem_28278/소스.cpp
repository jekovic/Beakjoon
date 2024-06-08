#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    stack<int> s;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        if (k == 1) {
            int a;
            cin >> a;
            s.push(a);
        }
        else if (k == 2) {
            if (!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }
            else {
                cout << "-1" << '\n';
            }
        }
        else if (k == 3) {
            cout << s.size() << '\n';
        }
        else if (k == 4) {
            if (s.empty()) {
                cout << "1" << '\n';
            }
            else {
                cout << "0" << '\n';
            }
        }
        else if (k == 5) {
            if (!s.empty()) {
                cout << s.top() << '\n';
            }
            else {
                cout << "-1" << '\n';
            }
        }
    }

    return 0;
}