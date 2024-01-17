#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class List {			// 결제 내역을 저장할 객체 (환불 시 delete)
public:
	string sex;
	string name;
	string phoneNum;
	string Theater;
	string seat;
	string title;
	string time;
	List();
	virtual ~List() {}
};
#endif