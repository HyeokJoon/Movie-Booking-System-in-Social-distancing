#ifndef PROFILE_H
#define PROFILE_H
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

class Profile {
	string name;		// 이름
	string sex;			// 성별
	string phoneNum;	// 전화번호
public:
	Account account;	// 계좌
	string seaton;		// 좌석이름				>> "A1"
	string seatoff;		// 사회적 거리두기 좌석 >> "  "
	string seatbook;	// 예약된 좌석이름		>> "||"
	string seat;		// 화면에 출력되는 이름
	Profile();
	virtual ~Profile() {}
	void Login();
	void showProfile();
	void cancle();
	string getPhoneNum();
	string getName();
	string getSex();
};


#endif