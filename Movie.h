#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include "Profile.h"
using namespace std;

class Movie {
	int i = 0;			// Ư�� profile�� ȣ���� �� ���  selectSeat(), swapSeat() (������ �ڸ�)
	int j = 0;
	string title;		// ��ȭ ����
	string time;		// �� �ð�
	string theater;		// �󿵰�
public:
	Profile profile[11][11]; //9x9�� �¼����� �յ� �翷�� �����Ҷ��� �����ؼ� �ϳ��� �� ����
	Movie();
	virtual ~Movie() {}
	void setMovie(string n, string t, string p);
	void showMovie();
	void makeSeat();
	void showSeat();
	Profile& selectSeat();
	void checkSeat();
	void swapSeat();
	Profile& getProfile(int a, int b);
	string getTitle();
	string getTime();
	string getTheater();
};





#endif