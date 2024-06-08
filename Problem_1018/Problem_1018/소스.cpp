#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	
	vector<string> chess;
	
	for (int i = 0; i < b;i++)
	{
		string s;
		cin >> s;
		chess.push_back(s);
	}
	int ret = 0;

	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (chess.at(j) == "B")
			{

			}
			else {

			}
		}
	}


	return 0;
}