#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class List {			// ���� ������ ������ ��ü (ȯ�� �� delete)
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