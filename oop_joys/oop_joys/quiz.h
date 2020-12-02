#pragma once
#include <string>

using namespace std;

class Quiz {

public:
	Quiz() {

	};
	Quiz(string question, string answer);

	string question;
	string answer;

	bool checkCorrect(string try_answer);
};