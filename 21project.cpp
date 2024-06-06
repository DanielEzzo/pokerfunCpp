#include <iostream>
#define random(a,b) a+rand()%(b+1-a)
using namespace std;

const string NAMES[] = { "Вася", "Катя", "Ира", "Жора", "Игорь", "Гога" };

const int COUNT_NAMES = 6;

int** generadeCartSet() {
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
	if (count > 5 || count < 1) {
		cout << "неправильное кол-во игроков";
		return nullptr;
	}
	else {
		string* name = new string[count];

		for (int i = 0, flag; i < count; i++) {
			name[i] = NAMES[random(0, COUNT_NAMES - 1)];
			flag = false;
			for (int j = 0; j < i; j++) {
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

void showPlayers(string*& names, int count, int*& money) {
	for (int i = 0; i < count; i++) {
		cout << endl << names[i] <<"\t" << money[i] << "$";
	}
}

int* creatCash(int count, int countMoney) {
	int* money = new int[count];
	for (int i = 0; i < count; i++) {
		money[i] = countMoney;
	}
	return money;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");
	int**mainSet = generadeCartSet();
	shuffle(mainSet);
	showCards(mainSet);
	int playersCount = 5;
	string* name = creatPlayers(playersCount);

	int* money = creatCash(5, 1000);
	showPlayers(name, playersCount, money);
}