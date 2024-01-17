// 영화 예매 및 통계확인 프로그램2
// B711049 김혁준
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Movie.h"
#include "Profile.h"
#include "List.h"
#include "Statistics.h"
#include "Reserve.h"
using namespace std;

int main() {
	Reserve* prog = new Reserve;
	prog->SetMovieList();
	prog->previousList();
	do {					// 반복
		int choice = 0;
		prog->start(choice);				// 초기화면(하고싶은 기능 선택)
		switch (choice) {
		case 1: { //----------------------------------------(영화 예매)
			prog->case1();
			break;
		}
		case 2: { // ---------------------------------------(예매 취소)
			prog->case2();
			break;
		}
		case 3: { // ---------------------------------------(통계 조회)
			int choice2;
			prog->startStatistic(choice2);	// 보고싶은 통계 선택
			if (choice2 == 1) {				// 좌석별 예매 횟수
				prog->showTop3ForSeat();
			}
			else if (choice2 == 2) {		// 영화별 예매 횟수 top3
				prog->showTop3ForTitle();
			}
			else if (choice2 == 3) {		// 남녀별 예매 횟수 top3
				prog->showTop3ForSex();
			}
			else if (choice2 == 4) {		// 자리별 예매 현황
				prog->showStatisticForSeat();
			}
			break;
		}
		case 4: {							// 종료
			return 0;
		}
		default:
			return 0;
		}
	} while (1);
	delete prog;
	return 0;
}