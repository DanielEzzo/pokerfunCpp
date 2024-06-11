#include <iostream>

#define random(a,b) a+rand()%(b+1-a)

using namespace std;

//#include "prototypes.h"
//#include "constance1.h"

const string NAMES[] = { "Вася", "Катя", "Ира", "Гоша", "Игорь", "Гога" };
const int COUNT_NAMES = 6;
const int DEFOULT_CASH = 1000;
int** generadeCartSet() {
	// 4♣ 4♠ 4♥ 4♦
	int** set = new int*[52];

	for (int index=0,value = 2; value < 15; value++) {
		for (int suit = 3; suit < 7; suit++) {
			set[index++] = new int[2]{ value,suit };
		}
	}
	return set;
}

void showCards(int** set) {
	int countCards = _msize(set) / sizeof(set[0]);

	for (int i = 0; i < countCards; i++) {

		switch (set[i][0]){
		case(11):
			cout << "В" << char(set[i][1]) << " ";
			break;
		case(12):
			cout << "Д" << char(set[i][1]) << " ";
			break;
		case(13):
			cout << "К" << char(set[i][1]) << " ";
			break;
		case(14):
			cout << "Т" << char(set[i][1]) << " ";
			break;
		default:
			cout << set[i][0] << char(set[i][1]) << " ";
			break;
		}
	}
}

void shuffle(int** set) {
	int size = _msize(set) / sizeof(set[0]);
	for (int i = 0; i < size; i++) {
		swap(set[i], set[random(0, size - 1)]);
	}
}

string* creatPlayers(int count) {
	if (count > 6 || count < 1) {
		cout << "неправильное кол-во игроков";
		return nullptr;
	}
	else {
		string* name = new string[count];
		name[0] = "вы";
		for (int i = 1, flag; i < count; i++) {
			name[i] = NAMES[random(0, COUNT_NAMES - 1)];
			flag = false;
			for (int j = 1; j < i; j++) {
				if (name[i] == name[j]) {
					flag = true;
					break;
				}
			}
			if (flag) i--;
		}

		return name;
	}
}

void transferCarts(int**& outSet, int**& inSet) {
	int countOutSet = _msize(outSet) / sizeof(outSet[0]);
	int countInSet = _msize(inSet) / sizeof(inSet[0]);
	int** outSetBuf = new int* [countOutSet - 1];
	int** inSetBuf = new int* [countInSet + 1];
	for (int i = 0; i < countOutSet - 1; i++) {
		outSetBuf[i] = outSet[i];
	}
	for (int i = 0; i < countInSet; i++) {
		inSetBuf[i] = inSet[i];
	}
	inSetBuf[countInSet] = outSet[countOutSet - 1];
	delete[] inSet;
	delete[] outSet;
	inSet = inSetBuf;
	outSet = outSetBuf;

}

int* creatCash(int countPlayers, int countMoney) {
	int* money = new int[countPlayers];
	for (int i = 0; i < countPlayers; i++) {
		money[i] = countMoney;
	}
	return money;
}

void showPlayers(string*& names, int count, int*& money) {
	for (int i = 0; i < count; i++) {
		cout << endl << names[i] << "\t" << money[i] << "$";
	}

}

void showPlayer(string names, int money, int**& playersSet) {
	cout << names << "\t" << money << "$" << " [";
	showCards(playersSet);
	cout << "]";
}



int main()
{

	srand(time(NULL));
	setlocale(LC_ALL, "");
	int** mainSet = generadeCartSet();
	shuffle(mainSet);
	showCards(mainSet);
	int playersCount = 6;
	string* name = creatPlayers(playersCount);

	int*** playersSets = new int** [playersCount];
	for (int i = 0; i < playersCount; i++) {
		playersSets[i] = new int* [0];
	}

	for (int i = 0; i < playersCount; i++) {
		for (int j = 0; j < 2; j++) {
			transferCarts(mainSet, playersSets[i]);
		}
	}

	int* money = creatCash(playersCount, 1000);


	for (int i = 0; i < playersCount; i++) {
		cout << endl;
		showPlayer(name[i], money[i], playersSets[i]);
	}

	int** tableSet = new int* [0];
	cout << endl << "стол: ";
	for (int i = 0; i < 3; i++) {
		transferCarts(mainSet, tableSet);
	}
	showCards(tableSet);

	int blind = DEFOULT_CASH/20;
	int smallBlind = blind / 2;
	int indexSmallBlind = 0;
	while (true) {

	}
}
