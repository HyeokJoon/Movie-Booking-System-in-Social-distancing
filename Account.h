#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
	int balance;	// 잔액을 20만원씩 있다고 가정함
	int point;		// 1000원당 1포인트
public:
	Account();
	virtual ~Account() {}
	void withdraw(int pay);
	void deposit(int pay);
	void showAccount();
};

#endif