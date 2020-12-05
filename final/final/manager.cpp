#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include "manager.h"


vector <string> Manager::game_startScreen() {

	string name;
	string id;
	string dept;
	vector <string> info;

	cout << "                              ====================================================" << endl;
	cout << "                                    #####  #####  #####  #####  #####  #####" << endl;
	cout << "                                    #      #      #      #   #  #   #  #" << endl;
	cout << "                                    ####   #####  #      #####  #####  ####" << endl;
	cout << "                                    #          #  #      #   #  #      #" << endl;
	cout << "                                    #####  #####  #####  #   #  #      #####" << endl;
	cout << endl;
	cout << "                                           #####  #####  #####  #####" << endl;
	cout << "                                           #      #   #  #        #  " << endl;
	cout << "                                           #####  #   #  ####     #  " << endl;
	cout << "                                               #  #   #  #        #  " << endl;
	cout << "                                           #####  #####  #        #    ##" << endl;
	cout << "                              ====================================================" << endl;
	cout << "                                                   < TEAM 4 >" << endl;
	cout << endl;
	cout << "                                           Please enter your name : ";
	cin >> name;
	cout << "                                            Please enter your ID : ";
	cin >> id;
	cout << "                                      Please enter your department name : ";
	cin >> dept;

	info.push_back(name);
	info.push_back(id);
	info.push_back(dept);

	return info;
}
void Manager::game_endScreen(Player player) {

	cout << "                              ====================================================" << endl;
	cout << "                                    #####  #####  #####  #####  #####  #####" << endl;
	cout << "                                    #      #      #      #   #  #   #  #" << endl;
	cout << "                                    ####   #####  #      #####  #####  ####" << endl;
	cout << "                                    #          #  #      #   #  #      #" << endl;
	cout << "                                    #####  #####  #####  #   #  #      #####" << endl;
	cout << endl;
	cout << "                                           #####  #####  #####  #####" << endl;
	cout << "                                           #      #   #  #        #  " << endl;
	cout << "                                           #####  #   #  ####     #  " << endl;
	cout << "                                               #  #   #  #        #  " << endl;
	cout << "                                           #####  #####  #        #    ##" << endl;
	cout << "                              ====================================================" << endl;
	cout << "                                                   < TEAM 4 >" << endl;
	cout << endl;
	cout << "                                            Player name : " << player.getName() << endl;
	cout << "                                              Player ID : " << player.getID() << endl;
	cout << "                                        Player department name : " << player.getDepartment() << endl;
	cout << "                                            Player EXP : " << player.getExp()<< endl;
	cout << endl;

	if (player.getExp() == 300) { //5*6*10
		cout << "                                          You are the BEST!!!" << endl;
	}
	else if (player.getExp() > 250) {
		cout << "                                          You did a great job!!!" << endl;
	}
	else if (player.getExp() > 200) {
		cout << "                                          You did a good job!!!" << endl;
	}
	else if (player.getExp() > 150) {
		cout << "                                          You did a nice job!!!" << endl;
	}
	else if (player.getExp() > 100) {
		cout << "                           Little bit disappointing... How about trying again?" << endl;
	}
	else if (player.getExp() > 50) {
		cout << "                                   Disappointing..... You can try again" << endl;
	}
	else if (player.getExp() > 0) {
		cout << "                               Your EXP is really bad. You must try again." << endl;
	}










}
