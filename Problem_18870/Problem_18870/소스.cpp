#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>arr;
vector<int>temp;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		arr.push_back(k);
		temp.push_back(k);
	}

	sort(arr.begin(), arr.end());

	/*
		같은 수들은 지우는 코드
	*/
	/*int a = 0;
	int k = arr.size();
	while (1) {
		if (a + 1 >= k) {
			break;
		}
		else if (arr[a] == arr[a + 1]) {
			arr.erase(arr.begin() + a);
			k--;
		}
		else {
			a++;
		}
	}*/
	arr.erase(unique(arr.begin(), arr.end()), arr.end());


	/*for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			if (temp[i] == arr[j]) {
				temp[i] = j;
			}
		}
	}
	
	for (int i = 0;i < n; i++) {
		cout << temp[i] << ' ';
	}*/

	for (int i = 0; i < n; i++) {
		auto idx = lower_bound(arr.begin(), arr.end(), temp[i]);
		cout << idx - arr.begin() << ' ';
	}


	return 0;
}