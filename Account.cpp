#include "Account.h"
using namespace std;

// 기본 생성자
Account::Account() {
	this->balance = 200000;
	this->point = 0;
}

// 잔액 출력
void Account::showAccount() {
	cout << "잔액 : " << balance << " 포인트 : " << point << 'p' << endl;
}

// 결제 시
void Account::deposit(int pay) {
	this->balance += pay;
	point -= pay / 1000;
}

// 환불 시
void Account::withdraw(int pay) {
	this->balance -= pay;
	this->point += pay / 1000;
}

