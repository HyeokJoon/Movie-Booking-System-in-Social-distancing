#ifndef PROFILE_H
#define PROFILE_H
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

class Profile {
	string name;		// �̸�
	string sex;			// ����
	string phoneNum;	// ��ȭ��ȣ
public:
	Account account;	// ����
	string seaton;		// �¼��̸�				>> "A1"
	string seatoff;		// ��ȸ�� �Ÿ��α� �¼� >> "  "
	string seatbook;	// ����� �¼��̸�		>> "||"
	string seat;		// ȭ�鿡 ��µǴ� �̸�
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