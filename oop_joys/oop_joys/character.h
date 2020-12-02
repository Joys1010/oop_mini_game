#pragma once
#include <string>

using namespace std;

class Character {

public:

	Character() {

	};
	Character(string name, string studentNo, string dept, int age);
	string getName() { return this->name; }
	string getStudNo() { return this->studentNo; }
	string getDept() { return this->dept; }
	int getAge() { return this->age; }

private:

	string name;
	string studentNo;
	string dept;
	int age;
};