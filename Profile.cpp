#include "Profile.h"
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

// 기본 생성자
Profile::Profile() {
	name = "이름";
	sex = "성별";
	phoneNum = "전화번호";
	seatoff = "  ";
	seatbook = "||";
}

// 예약 전 개인정보 입력
void Profile::Login() {
	cout << "이름을 입력하세요 : ";
	cin >> this->name;
	int s = 0;
	do {
		cout << "성별을 선택하세요 : 1. 남성   2. 여성" << endl;
		cin >> s;
		if (s == 1) {
			this->sex = "남성";
			break;
		}
		else if (s == 2) {
			this->sex = "여성";
			break;
		}
	} while (1);
	cout << "전화번호를(-)기호 없이 띄어쓰지 않고 입력하세요 : ";
	cin >> this->phoneNum;
	cout << "로그인이 완료되었습니다" << endl << endl;
}

// 예약취소 시 원래상태로 되돌리기
void Profile::cancle() {
	name = "이름";
	sex = "성별";
	phoneNum = "전화번호";
}

// 입력한 개인정보 확인 시 사용
void Profile::showProfile() {
	cout << "이름 : " << name << ", 성별 : " << sex << ", 전화번호 : " << phoneNum << ", 좌석 : " << seaton << endl;
}

// private멤버 phoneNum 반환
string Profile::getPhoneNum() {
	return phoneNum;
}

// private멤버 name 반환
string Profile::getName() {
	return name;
}

// private멤버 sex 반환
string Profile::getSex() {
	return sex;
}
