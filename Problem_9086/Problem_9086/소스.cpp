#include <iostream>
#include <string>

using namespace std;


int main()
{
	unsigned short N;
	cin >> N;

	for (int i = 0; i < N;i++) {
		string s;
		cin >> s;
		cout << s.front() << s.back() << endl;
	}


	return 0;
}