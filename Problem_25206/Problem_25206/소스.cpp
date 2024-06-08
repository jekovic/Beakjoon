#include <iostream>
#include <string>
using namespace std;

float Grade(string s) {	//학점 환산

	if (s.compare("A+") == 0) {
		return 4.5;
	}
	else if (s.compare("A0") == 0) {
		return 4.0;
	}
	else if (s.compare("B+") == 0) {
		return 3.5;
	}
	else if (s.compare("B0") == 0) {
		return 3.0;
	}
	else if (s.compare("C+") == 0) {
		return 2.5;
	}
	else if (s.compare("C0") == 0) {
		return 2.0;
	}
	else if (s.compare("D+") == 0) {
		return 1.5;
	}
	else if (s.compare("D0") == 0) {
		return 1.0;
	}
	else if (s.compare("F") == 0) {
		return 0.0;
	}
	else {

	}
}

int main() {

	float sum_score = 0.0;
	float sum_grade = 0.0;//학점 총합

	for (int i = 0; i < 20; i++) {
		string s;
		float score;
		string grade;
		
		cin >> s >> score >> grade;

		if (grade.compare("P") == 0) {
			continue;
		}

		sum_score += score;
		sum_grade += score*Grade(grade);
		
	}

	printf("%.6f",sum_grade / sum_score);


	return 0;
}