#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Reserve.h"
#include "Movie.h"
#include "Profile.h"
#include "List.h"
#include "Statistics.h"
using namespace std;

//기본생성자
Reserve::Reserve() {
	mp = &movie[0];
	char a = ' ';
}

// movie객체 설정
void Reserve::SetMovieList() {
	movie[0].setMovie("라이온킹", "09:00", "A관"); //영화제목, 사영시간, 상영관 입력
	movie[0].makeSeat();
	movie[1].setMovie("라이온킹", "15:00", "A관");
	movie[1].makeSeat();
	movie[2].setMovie("킹콩", "09:00", "B관");
	movie[2].makeSeat();
	movie[3].setMovie("킹콩", "15:00", "B관");
	movie[3].makeSeat();
	movie[4].setMovie("살아있다", "09:00", "C관");
	movie[4].makeSeat();
	movie[5].setMovie("살아있다", "15:00", "C관");
	movie[5].makeSeat();
}

// 영화 선택화면 출력
void Reserve::ShowTimetable() {
	cout << "1. 라이온킹 09:00 A관" << endl;
	cout << "2. 라이온킹 15:00 A관" << endl;
	cout << "3. 킹콩 09:00 B관" << endl;
	cout << "4. 킹콩 15:00 B관" << endl;
	cout << "5. 살아있다 09:00 C관" << endl;
	cout << "6. 살아있다 15:00 C관" << endl << endl;
}

// 특정 영화 선택 후 포인터 반환
Movie* Reserve::SelectMovie() {
	int num;
	cout << "<보고싶은 영화 및 시간을 선택하세요>" << endl << endl;
	ShowTimetable();
	cin >> num;
	switch (num) {
	default:
		cout << "영화의 번호를 선택하세요" << endl;
		return SelectMovie();
	case(1):
		return &movie[0];
		break;
	case(2):
		return &movie[1];
		break;
	case(3):
		return &movie[2];
		break;
	case(4):
		return &movie[3];
		break;
	case(5):
		return &movie[4];
		break;
	case(6):
		return &movie[5];
		break;
	}
}

// 시작화면(기능선택) 
void Reserve::start(int& choice) {
	cout << "<하고싶은 기능을 선택하시오>" << endl;
	cout << "1. 영화 예매	2. 예매 취소	3. 예매 현황 조회	(4 or 나머지). 끝내기" << endl;
	cin >> choice;
	cout << endl;
}

// 영화 예매
void Reserve::case1() {
	cout << endl;
	mp = SelectMovie();					//특정 movie 객체 선택
	mp->showMovie();					//선택한 movie객체 보여주기
	mp->showSeat();
	Profile& refp = mp->selectSeat();	// refp에 선택한자리의 프로필 객체의 참조를 받음
	refp.showProfile();					//프로필 객체 참조 잘됬는지 확인x
	cout << "<10000원 결제하시겠습니까 Y/N>    (포인트 10p적립)" << endl;
	cin >> a;
	a = toupper(a);
	if (a == 'Y') {
		addList(refp, mp); // 리스트 작성
		mp->swapSeat();
		cout << "<결제가 완료되었습니다>" << endl;
		refp.account.withdraw(10000);	//10000원 결제, 포인트 10 적립
		refp.account.showAccount();		//잔액확인
		cout << endl;
	}
}

// 예매 취소
void Reserve::case2() {
	cout << endl;
	int i = 0, j = 0, m = 0;
	string phone = "000";
	cout << "<전화번호를 입력해 주세요>" << endl << "전화번호 : ";
	cin >> phone;
	for (int k = 0; k < 6; k++) {									// 전화번호 조회 및 예약한 자리 확인
		for (int a = 1; a < 10; a++) {
			for (int b = 1; b < 10; b++) {
				if (movie[k].profile[a][b].getPhoneNum() == phone) {
					m = k;
					i = a;
					j = b;
				}
			}
		}
	}
	if (i == 0) {
		cout << "<예매 내역이 없습니다>" << endl << endl;			//  일치하는 전화번호가 없는 경우
		return;
	}
	mp = &movie[m];
	Profile& refp = mp->getProfile(i, j);
	cout << endl << "<예매정보 확인>" << endl;
	refp.showProfile();
	mp->showMovie();
	refp.account.showAccount();
	cout << "<환불을 진행하시겠습니까? Y/N 10000원, 포인트 10p가 차감됩니다>" << endl;
	cin >> a;
	a = toupper(a);
	if (a == 'Y') {
		deleteList(refp, mp);										// 리스트에서 제거
		mp->getProfile(i, j).seat = mp->getProfile(i, j).seaton;	// 자리 상태 변경
		mp->getProfile(i, j + 1).seat = mp->getProfile(i, j + 1).seaton;
		mp->getProfile(i, j - 1).seat = mp->getProfile(i, j - 1).seaton;
		mp->getProfile(i + 1, j).seat = mp->getProfile(i + 1, j).seaton;
		mp->getProfile(i - 1, j).seat = mp->getProfile(i - 1, j).seaton;
		mp->checkSeat();											// 중복된 자리 수정
		mp->getProfile(i, j).cancle();								// 개인정보 삭제
		refp.account.deposit(10000);								// 환불, 포인트회수
		cout << "<환불이 완료되었습니다>" << endl;
		refp.account.showAccount();									// 잔액 출력
	}
	cout << endl;
}

