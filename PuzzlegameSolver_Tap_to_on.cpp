//For windows visual studio

//This 'Tap to on' game is simillar with Bright.
//However, they had more functional tiles such as one tap to turn on every bulb in one line, cross, and so on.
//□/■ is turned off/on bulb
//─/━ is turned off/on vertical line bulb, which turning on just two near tile.
//〓/↔ is turned off/on vertical line bulb, which turning on every tile that their line.
//│/┃ is turned off/on horizontal line bulb, which turning on just two near tile.
//∥/↕ is turned off/on horizontal line bulb, which turning on every tile that their line.
//χ/ㅿ is turned off/on cross line bulb, which turning on just four near tile.
//Χ/Δ is turned off/on cross line bulb, which turning on every tile that their cross line.
//◎/● is turned off/on circular bulb, which turning on every tile that their nearby.
//┼/╋ is turned off/on cross line bulb, which turning on every tile that their cross line(vertical and horizontal).
//§ is turned only on bulb, which turning on just like normal bulb but the bulb does not turn off.

#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

bool s = true;
int n = 0, x = 0, y = 0, sum = 0;
int** map = (int**)malloc(sizeof(int*));
typedef struct XY {
	int x;
	int y;
};
XY* ord = (XY*)malloc(sizeof(XY));

void init();
int fn(int sp, int level, int pos[]);
void tap(int n);
int set(int y, int x);
bool jd();
void print();

int main() {
	int i = 0, j = 0, c = 0, d = 0, *pos = (int*)malloc(sizeof(int));
	bool f = false;
	DWORD count = 0;

	cout << " □/■ = 1/2 \n ─/━ = n/N \t │/┃ = i/I \n χ/ㅿ = k/K \t ◎/● = o/O \n 〓/↔ = m/M \t ∥/↕ = l/L \t Χ/Δ = x/X \t ┼/╋ = t/T \n § = Y" << endl;
	cout << "map shape(end : / key) : " << endl;
	for (i = 0; ; i++) {
		map = (int**)realloc(map, sizeof(int) * (i + 1));
		map[i] = (int*)malloc(sizeof(int));
		for (j = 0; ; j++, d = 0) {
			c = _getch();
			if (c == '/') {
				f = true;
				cout << endl;
				break;
			}
			else if (c == 13) {
				cout << endl;
				break;
			}
			else if (c == 8) {
				j -= 2;
				printf("\b \b");
				if (j < -1) {
					i--;
					j = x - 1;
					system("cls");
					cout << " □/■ = 1/2 \n ─/━ = n/N \t │/┃ = i/I \n χ/ㅿ = k/K \t ◎/● = o/O \n 〓/↔ = m/M \t ∥/↕ = l/L \t Χ/Δ = x/X \t ┼/╋ = t/T § = Y" << endl;
					cout << "map shape(end : / key) : " << endl;
					for (int m = 0; m < i + 1; m++) {
						for (int n = 0; n < j + 1; n++) cout << map[m][n];
						if (m != i) cout << endl;
					}
				}
				continue;
			}
			switch (c) {
			case '0': break; case '1': d = 1; break; case '2': d = 2; break;
			case 'N': d = 1; case 'n': d += 11; break;
			case 'I': d = 1; case 'i': d += 21; break;
			case 'M': d = 1; case 'm': d += 31; break;
			case 'L': d = 1; case 'l': d += 41; break;
			case 'K': d = 1; case 'k': d += 51; break;
			case 'X': d = 1; case 'x': d += 61; break;
			case 'O': d = 1; case 'o': d += 71; break;
			case 'T': d = 1; case 't': d += 81; break;
			case 'Y': d = 92; break;
			default: j--; continue;
			}
			map[i][j] = d;
			cout << (char)c;
			map[i] = (int*)realloc(map[i], sizeof(int) * (j + 2));
		}
		x = j;
		if (f) break;
	}
	y = i + 1;

	print();
	init();
	count = GetTickCount();
	for (i = 1; ; i++) {
		pos = (int*)realloc(pos, sizeof(int) * i);
		fn(0, i - 1, pos);
		if (!s) break;
	}
	print();
	cout << "Time taking : " << (double)(GetTickCount() - count) / 1000 << "secs" << endl;
	cout << "Minimum number : " << i << endl << endl;
	for (j = i - 1; j > -1; j--) cout << i - j << " : " << pos[j] << endl;

	for (i = 0; i < y; i++) free(map[i]);
	free(map);
	free(ord);
	free(pos);

	_getch();
	return 0;
}

void init() {
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			if (map[i][j]) {
				ord = (XY*)realloc(ord, sizeof(XY) * (n + 1));
				ord[n].y = i;
				ord[n].x = j;
				n++;
				if (map[i][j] == 1) sum++;
			}
}

int fn(int sp, int level, int pos[]) {
	int i;
	for (i = sp; i < n && s; i++) {
		tap(i);
		if (sum > 5 * (level + 1)) {
			tap(i);
			return 0;
		}
		if (level) fn(i + 1, level - 1, pos);
		else if (jd()) s = false;
		if (s) tap(i);
	}
	pos[level] = i;
	return 0;
}

bool jd() {
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			if (map[i][j] % 2) return false;
	return true;
}

void print() {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++)
			switch (map[i][j]) {
			case 0: cout << "　"; break; case 1: cout << "□"; break; case 2: cout << "■"; break;
			case 11: cout << "─"; break; case 12: cout << "━"; break;
			case 21: cout << "│"; break; case 22: cout << "┃"; break;
			case 31: cout << "〓"; break; case 32: cout << "↔"; break;
			case 41: cout << "∥"; break; case 42: cout << "↕"; break;
			case 51: cout << "χ"; break; case 52: cout << "ㅿ"; break;
			case 61: cout << "Χ"; break; case 62: cout << "Δ"; break;
			case 71: cout << "◎"; break; case 72: cout << "●"; break;
			case 81: cout << "┼"; break; case 82: cout << "╋"; break;
			case 92: cout << "§"; break;
			}
		cout << endl;
	}
	cout << endl;
}

