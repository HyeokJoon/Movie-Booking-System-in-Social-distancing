#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
	int balance;	// �ܾ��� 20������ �ִٰ� ������
	int point;		// 1000���� 1����Ʈ
public:
	Account();
	virtual ~Account() {}
	void withdraw(int pay);
	void deposit(int pay);
	void showAccount();
};

#endif