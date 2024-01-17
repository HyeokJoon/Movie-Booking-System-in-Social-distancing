#ifndef RESERVE_H
#define RESERVE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Movie.h"
#include "Profile.h"
#include "List.h"
#include "Statistics.h"
using namespace std;

class Reserve {
	Movie* mp;
	List l;								// 결제 내역을 저장할 객체 생성
	Statistics statistic;				// 통계
	vector<List>::iterator it;			// 벡터 포인터
	char a;								// Y/N 선택하는변수
public:
	Movie movie[6];						// movie객체
	vector<List> list;					// 결재내역 기록할 벡터
	Reserve();
	void SetMovieList();
	void ShowTimetable();
	Movie* SelectMovie();

	void start(int& choice);			// 초기화면 출력
	void case1();						// 영화 예매
	void case2();						// 예매 취소
	void previousList();				// 이전 예매내역 벡터에 입력
	void addList(Profile& refp, Movie* mp); // 예매 시 벡터에 추가
	void deleteList(Profile& refp, Movie* mp); // 취소 시 벡터에 제거
	void startStatistic(int& choice);	// 통계 초기화면 출력
	void showTop3ForSeat();				// 좌석별 예매 횟수 Top3
	void showTop3ForTitle();			// 영화별 예매 횟수 Top3
	void showTop3ForSex();				// 남녀별 예매 횟수 Top3
	void showStatisticForSeat();		// 자리별 세부 정보
};
#endif // !RESERVE_H