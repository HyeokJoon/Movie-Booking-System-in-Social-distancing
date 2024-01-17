#include <iostream>
#include <string>
#include "Movie.h"
#include "Profile.h"
using namespace std;

// �⺻������
Movie::Movie() {
	title = "�̸�";
	time = "�ð�";
	theater = "�󿵰�";
}

// progile ���� ��ȯ
Profile& Movie::getProfile(int a, int b) {
	return profile[a][b];
}

//Movie ���� �Է�(��ȭ����, �󿵽ð�, �󿵰�)
void Movie::setMovie(string n, string t, string p) {
	this->title = n;
	this->time = t;
	this->theater = p;
}

// ������ ��ȭ�� Ȯ���� �� ���
void Movie::showMovie() {
	cout << "��ȭ : " << this->title << ", �ð� : " << this->time << ", �󿵰� : " << this->theater << endl << endl;
}

// �¼�ǥ ����� (�¼� �̸� �Է� -> profile �� seat, seaton)
void Movie::makeSeat() {
	string a = "@";							// ���̴ºκ��� A~I����
	for (int i = 0; i < 11; i++) {
		string b = "0";						// ���̴ºκ��� 1~9����
		for (int j = 0; j < 11; j++) {
			profile[i][j].seaton = a + b;
			profile[i][j].seat = profile[i][j].seaton;
			b[0]++;
		}a[0]++;
	}
}

// �¼�ǥ �����ֱ� (profile.seat)
void Movie::showSeat() {
	cout << "<���Ͻô� �¼��� ������ �ּ���>" << endl << endl;
	cout << "\t\t  ��ũ��" << endl;
	cout << "------------------------------------------------" << endl;
	for (int i = 1; i < 10; i++) {		//A~I����
		cout << "|";
		for (int j = 1; j < 10; j++) {	//1~9����
			cout << " " << profile[i][j].seat << " |";
		}cout << endl;
	}cout << endl;
	cout << "------------------------------------------------" << endl;
}

// �¼����� ���� �� ������ �ڸ��� �����ʰ�ü�� ���� ����
Profile& Movie::selectSeat() {
	string select;
	cin >> select;
	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			// ���� ������ �ڸ�(profile.seat) && ���� �����ϴ��ڸ�(profile.seaton) -> �����ڸ� ���� ����
			if (select == profile[i][j].seat && select == profile[i][j].seaton) {
				profile[i][j].Login();			// ������ �Է� (�̸�, ����, ��ȭ��ȣ)
				return this->profile[i][j];		// �������� ������ ���� ����
			}
		}
	}
	// ���� ã�ƺ��� ���°��
	cout << "���ڸ��� �������ּ���(�빮�ڷ� �Է����ּ���) : ";
	return selectSeat();
}

// �������� ���� �������ڸ� �� �Ÿ��α� �¼� ���º���
void Movie::swapSeat() {
	profile[i][j].seat = profile[i][j].seatbook;
	profile[i][j + 1].seat = profile[i][j + 1].seatoff;
	profile[i][j - 1].seat = profile[i][j - 1].seatoff;
	profile[i + 1][j].seat = profile[i + 1][j].seatoff;
	profile[i - 1][j].seat = profile[i - 1][j].seatoff;
}

// ������� �� �ڸ����� �缳��
void Movie::checkSeat() {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (profile[i][j].seat == "||") {
				profile[i][j + 1].seat = profile[i][j + 1].seatoff;
				profile[i][j - 1].seat = profile[i][j - 1].seatoff;
				profile[i + 1][j].seat = profile[i + 1][j].seatoff;
				profile[i - 1][j].seat = profile[i - 1][j].seatoff;
			}
		}
	}
}

// private��� title��ȯ
string Movie::getTitle() {
	return this->title;
}

// private��� time��ȯ
string Movie::getTime() {
	return this->time;
}

// private��� theater��ȯ
string Movie::getTheater() {
	return this->theater;
}
