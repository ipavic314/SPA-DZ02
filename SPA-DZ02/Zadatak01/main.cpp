/* U prilogu je aplikacija kakvu trebate napraviti, a sastoji se od sljedeæeg: prilikom pokretanja aplikacije korisnik unosi redak i

stupac poèetne toèke A i redak i stupac krajnje toèke B (broj retka ide od 1 do 20, a broj stupca od 1 do 40). Nakon toga,

aplikacija treba osmisliti put od toèke A do toèke B i svakih 100 milisekundi iscrtati gdje se trenutno nalazimo. Toèka A i toèka

B se mogu nalaziti na bilo kojem dopuštenom mjestu (isprobajte kako radi aplikacija u prilogu s, primjerice, A = 1, 1 i B = 20,

40, te kako radi s A = 20, 20 i B = 10, 10).*/

#include <iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;

struct point {
	int row;
	int column;
};

void initialize(point& startPoint, point& endPoint) {

	int redak;
	int stupac;

	cout << "Unesi redak pocetne tocke: ";
	cin >> redak;
	if (!(redak > 0 && redak <= 20)) {
		cout << "Greska." << endl;
		return;
	}
	startPoint.row = redak;

	cout << "Unesi stupac pocetne tocke: ";
	cin >> stupac;
	if (!(stupac > 0 && stupac <= 40)) {
		cout << "Greska." << endl;
		return;
	}
	startPoint.column = stupac;

	cout << "Unesi redak krajnje tocke: ";
	cin >> redak;
	if (!(redak > 0 && redak <= 20)) {
		cout << "Greska." << endl;
		return;
	}
	endPoint.row = redak;

	cout << "Unesi stupac krajnje tocke: ";
	cin >> stupac;
	if (!(stupac > 0 && stupac <= 40)) {
		cout << "Greska." << endl;
		return;
	}

	endPoint.column = stupac;

}

void moveCharacter(point& character, point endPoint, bool sameRow, bool sameColumn) {

	if (!sameRow) {
		if (character.row < endPoint.row)
			character.row++;

		else if (character.row > endPoint.row)
			character.row--;
		return;
	}

	if (!sameColumn) {
		if (character.column < endPoint.column)
			character.column++;

		else if (character.column > endPoint.column)
			character.column--;
		return;
	}
}

bool gameRunning(point& startPoint, point& endPoint, point& character) {

	bool sameRow = false;
	bool sameColumn = false;

	if (character.row == endPoint.row) {
		sameRow = true;
	}
	if (character.column == endPoint.column) {
		sameColumn = true;
	}

	if (sameRow && sameColumn)
		return false;

	else
		moveCharacter(character, endPoint, sameRow, sameColumn);

	return true;
}

void drawGrid(point startPoint, point endPoint, point character) {
	for (int x = 1; x <= 20; x++) {
		for (int y = 1; y <= 40; y++) {

			if (x == startPoint.row && y == startPoint.column)
				cout << "A";

			else if (x == endPoint.row && y == endPoint.column)
				cout << "B";

			else if (x == character.row && y == character.column)
				cout << "X";

			else
				cout << "-";
		}

		cout << endl;
	}
}
int main() {

	point startPoint;
	point endPoint;

	initialize(startPoint, endPoint);
	point character = startPoint;

	drawGrid(startPoint, endPoint, character);

	while (gameRunning(startPoint, endPoint, character)) {

		system("cls");
		drawGrid(startPoint, endPoint, character);
		Sleep(100);

	}


	return 0;
}