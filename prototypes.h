#pragma once
/*
генерация колоды
*/
int** generadeCartSet();
/*
отоброжение колоды
*/
void showCards(int** set);
/*
тасовка
*/
void shuffle(int** set);
/*
создание игроков(огр. до 5)
*/
string* creatPlayers(int count);
/*
отображение инфы о игроках
*/
void showPlayers(string*& names, int count, int*& money);
/*
создание денег
*/
int* creatCash(int count, int countMoney);