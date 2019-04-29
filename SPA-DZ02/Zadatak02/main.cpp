#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>

using namespace std;

const int HEIGHT = 25;
const int WIDTH = 30;
struct point {
	int height;
	int width;
};
enum playerDirection { LEFT, RIGHT, UP, DOWN };


int randomCoordinate(int number) {
	return rand() % number;
}

void initializeFruit(point& fruit, point& player) {

	int randomX = randomCoordinate(WIDTH);
	int randomY = randomCoordinate(HEIGHT);

	if (!((randomX == player.width && randomY == player.height)) || (randomX == 0 || randomY == 0 || randomX == (HEIGHT - 1) || randomY == (WIDTH - 1))) {
		fruit.height = randomX;
		fruit.width = randomY;
	}
	else
		initializeFruit(fruit, player);

}

void initializeGame(point& player, point& fruit, playerDirection& direction, bool& runningGame) {

	direction = RIGHT;
	runningGame = true;

	player.height = HEIGHT / 2;
	player.width = WIDTH / 2;


	initializeFruit(fruit, player);
}

void drawGrid(point& fruit, point& player) {

	system("cls");

	for (int i = 0; i < WIDTH + 2; i++) {
		cout << "#";
	}
	cout << endl;

	for (int x = 0; x < HEIGHT; x++) {
		for (int y = 0; y < WIDTH; y++) {
			if (y == 0)
				cout << "#";

			if (x == player.height && y == player.width)
				cout << "X";

			else if (x == fruit.height && y == fruit.width)
				cout << "D";

			else
				cout << " ";

			if (y == WIDTH - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < WIDTH + 2; i++)
		cout << "#";

}

void playerInput(playerDirection& direction, bool& runningGame) {

	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			direction = LEFT;
			break;
		case 'd':
			direction = RIGHT;
			break;
		case 'w':
			direction = UP;
			break;
		case 's':
			direction = DOWN;
			break;
		case 'k':
			runningGame = false;
			break;
		default:
			break;
		}
	}
}

void gameLogic(playerDirection& direction, bool& runningGame, point& player, point& fruit) {

	switch (direction) {
	case LEFT:
		player.width--;
		break;
	case RIGHT:
		player.width++;
		break;
	case UP:
		player.height--;
		break;
	case DOWN:
		player.height++;
		break;
	default:
		break;
	}

	if (player.width == 0 || player.width == WIDTH - 1 || player.height == 0 || player.height == HEIGHT - 1)
		runningGame = false;

	if (player.height == fruit.height && player.width == fruit.width)
		initializeFruit(fruit, player);

}

int main() {

	point player;
	point fruit;
	playerDirection direction;
	bool runningGame;
	srand(time(nullptr));
	initializeGame(player, fruit, direction, runningGame);

	while (runningGame) {

		drawGrid(fruit, player);
		playerInput(direction, runningGame);
		gameLogic(direction, runningGame, player, fruit);
		Sleep(100);

	}

	cout << endl << "GAME OVER" << endl;

	return 0;
}