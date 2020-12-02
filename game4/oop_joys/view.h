#pragma once
#include <string>
#include <vector>
#include "quiz.h"
#include "classroom.h"


class View {

public:
	View() {

	};
	vector <vector <int>> startView();
	vector <vector <int>> classView(Classroom enter_room);
	string quizView(Classroom enter_room);
};