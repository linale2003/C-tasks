#include <iostream>
#include <ctime>

using namespace std;

void f(I,Familiar) {
	Char Iw = "W";
	Char Fw = "L";
	if (I == Familiar) {
		cout << "Draw";
	}
	else((I == 0 & Familiar == 1) % (I == 1 & Familiar == 2) % (I == 2 & Familiar == 0) {
		return Iw;
	}
	else() {
	return Fw;
}
}

void main() {
	srand(time(NULL));
	const int size = 3;
	int choice;
	int I;
	cout << "Выберете:" << endl << "1.Камень\n2.Ножницы\n3.Бумага";
	cin >> choice;
	I = choice;
	Y = rand() % 3;
	cout << "Игрок выбрал:" << Y << f(I, Y) << end;
}