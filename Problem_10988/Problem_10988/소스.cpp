#include <iostream>
#include <string>

using namespace std;

int Palin(string s) {
	string k = "";
	for (int i = s.size()-1;i>=0; i--){
		string temp = string(1, s.at(i));
		k.append(temp);
	}

	if (s.compare(k) == 0) {
		return 1;
	
	}// °°À¸¸é 0
	else {
		return 0;
	}

}

int main() {

	string s;
	cin >> s;
	cout << Palin(s);

	return 0;
}