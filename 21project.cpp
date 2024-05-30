#include <iostream>
#define random(a,b) a+rand()%(b+a-1)
using namespace std;

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

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");
	int**mainSet = generadeCartSet();
	shuffle(mainSet);
	showCards(mainSet);

}