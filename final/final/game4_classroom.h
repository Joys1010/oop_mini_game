#pragma once
#include <string>
#include "game4_quiz.h"

using namespace std;

class Classroom {
public:

	Classroom() {

	};
	Classroom(int student_num, int seat_num, string class_name, string professor, Quiz quiz);

	int student_num;
	int seat_num;
	string class_name;
	string professor;

	string getQuestion() { return this->class_quiz.question; }
	string getAnswer() { return this->class_quiz.answer; }

	int getStdNum() { return this->student_num; }
	int getSeatNum() { return this->seat_num; }

	Quiz class_quiz;

};