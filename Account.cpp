#include "Account.h"
using namespace std;

// �⺻ ������
Account::Account() {
	this->balance = 200000;
	this->point = 0;
}

// �ܾ� ���
void Account::showAccount() {
	cout << "�ܾ� : " << balance << " ����Ʈ : " << point << 'p' << endl;
}

// ���� ��
void Account::deposit(int pay) {
	this->balance += pay;
	point -= pay / 1000;
}

// ȯ�� ��
void Account::withdraw(int pay) {
	this->balance -= pay;
	this->point += pay / 1000;
}

