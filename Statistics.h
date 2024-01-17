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
	vector <pair<int, string>> v;	//top3�� ���ϱ� ���� <����Ƚ��, �ڸ��̸�> ���� ����
public:
	int count[11][11];				// �� �ڸ� Ƚ���� ����� ���� -> ������ ����Ƚ���� ��
	Statistics();
	virtual ~Statistics() {};
	int getCount(int i, int j);
	void showCount();													// �¼��� ����Ƚ���� �����ִ� �Լ�
	void makeCount(Movie* m, vector<List>& list, int size);				// ��ü �¼��� ����Ƚ���� ����ϴ� �Լ�
	void makeCountForM(Movie* m, vector<List>& list, int size);			// ���� �¼��� ����Ƚ���� ����ϴ� �Լ�
	void makeCountForW(Movie* m, vector<List>& list, int size);			// ���� �¼��� ����Ƚ���� ����ϴ� �Լ�
	void makeCountForLionKing(Movie* m, vector<List>& list, int size);	// ���̿�ŷ �¼��� ����Ƚ���� ����ϴ� �Լ�
	void makeCountForKingKong(Movie* m, vector<List>& list, int size);	// ŷ�� �¼��� ����Ƚ���� ����ϴ� �Լ�
	void makeCountForAlive(Movie* m, vector<List>& list, int size);		// ����ִ� �¼��� ����Ƚ���� ����ϴ� �Լ�
	void makeCountForTime09(Movie* m, vector<List>& list, int size);	// 09�� �¼��� ����Ƚ���� ����ϴ� �Լ�
	void makeCountForTime15(Movie* m, vector<List>& list, int size);	// 15�� �¼��� ����Ƚ���� ����ϴ� �Լ�
	void top3(Movie* m);												// Top3�� �����ִ� �Լ� (������ ��� �ڿ������� ���)
};

#endif