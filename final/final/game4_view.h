#pragma once
#include <string>
#include <vector>
#include "game4_quiz.h"
#include "game4_classroom.h"


class View4 {

public:
	View4() {

	};
	vector <vector <int>> startView();
	vector <vector <int>> classView(Classroom enter_room);
	string quizView(Classroom enter_room);
};