// 이전 결제내역 벡터에 입력
void Reserve::previousList() {
	ifstream fin("payment.txt");
	if (!fin) {
		cout << "결제내역 파일을 찾지 못했습니다." << endl;
	}
	while (!fin.eof()) {
		fin >> l.name;
		fin >> l.phoneNum;
		fin >> l.sex;
		fin >> l.seat;
		fin >> l.Theater;
		fin >> l.time;
		fin >> l.title;
		list.push_back(l);
	}
}

// 결제 시 리스트에 추가
void Reserve::addList(Profile& refp, Movie* mp) {
	l.sex = refp.getSex();
	l.name = refp.getName();
	l.phoneNum = refp.getPhoneNum();
	l.Theater = mp->getTheater();
	l.seat = refp.seaton;
	l.time = mp->getTime();
	l.title = mp->getTitle();
	list.push_back(l);
	ofstream fout("payment.txt");
	if (!fout) { cout << "결제내역 파일을 찾지 못했습니다." << endl; }
	for (it = list.begin(); it != list.end(); it++) {
		fout << it->name << ' ' << it->phoneNum << ' ' << it->sex << ' ' << it->seat << ' ' << it->Theater << ' ' << it->time << ' ' << it->title << endl;
	}
}

// 환불 시 리스트 제거
void Reserve::deleteList(Profile& refp, Movie* mp) {
	for (it = list.end() - 1; it != list.begin(); it--) {	// 파일 마지막에 엔터가 들어있기 때문에 end()-1로 설정
		if (it->phoneNum == refp.getPhoneNum()) {
			list.erase(it);
			break;
		}
	}
	ofstream fout("payment.txt");
	if (!fout) { cout << "결제내역 파일을 찾지 못했습니다." << endl; }
	for (it = list.begin(); it != list.end(); it++) {
		fout << it->name << ' ' << it->phoneNum << ' ' << it->sex << ' ' << it->seat << ' ' << it->Theater << ' ' << it->time << ' ' << it->title << endl;
	}
}

// 통계 선택
void Reserve::startStatistic(int& choice2) {
	cout << endl;
	cout << "<보고싶은 자료를 선택하세요>" << endl;
	cout << "1. 가장 많이 예매된 좌석 Top3     2. 영화별 가장 많이 예매된 좌석 Top3     3. 남녀별 가장 많이 예매한 좌석 Top3     4. 좌석별 세부 정보 출력" << endl;
	cin >> choice2;
}

// 좌석별 예매 횟수top3 출력
void Reserve::showTop3ForSeat() {
	cout << endl;
	statistic.makeCount(&movie[0], list, list.size());
	cout << "<좌석별 예매 횟수>";
	statistic.showCount();
	statistic.top3(&movie[0]);
	cout << endl;
}

// 영화별 예매 횟수 top3 출력
void Reserve::showTop3ForTitle() {
	cout << endl;
	cout << "<라이온킹 Top3>" << endl;
	statistic.makeCountForLionKing(&movie[0], list, list.size());
	statistic.top3(&movie[0]);
	cout << endl << "<킹콩 Top3>" << endl;
	statistic.makeCountForKingKong(&movie[0], list, list.size());
	statistic.top3(&movie[0]);
	cout << endl << "<살아있다 Top3>" << endl;
	statistic.makeCountForAlive(&movie[0], list, list.size());
	statistic.top3(&movie[0]);
	cout << endl;
}

// 남녀별 예매 횟수 top3 출력
void Reserve::showTop3ForSex() {
	cout << endl;
	cout << "<남성 선호 좌석 Top3>" << endl;
	statistic.makeCountForM(&movie[0], list, list.size());
	statistic.top3(&movie[0]);
	cout << endl << "<여성 선호 좌석 Top3>" << endl;
	statistic.makeCountForW(&movie[0], list, list.size());
	statistic.top3(&movie[0]);
	cout << endl;
}

// 좌석별 세부정보 출력
void Reserve::showStatisticForSeat() {
	cout << endl;
	cout << "<원하시는 좌석을 선택해 주세요>" << endl << endl;
	cout << "\t\t  스크린" << endl;
	cout << "------------------------------------------------" << endl;
	for (int i = 1; i < 10; i++) { //A~I까지
		cout << "|";
		for (int j = 1; j < 10; j++) { //1~9까지
			cout << " " << movie[0].profile[i][j].seaton << " |";
		}cout << endl;
	}cout << endl;
	cout << "------------------------------------------------" << endl;
	string select;
	cin >> select;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (select == movie[0].profile[i][j].seaton) {
				cout << '<' << select << "의 영화별 예매 횟수>" << endl;
				statistic.makeCountForLionKing(&movie[0], list, list.size());
				cout << "라이온킹 : " << statistic.getCount(i, j) << "회" << endl;
				statistic.makeCountForKingKong(&movie[0], list, list.size());
				cout << "킹콩 : " << statistic.getCount(i, j) << "회" << endl;
				statistic.makeCountForAlive(&movie[0], list, list.size());
				cout << "살아있다 : " << statistic.getCount(i, j) << "회" << endl << endl;
				cout << '<' << select << "의 남녀 예매 비율>" << endl;
				statistic.makeCountForM(&movie[0], list, list.size());
				cout << statistic.getCount(i, j) << " : ";
				statistic.makeCountForW(&movie[0], list, list.size());
				cout << statistic.getCount(i, j) << endl << endl;
				cout << '<' << select << "의 상영대별 예매 횟수>" << endl;
				statistic.makeCountForTime09(&movie[0], list, list.size());
				cout << "09:00 시 : " << statistic.getCount(i, j) << endl;
				statistic.makeCountForTime15(&movie[0], list, list.size());
				cout << "15:00 시 : " << statistic.getCount(i, j) << endl;
				cout << endl;
			}
		}
	}
}


