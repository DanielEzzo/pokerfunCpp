#pragma once
/*
��������� ������
*/
int** generadeCartSet();
/*
����������� ������
*/
void showCards(int** set);
/*
�������
*/
void shuffle(int** set);
/*
�������� �������(���. �� 5)
*/
string* creatPlayers(int count);
/*
����������� ���� � �������
*/
void showPlayers(string*& names, int count, int*& money);
/*
�������� �����
*/
int* creatCash(int count, int countMoney);