#include "Statistics.h"
#include <iostream>
#include <string>
#include <vector>
#include "Movie.h"
#include "List.h"
#include <algorithm>
using namespace std;

// 기본 생성자
Statistics::Statistics() {
	count[11][11] = { 0 };
}

// 특정 자리 예매횟수를 반환
int Statistics::getCount(int i, int j) {
	return count[i][j];
}

// 전체 좌석별 예매횟수를 기록하는 함수
void Statistics::makeCount(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0으로 초기화
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list의 seat마다 count를 더함
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// 남성 좌석별 예매횟수를 기록하는 함수
void Statistics::makeCountForM(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0으로 초기화
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list의 남성이 예매한 자리마다 count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].sex == "남성" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// 여성 좌석별 예매횟수를 기록하는 함수
void Statistics::makeCountForW(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0으로 초기화
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list의 여성이 예매한 자리마다 count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].sex == "여성" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// 라이온킹 좌석별 예매횟수를 기록하는 함수
void Statistics::makeCountForLionKing(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0으로 초기화
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list의 라이온킹 예매한 자리마다 count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].title == "라이온킹" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// 킹콩 좌석별 예매횟수를 기록하는 함수
void Statistics::makeCountForKingKong(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0으로 초기화
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list의 킹콩 예매한 자리마다 count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].title == "킹콩" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// 살아있다 좌석별 예매횟수를 기록하는 함수
void Statistics::makeCountForAlive(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0으로 초기화
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list의 살아있다 예매한 자리마다 count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].title == "살아있다" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// 09시 좌석별 예매횟수를 기록하는 함수
void Statistics::makeCountForTime09(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0으로 초기화
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list의 09시에 예매한 자리마다 count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].time == "09:00" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// 15시 좌석별 예매횟수를 기록하는 함수
void Statistics::makeCountForTime15(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0으로 초기화
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list의 15시에 예매한 자리마다 count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].time == "15:00" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// 좌석별 예매횟수를 보여주는 함수
void Statistics::showCount() {
	cout << endl << endl;
	cout << "\t\t  스크린" << endl;
	cout << "------------------------------------------------" << endl;
	for (int i = 1; i < 10; i++) { //A~I까지
		cout << "|";
		for (int j = 1; j < 10; j++) { //1~9까지
			cout << " " << this->count[i][j] << " |";
		}cout << endl;
	}cout << endl;
	cout << "------------------------------------------------" << endl;
}

// Top3를 보여주는 함수 (동일한 경우 뒤에서부터 출력)
void Statistics::top3(Movie* m) {
	v.clear();
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			v.push_back(pair<int, string>(count[i][j], m->profile[i][j].seaton));
		}
	}
	sort(v.begin(), v.end());
	cout << "Top1 = " << v[80].second << endl;
	cout << "Top2 = " << v[79].second << endl;
	cout << "Top3 = " << v[78].second << endl;
}