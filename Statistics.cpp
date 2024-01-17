#include "Statistics.h"
#include <iostream>
#include <string>
#include <vector>
#include "Movie.h"
#include "List.h"
#include <algorithm>
using namespace std;

// �⺻ ������
Statistics::Statistics() {
	count[11][11] = { 0 };
}

// Ư�� �ڸ� ����Ƚ���� ��ȯ
int Statistics::getCount(int i, int j) {
	return count[i][j];
}

// ��ü �¼��� ����Ƚ���� ����ϴ� �Լ�
void Statistics::makeCount(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0���� �ʱ�ȭ
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list�� seat���� count�� ����
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// ���� �¼��� ����Ƚ���� ����ϴ� �Լ�
void Statistics::makeCountForM(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0���� �ʱ�ȭ
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list�� ������ ������ �ڸ����� count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].sex == "����" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// ���� �¼��� ����Ƚ���� ����ϴ� �Լ�
void Statistics::makeCountForW(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0���� �ʱ�ȭ
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list�� ������ ������ �ڸ����� count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].sex == "����" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// ���̿�ŷ �¼��� ����Ƚ���� ����ϴ� �Լ�
void Statistics::makeCountForLionKing(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0���� �ʱ�ȭ
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list�� ���̿�ŷ ������ �ڸ����� count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].title == "���̿�ŷ" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// ŷ�� �¼��� ����Ƚ���� ����ϴ� �Լ�
void Statistics::makeCountForKingKong(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0���� �ʱ�ȭ
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list�� ŷ�� ������ �ڸ����� count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].title == "ŷ��" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// ����ִ� �¼��� ����Ƚ���� ����ϴ� �Լ�
void Statistics::makeCountForAlive(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0���� �ʱ�ȭ
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list�� ����ִ� ������ �ڸ����� count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].title == "����ִ�" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// 09�� �¼��� ����Ƚ���� ����ϴ� �Լ�
void Statistics::makeCountForTime09(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0���� �ʱ�ȭ
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list�� 09�ÿ� ������ �ڸ����� count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].time == "09:00" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// 15�� �¼��� ����Ƚ���� ����ϴ� �Լ�
void Statistics::makeCountForTime15(Movie* m, vector<List>& list, int size) {
	for (int i = 1; i < 10; i++) {			// 0���� �ʱ�ȭ
		for (int j = 1; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {	// list�� 15�ÿ� ������ �ڸ����� count++;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (list[i].time == "15:00" && list[i].seat == m[0].profile[j][k].seaton) {
					count[j][k]++;
				}
			}
		}
	}
}

// �¼��� ����Ƚ���� �����ִ� �Լ�
void Statistics::showCount() {
	cout << endl << endl;
	cout << "\t\t  ��ũ��" << endl;
	cout << "------------------------------------------------" << endl;
	for (int i = 1; i < 10; i++) { //A~I����
		cout << "|";
		for (int j = 1; j < 10; j++) { //1~9����
			cout << " " << this->count[i][j] << " |";
		}cout << endl;
	}cout << endl;
	cout << "------------------------------------------------" << endl;
}

// Top3�� �����ִ� �Լ� (������ ��� �ڿ������� ���)
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