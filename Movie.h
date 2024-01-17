#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include "Profile.h"
using namespace std;

class Movie {
	int i = 0;			// 특정 profile을 호출할 때 사용  selectSeat(), swapSeat() (선택한 자리)
	int j = 0;
	string title;		// 영화 제목
	string time;		// 상영 시간
	string theater;		// 상영관
public:
	Profile profile[11][11]; //9x9의 좌석에서 앞뒤 양옆을 제외할때를 생각해서 하나씩 더 만듦
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