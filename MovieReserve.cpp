// ��ȭ ���� �� ���Ȯ�� ���α׷�2
// B711049 ������
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
	do {					// �ݺ�
		int choice = 0;
		prog->start(choice);				// �ʱ�ȭ��(�ϰ���� ��� ����)
		switch (choice) {
		case 1: { //----------------------------------------(��ȭ ����)
			prog->case1();
			break;
		}
		case 2: { // ---------------------------------------(���� ���)
			prog->case2();
			break;
		}
		case 3: { // ---------------------------------------(��� ��ȸ)
			int choice2;
			prog->startStatistic(choice2);	// ������� ��� ����
			if (choice2 == 1) {				// �¼��� ���� Ƚ��
				prog->showTop3ForSeat();
			}
			else if (choice2 == 2) {		// ��ȭ�� ���� Ƚ�� top3
				prog->showTop3ForTitle();
			}
			else if (choice2 == 3) {		// ���ະ ���� Ƚ�� top3
				prog->showTop3ForSex();
			}
			else if (choice2 == 4) {		// �ڸ��� ���� ��Ȳ
				prog->showStatisticForSeat();
			}
			break;
		}
		case 4: {							// ����
			return 0;
		}
		default:
			return 0;
		}
	} while (1);
	delete prog;
	return 0;
}