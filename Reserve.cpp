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

//�⺻������
Reserve::Reserve() {
	mp = &movie[0];
	char a = ' ';
}

// movie��ü ����
void Reserve::SetMovieList() {
	movie[0].setMovie("���̿�ŷ", "09:00", "A��"); //��ȭ����, �翵�ð�, �󿵰� �Է�
	movie[0].makeSeat();
	movie[1].setMovie("���̿�ŷ", "15:00", "A��");
	movie[1].makeSeat();
	movie[2].setMovie("ŷ��", "09:00", "B��");
	movie[2].makeSeat();
	movie[3].setMovie("ŷ��", "15:00", "B��");
	movie[3].makeSeat();
	movie[4].setMovie("����ִ�", "09:00", "C��");
	movie[4].makeSeat();
	movie[5].setMovie("����ִ�", "15:00", "C��");
	movie[5].makeSeat();
}

// ��ȭ ����ȭ�� ���
void Reserve::ShowTimetable() {
	cout << "1. ���̿�ŷ 09:00 A��" << endl;
	cout << "2. ���̿�ŷ 15:00 A��" << endl;
	cout << "3. ŷ�� 09:00 B��" << endl;
	cout << "4. ŷ�� 15:00 B��" << endl;
	cout << "5. ����ִ� 09:00 C��" << endl;
	cout << "6. ����ִ� 15:00 C��" << endl << endl;
}

