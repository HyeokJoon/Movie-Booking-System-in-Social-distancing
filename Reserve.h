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
	List l;								// ���� ������ ������ ��ü ����
	Statistics statistic;				// ���
	vector<List>::iterator it;			// ���� ������
	char a;								// Y/N �����ϴº���
public:
	Movie movie[6];						// movie��ü
	vector<List> list;					// ���系�� ����� ����
	Reserve();
	void SetMovieList();
	void ShowTimetable();
	Movie* SelectMovie();

	void start(int& choice);			// �ʱ�ȭ�� ���
	void case1();						// ��ȭ ����
	void case2();						// ���� ���
	void previousList();				// ���� ���ų��� ���Ϳ� �Է�
	void addList(Profile& refp, Movie* mp); // ���� �� ���Ϳ� �߰�
	void deleteList(Profile& refp, Movie* mp); // ��� �� ���Ϳ� ����
	void startStatistic(int& choice);	// ��� �ʱ�ȭ�� ���
	void showTop3ForSeat();				// �¼��� ���� Ƚ�� Top3
	void showTop3ForTitle();			// ��ȭ�� ���� Ƚ�� Top3
	void showTop3ForSex();				// ���ະ ���� Ƚ�� Top3
	void showStatisticForSeat();		// �ڸ��� ���� ����
};
#endif // !RESERVE_H