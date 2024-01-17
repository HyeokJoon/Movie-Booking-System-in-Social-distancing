#include <iostream>
#include <string>
#include "Movie.h"
#include "Profile.h"
using namespace std;

// 기본생성자
Movie::Movie() {
	title = "이름";
	time = "시간";
	theater = "상영관";
}

// progile 참조 반환
Profile& Movie::getProfile(int a, int b) {
	return profile[a][b];
}

//Movie 변수 입력(영화제목, 상영시간, 상영관)
void Movie::setMovie(string n, string t, string p) {
	this->title = n;
	this->time = t;
	this->theater = p;
}

// 선택한 영화를 확인할 때 사용
void Movie::showMovie() {
	cout << "영화 : " << this->title << ", 시간 : " << this->time << ", 상영관 : " << this->theater << endl << endl;
}

// 좌석표 만들기 (좌석 이름 입력 -> profile 의 seat, seaton)
void Movie::makeSeat() {
	string a = "@";							// 보이는부분은 A~I까지
	for (int i = 0; i < 11; i++) {
		string b = "0";						// 보이는부분은 1~9까지
		for (int j = 0; j < 11; j++) {
			profile[i][j].seaton = a + b;
			profile[i][j].seat = profile[i][j].seaton;
			b[0]++;
		}a[0]++;
	}
}

// 좌석표 보여주기 (profile.seat)
void Movie::showSeat() {
	cout << "<원하시는 좌석을 선택해 주세요>" << endl << endl;
	cout << "\t\t  스크린" << endl;
	cout << "------------------------------------------------" << endl;
	for (int i = 1; i < 10; i++) {		//A~I까지
		cout << "|";
		for (int j = 1; j < 10; j++) {	//1~9까지
			cout << " " << profile[i][j].seat << " |";
		}cout << endl;
	}cout << endl;
	cout << "------------------------------------------------" << endl;
}

// 좌석선택 선택 후 선택한 자리의 프로필객체의 참조 리턴
Profile& Movie::selectSeat() {
	string select;
	cin >> select;
	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			// 예약 가능한 자리(profile.seat) && 실제 존재하는자리(profile.seaton) -> 같은자리 예약 방지
			if (select == profile[i][j].seat && select == profile[i][j].seaton) {
				profile[i][j].Login();			// 프로필 입력 (이름, 성별, 전화번호)
				return this->profile[i][j];		// 선택종료 프로필 참조 리턴
			}
		}
	}
	// 전부 찾아보고 없는경우
	cout << "빈자리를 선택해주세요(대문자로 입력해주세요) : ";
	return selectSeat();
}

// 결제동의 이후 선택한자리 및 거리두기 좌석 상태변경
void Movie::swapSeat() {
	profile[i][j].seat = profile[i][j].seatbook;
	profile[i][j + 1].seat = profile[i][j + 1].seatoff;
	profile[i][j - 1].seat = profile[i][j - 1].seatoff;
	profile[i + 1][j].seat = profile[i + 1][j].seatoff;
	profile[i - 1][j].seat = profile[i - 1][j].seatoff;
}

// 예약취소 후 자리상태 재설정
void Movie::checkSeat() {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (profile[i][j].seat == "||") {
				profile[i][j + 1].seat = profile[i][j + 1].seatoff;
				profile[i][j - 1].seat = profile[i][j - 1].seatoff;
				profile[i + 1][j].seat = profile[i + 1][j].seatoff;
				profile[i - 1][j].seat = profile[i - 1][j].seatoff;
			}
		}
	}
}

// private멤버 title반환
string Movie::getTitle() {
	return this->title;
}

// private멤버 time반환
string Movie::getTime() {
	return this->time;
}

// private멤버 theater반환
string Movie::getTheater() {
	return this->theater;
}
