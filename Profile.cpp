#include "Profile.h"
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

// �⺻ ������
Profile::Profile() {
	name = "�̸�";
	sex = "����";
	phoneNum = "��ȭ��ȣ";
	seatoff = "  ";
	seatbook = "||";
}

// ���� �� �������� �Է�
void Profile::Login() {
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> this->name;
	int s = 0;
	do {
		cout << "������ �����ϼ��� : 1. ����   2. ����" << endl;
		cin >> s;
		if (s == 1) {
			this->sex = "����";
			break;
		}
		else if (s == 2) {
			this->sex = "����";
			break;
		}
	} while (1);
	cout << "��ȭ��ȣ��(-)��ȣ ���� ���� �ʰ� �Է��ϼ��� : ";
	cin >> this->phoneNum;
	cout << "�α����� �Ϸ�Ǿ����ϴ�" << endl << endl;
}

// ������� �� �������·� �ǵ�����
void Profile::cancle() {
	name = "�̸�";
	sex = "����";
	phoneNum = "��ȭ��ȣ";
}

// �Է��� �������� Ȯ�� �� ���
void Profile::showProfile() {
	cout << "�̸� : " << name << ", ���� : " << sex << ", ��ȭ��ȣ : " << phoneNum << ", �¼� : " << seaton << endl;
}

// private��� phoneNum ��ȯ
string Profile::getPhoneNum() {
	return phoneNum;
}

// private��� name ��ȯ
string Profile::getName() {
	return name;
}

// private��� sex ��ȯ
string Profile::getSex() {
	return sex;
}