// Ư�� ��ȭ ���� �� ������ ��ȯ
Movie* Reserve::SelectMovie() {
	int num;
	cout << "<������� ��ȭ �� �ð��� �����ϼ���>" << endl << endl;
	ShowTimetable();
	cin >> num;
	switch (num) {
	default:
		cout << "��ȭ�� ��ȣ�� �����ϼ���" << endl;
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

// ����ȭ��(��ɼ���) 
void Reserve::start(int& choice) {
	cout << "<�ϰ���� ����� �����Ͻÿ�>" << endl;
	cout << "1. ��ȭ ����	2. ���� ���	3. ���� ��Ȳ ��ȸ	(4 or ������). ������" << endl;
	cin >> choice;
	cout << endl;
}

// ��ȭ ����
void Reserve::case1() {
	cout << endl;
	mp = SelectMovie();					//Ư�� movie ��ü ����
	mp->showMovie();					//������ movie��ü �����ֱ�
	mp->showSeat();
	Profile& refp = mp->selectSeat();	// refp�� �������ڸ��� ������ ��ü�� ������ ����
	refp.showProfile();					//������ ��ü ���� �߉���� Ȯ��x
	cout << "<10000�� �����Ͻðڽ��ϱ� Y/N>    (����Ʈ 10p����)" << endl;
	cin >> a;
	a = toupper(a);
	if (a == 'Y') {
		addList(refp, mp); // ����Ʈ �ۼ�
		mp->swapSeat();
		cout << "<������ �Ϸ�Ǿ����ϴ�>" << endl;
		refp.account.withdraw(10000);	//10000�� ����, ����Ʈ 10 ����
		refp.account.showAccount();		//�ܾ�Ȯ��
		cout << endl;
	}
}

// ���� ���
void Reserve::case2() {
	cout << endl;
	int i = 0, j = 0, m = 0;
	string phone = "000";
	cout << "<��ȭ��ȣ�� �Է��� �ּ���>" << endl << "��ȭ��ȣ : ";
	cin >> phone;
	for (int k = 0; k < 6; k++) {									// ��ȭ��ȣ ��ȸ �� ������ �ڸ� Ȯ��
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
		cout << "<���� ������ �����ϴ�>" << endl << endl;			//  ��ġ�ϴ� ��ȭ��ȣ�� ���� ���
		return;
	}
	mp = &movie[m];
	Profile& refp = mp->getProfile(i, j);
	cout << endl << "<�������� Ȯ��>" << endl;
	refp.showProfile();
	mp->showMovie();
	refp.account.showAccount();
	cout << "<ȯ���� �����Ͻðڽ��ϱ�? Y/N 10000��, ����Ʈ 10p�� �����˴ϴ�>" << endl;
	cin >> a;
	a = toupper(a);
	if (a == 'Y') {
		deleteList(refp, mp);										// ����Ʈ���� ����
		mp->getProfile(i, j).seat = mp->getProfile(i, j).seaton;	// �ڸ� ���� ����
		mp->getProfile(i, j + 1).seat = mp->getProfile(i, j + 1).seaton;
		mp->getProfile(i, j - 1).seat = mp->getProfile(i, j - 1).seaton;
		mp->getProfile(i + 1, j).seat = mp->getProfile(i + 1, j).seaton;
		mp->getProfile(i - 1, j).seat = mp->getProfile(i - 1, j).seaton;
		mp->checkSeat();											// �ߺ��� �ڸ� ����
		mp->getProfile(i, j).cancle();								// �������� ����
		refp.account.deposit(10000);								// ȯ��, ����Ʈȸ��
		cout << "<ȯ���� �Ϸ�Ǿ����ϴ�>" << endl;
		refp.account.showAccount();									// �ܾ� ���
	}
	cout << endl;
}

// ���� �������� ���Ϳ� �Է�
void Reserve::previousList() {
	ifstream fin("payment.txt");
	if (!fin) {
		cout << "�������� ������ ã�� ���߽��ϴ�." << endl;
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

// ���� �� ����Ʈ�� �߰�
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
	if (!fout) { cout << "�������� ������ ã�� ���߽��ϴ�." << endl; }
	for (it = list.begin(); it != list.end(); it++) {
		fout << it->name << ' ' << it->phoneNum << ' ' << it->sex << ' ' << it->seat << ' ' << it->Theater << ' ' << it->time << ' ' << it->title << endl;
	}
}

// ȯ�� �� ����Ʈ ����
void Reserve::deleteList(Profile& refp, Movie* mp) {
	for (it = list.end() - 1; it != list.begin(); it--) {	// ���� �������� ���Ͱ� ����ֱ� ������ end()-1�� ����
		if (it->phoneNum == refp.getPhoneNum()) {
			list.erase(it);
			break;
		}
	}
	ofstream fout("payment.txt");
	if (!fout) { cout << "�������� ������ ã�� ���߽��ϴ�." << endl; }
	for (it = list.begin(); it != list.end(); it++) {
		fout << it->name << ' ' << it->phoneNum << ' ' << it->sex << ' ' << it->seat << ' ' << it->Theater << ' ' << it->time << ' ' << it->title << endl;
	}
}

// ��� ����
void Reserve::startStatistic(int& choice2) {
	cout << endl;
	cout << "<������� �ڷḦ �����ϼ���>" << endl;
	cout << "1. ���� ���� ���ŵ� �¼� Top3     2. ��ȭ�� ���� ���� ���ŵ� �¼� Top3     3. ���ະ ���� ���� ������ �¼� Top3     4. �¼��� ���� ���� ���" << endl;
	cin >> choice2;
}

// �¼��� ���� Ƚ��top3 ���
void Reserve::showTop3ForSeat() {
	cout << endl;
	statistic.makeCount(&movie[0], list, list.size());
	cout << "<�¼��� ���� Ƚ��>";
	statistic.showCount();
	statistic.top3(&movie[0]);
	cout << endl;
}

// ��ȭ�� ���� Ƚ�� top3 ���
void Reserve::showTop3ForTitle() {
	cout << endl;
	cout << "<���̿�ŷ Top3>" << endl;
	statistic.makeCountForLionKing(&movie[0], list, list.size());
	statistic.top3(&movie[0]);
	cout << endl << "<ŷ�� Top3>" << endl;
	statistic.makeCountForKingKong(&movie[0], list, list.size());
	statistic.top3(&movie[0]);
	cout << endl << "<����ִ� Top3>" << endl;
	statistic.makeCountForAlive(&movie[0], list, list.size());
	statistic.top3(&movie[0]);
	cout << endl;
}

// ���ະ ���� Ƚ�� top3 ���
void Reserve::showTop3ForSex() {
	cout << endl;
	cout << "<���� ��ȣ �¼� Top3>" << endl;
	statistic.makeCountForM(&movie[0], list, list.size());
	statistic.top3(&movie[0]);
	cout << endl << "<���� ��ȣ �¼� Top3>" << endl;
	statistic.makeCountForW(&movie[0], list, list.size());
	statistic.top3(&movie[0]);
	cout << endl;
}

// �¼��� �������� ���
void Reserve::showStatisticForSeat() {
	cout << endl;
	cout << "<���Ͻô� �¼��� ������ �ּ���>" << endl << endl;
	cout << "\t\t  ��ũ��" << endl;
	cout << "------------------------------------------------" << endl;
	for (int i = 1; i < 10; i++) { //A~I����
		cout << "|";
		for (int j = 1; j < 10; j++) { //1~9����
			cout << " " << movie[0].profile[i][j].seaton << " |";
		}cout << endl;
	}cout << endl;
	cout << "------------------------------------------------" << endl;
	string select;
	cin >> select;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (select == movie[0].profile[i][j].seaton) {
				cout << '<' << select << "�� ��ȭ�� ���� Ƚ��>" << endl;
				statistic.makeCountForLionKing(&movie[0], list, list.size());
				cout << "���̿�ŷ : " << statistic.getCount(i, j) << "ȸ" << endl;
				statistic.makeCountForKingKong(&movie[0], list, list.size());
				cout << "ŷ�� : " << statistic.getCount(i, j) << "ȸ" << endl;
				statistic.makeCountForAlive(&movie[0], list, list.size());
				cout << "����ִ� : " << statistic.getCount(i, j) << "ȸ" << endl << endl;
				cout << '<' << select << "�� ���� ���� ����>" << endl;
				statistic.makeCountForM(&movie[0], list, list.size());
				cout << statistic.getCount(i, j) << " : ";
				statistic.makeCountForW(&movie[0], list, list.size());
				cout << statistic.getCount(i, j) << endl << endl;
				cout << '<' << select << "�� �󿵴뺰 ���� Ƚ��>" << endl;
				statistic.makeCountForTime09(&movie[0], list, list.size());
				cout << "09:00 �� : " << statistic.getCount(i, j) << endl;
				statistic.makeCountForTime15(&movie[0], list, list.size());
				cout << "15:00 �� : " << statistic.getCount(i, j) << endl;
				cout << endl;
			}
		}
	}
}


