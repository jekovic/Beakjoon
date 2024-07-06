#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<pair<int, int> > v;
	for (int i = 0;i < n;i++)
	{
		int ms, ds, me, de;
		cin >> ms >> ds >> me >> de;
		v.push_back(make_pair(ms * 100 + ds, me * 100 + de));
	}
	sort(v.begin(), v.end());
	int t = 301, res = 0, idx = 0;
	while (t < 1201)
	{
		int nxt_t = t;
		for (int i = idx;i < n;i++)
		{
			if (v[i].first <= t && v[i].second > nxt_t) {
				nxt_t = v[i].second;
				idx = i;
			}
			else if (v[i].first > t) break; 
		}
		
		if (nxt_t == t)	{
			cout << 0 << "\n";
			return 0;
		}
		t = nxt_t;
		res++;
	}
	cout << res << "\n";

	return 0;
}