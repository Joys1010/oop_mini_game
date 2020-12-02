#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "view.h"
using namespace std;

Quiz::Quiz(string quesiton, string answer) {

	this->question = question;
	this->answer = answer;
}

bool Quiz::checkCorrect(string try_answer) {

	if (this->answer == try_answer) {
		return true;
	}
	else {
		return false;
	}
}
