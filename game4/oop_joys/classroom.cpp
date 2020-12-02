#include "classroom.h"

Classroom::Classroom(int student_num, int seat_num, string class_name, string professor, Quiz quiz) {

	this->student_num = student_num;
	this->seat_num = seat_num;
	this->class_name = class_name;
	this->professor = professor;
	this->class_quiz = quiz;
}