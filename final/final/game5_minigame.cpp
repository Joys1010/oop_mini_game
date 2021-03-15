
#define CRT_SECURE_NO_WARNINGS
#include "game5_minigame.h"
#include "game5_Scene.h"
#include <iostream>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include <cmath>

using namespace std;

Game5::Game5() {   //element 초기화
   srand((unsigned int)time(NULL)); //랜덤 설정

   MAPX = 40;
   MAPY = 25;
   PI = 3.14159265;
   NUM_OF_ITEM = 3;

   comment[0] = "뭐가 진짜일까?";
   comment[1] = "햄버거는 b지!";
   comment[2] = "자네, 수업 들으러왔나?";
   comment[3] = "멈춰랏!";
   comment[4] = "눈누 난나";

   //boss
   boss.fig = "♨";
   boss.nMoveX = 1;
   boss.nMoveY = 1;
   boss.nDist = 1.1;
   boss.MoveTime = 30;
   boss.OldTime = clock();
   boss.color = LIGHTRED;

   //players
   player.fig = "◎";
   player.nMoveX = 40;
   player.nMoveY = 20;
   player.nDist = 1;
   player.MoveTime = 30;

   player.OldTime = clock();

   banana.fig = "<<<";
   banana.nMoveX = 20;
   banana.nMoveY = 15;
   banana.GET = true;
   banana.OldTime = clock();
   banana.TIMER = false;
   banana.NewTime = 3; // 5초 동안 유지
   banana.color = YELLOW;

   boss_comment.GET = false;
   boss_comment.TIMER = false;
   boss_comment.NewTime = 3;
   boss_comment.OldTime = clock();

   //ITEMS
   int pos_x;
   int pos_y;
   for (int i = 0; i < NUM_OF_ITEM; i++) {
      pos_x = rand() % MAPX;
      pos_y = rand() % MAPY;
      cau_burger[i].fig = "b";
      cau_burger[i].nMoveX = pos_x;
      cau_burger[i].nMoveY = pos_y;
      cau_burger[i].GET = false;
      cau_burger[i].OldTime = clock();
      cau_burger[i].TIMER = false;
      cau_burger[i].NewTime = 3; // 5초 동안 유지
      cau_burger[i].color = LIGHTGREEN;
   }
   for (int i = 0; i < NUM_OF_ITEM; i++) {
      pos_x = rand() % MAPX;
      pos_y = rand() % MAPY;
      studentIDcard[i].fig = "■";
      studentIDcard[i].nMoveX = pos_x;
      studentIDcard[i].nMoveY = pos_y;
      studentIDcard[i].GET = false;
      studentIDcard[i].OldTime = clock();
      studentIDcard[i].TIMER = false;
      studentIDcard[i].NewTime = 3; // 5초 동안 유지
      studentIDcard[i].color = LIGHTCYAN;
   }
   for (int i = 0; i < NUM_OF_ITEM; i++) {
      pos_x = rand() % MAPX;
      pos_y = rand() % MAPY;
      book[i].fig = "▤";
      book[i].nMoveX = pos_x;
      book[i].nMoveY = pos_y;
      book[i].GET = false;
      book[i].OldTime = clock();
      book[i].TIMER = false;
      book[i].NewTime = 3; // 5초 동안 유지
      book[i].color = LIGHTMAGENTA;
   }

   int realItem = rand() % NUM_OF_ITEM; //init geuine item
   cau_burger[realItem].GET = true;
   studentIDcard[realItem].GET = true;
   book[realItem].GET = true;
}

Game5::~Game5() {};

void Game5::Update() { //hitby 따로 빼기
   clock_t CurTime = clock();
   COORD coor_player = { player.nMoveX, player.nMoveY };
   COORD corr_boss = { boss.nMoveX, boss.nMoveY };

   //boss의 움직임
   if ((CurTime - boss.OldTime) > boss.MoveTime) {
      boss.OldTime = CurTime;
      //player와의 각도를 계산해서 방향 벡터 설정
      double theta = acos(sqrt(pow(coor_player.X - corr_boss.X, 2)) / sqrt(pow(coor_player.X - corr_boss.X, 2) +
         pow(coor_player.Y - corr_boss.Y, 2)));      // 기본 1 사분면
      if (coor_player.Y - corr_boss.Y <= 0 && coor_player.X - corr_boss.X >= 0) { theta = -theta; }   //4 사분면
      if (coor_player.Y - corr_boss.Y >= 0 && coor_player.X - corr_boss.X <= 0) { theta = PI - theta; } //2 사분면
      if (coor_player.Y - corr_boss.Y <= 0 && coor_player.X - corr_boss.X <= 0) { theta = PI + theta; } // 3 사분면
      int distance = sqrt(pow(coor_player.X - corr_boss.X, 2) + pow(coor_player.Y - corr_boss.Y, 2));

      //boss 말풍선
      if (boss_comment.GET == false) {
         if ((distance) % 5 == 0) {   //일정거리 보스에게 다가가면 힌트를 얻음 
            int randomB = rand() % 5;
            boss_comment.fig = comment[randomB];
            boss_comment.GET = true;
            boss_comment.OldTime = clock();
            boss_comment.TIMER = true;
         }
      }
      else {
         if (boss_comment.TIMER == true) {
            if ((float)(CurTime - boss_comment.OldTime) / CLOCKS_PER_SEC > boss_comment.NewTime) {
               boss_commen