void tap(int a) {
	bool d = 0, n = 0, i = 0, m = 0, l = 0, k = 0, x = 0, o = 0, t = 0, y = 0;
	int Y = ord[a].y, X = ord[a].x, corr = 0;

	switch (map[Y][X]) {
	case 1: case 2: d = 1; break;
	case 11: case 12: n = 1; break;
	case 21: case 22: i = 1; break;
	case 31: case 32: m = 1; break;
	case 41: case 42: l = 1; break;
	case 51: case 52: k = 1; break;
	case 61: case 62: x = 1; break;
	case 71: case 72: o = 1; break;
	case 81: case 82: t = 1; break;
	case 92: y = 1; break;
	}

	map[Y][X] = set(Y, X);
	map[Y][X] - 1 ? sum-- : sum++;
	if (Y > 0)
		if (map[Y - 1][X] && (d || i || l || o || t || y))
			if (l || t)
				for (int i = Y - 1; i > -1; i--) {
					map[i][X] = set(i, X);
					map[i][X] - 1 ? sum-- : sum++;
				}
			else {
				map[Y - 1][X] = set(Y - 1, X);
				map[Y - 1][X] - 1 ? sum-- : sum++;
			}
	if (X > 0)
		if (map[Y][X - 1] && (d || n || m || o || t || y))
			if (m || t) for (int i = X - 1; i > -1; i--) {
				map[Y][i] = set(Y, i);
				map[Y][i] - 1 ? sum-- : sum++;
			}
			else {
				map[Y][X - 1] = set(Y, X - 1);
				map[Y][X - 1] - 1 ? sum-- : sum++;
			}
	if (Y < ::y - 1)
		if (map[Y + 1][X] && (d || i || l || o || t || y))
			if (l || t) for (int i = Y + 1; i < ::y; i++) {
				map[i][X] = set(i, X);
				map[i][X] - 1 ? sum-- : sum++;
			}
			else {
				map[Y + 1][X] = set(Y + 1, X);
				map[Y + 1][X] - 1 ? sum-- : sum++;
			}
	if (X < ::x - 1)
		if (map[Y][X + 1] && (d || n || m || o || t || y))
			if (m || t) for (int i = X + 1; i < ::x; i++) {
				map[Y][i] = set(Y, i);
				map[Y][i] - 1 ? sum-- : sum++;
			}
			else {
				map[Y][X + 1] = set(Y, X + 1);
				map[Y][X + 1] - 1 ? sum-- : sum++;
			}
	if (k || x || o) {
		if (Y > 0 && X > 0)
			if (map[Y - 1][X - 1])
				if (x)
					for (int i = 1; ((Y - i) > -1) && ((X - i) > -1); i++) {
						map[Y - i][X - i] = set(Y - i, X - i);
						map[Y - i][X - i] - 1 ? sum-- : sum++;
					}
				else {
					map[Y - 1][X - 1] = set(Y - 1, X - 1);
					map[Y - 1][X - 1] - 1 ? sum-- : sum++;
				}
		if (Y > 0 && X < ::x - 1)
			if (map[Y - 1][X + 1])
				if (x)
					for (int i = 1; ((Y - i) > -1) && ((X + i) < ::x); i++) {
						map[Y - i][X + i] = set(Y - i, X + i);
						map[Y - i][X + i] - 1 ? sum-- : sum++;
					}
				else {
					map[Y - 1][X + 1] = set(Y - 1, X + 1);
					map[Y - 1][X + 1] - 1 ? sum-- : sum++;
				}
		if (Y < ::y - 1 && X>0)
			if (map[Y + 1][X - 1])
				if (x)
					for (int i = 1; ((Y + i) < ::y) && ((X - i) > -1); i++) {
						map[Y + i][X - i] = set(Y + i, X - i);
						map[Y + i][X - i] - 1 ? sum-- : sum++;
					}
				else {
					map[Y + 1][X - 1] = set(Y + 1, X - 1);
					map[Y + 1][X - 1] - 1 ? sum-- : sum++;
				}
		if (Y < ::y - 1 && X < ::x - 1)
			if (map[Y + 1][X + 1])
				if (x)
					for (int i = 1; ((Y + i) < ::y) && ((X + i) < ::x); i++) {
						map[Y + i][X + i] = set(Y + i, X + i);
						map[Y + i][X + i] - 1 ? sum-- : sum++;
					}
				else {
					map[Y + 1][X + 1] = set(Y + 1, X + 1);
					map[Y + 1][X + 1] - 1 ? sum-- : sum++;
				}
	}
}

int set(int Y, int X) {
	int d = 0, n = 0, i = 0, m = 0, l = 0, k = 0, x = 0, o = 0, t = 0, y = 0;
	switch (map[Y][X]) {
	case 1: case 2: d = 1; break;
	case 11: case 12: n = 10; break;
	case 21: case 22: i = 20; break;
	case 31: case 32: m = 30; break;
	case 41: case 42: l = 40; break;
	case 51: case 52: k = 50; break;
	case 61: case 62: x = 60; break;
	case 71: case 72: o = 70; break;
	case 81: case 82: t = 80; break;
	case 92: y = 90; break;
	}
	if (y) return map[Y][X];
	else return map[Y][X] % 2 + n + i + m + l + k + x + o + t + 1;
}
