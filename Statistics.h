#ifndef STATISTICS_H
#define STATISTICS_H
#include <iostream>
#include <string>
#include <vector>
#include "Movie.h"
#include "List.h"
#include <algorithm>
using namespace std;

class Statistics {
	vector <pair<int, string>> v;	//top3를 구하기 위해 <예매횟수, 자리이름> 벡터 생성
public:
	int count[11][11];				// 각 자리 횟수를 기록할 변수 -> 벡터의 예매횟수에 들어감
	Statistics();
	virtual ~Statistics() {};
	int getCount(int i, int j);
	void showCount();													// 좌석별 예매횟수를 보여주는 함수
	void makeCount(Movie* m, vector<List>& list, int size);				// 전체 좌석별 예매횟수를 기록하는 함수
	void makeCountForM(Movie* m, vector<List>& list, int size);			// 남성 좌석별 예매횟수를 기록하는 함수
	void makeCountForW(Movie* m, vector<List>& list, int size);			// 여성 좌석별 예매횟수를 기록하는 함수
	void makeCountForLionKing(Movie* m, vector<List>& list, int size);	// 라이온킹 좌석별 예매횟수를 기록하는 함수
	void makeCountForKingKong(Movie* m, vector<List>& list, int size);	// 킹콩 좌석별 예매횟수를 기록하는 함수
	void makeCountForAlive(Movie* m, vector<List>& list, int size);		// 살아있다 좌석별 예매횟수를 기록하는 함수
	void makeCountForTime09(Movie* m, vector<List>& list, int size);	// 09시 좌석별 예매횟수를 기록하는 함수
	void makeCountForTime15(Movie* m, vector<List>& list, int size);	// 15시 좌석별 예매횟수를 기록하는 함수
	void top3(Movie* m);												// Top3를 보여주는 함수 (동일한 경우 뒤에서부터 출력)
};

#endif