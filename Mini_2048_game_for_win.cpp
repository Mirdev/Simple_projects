// Console version of the 2048 game (winning tile set to 64 for demo purposes)

#include <iostream>
#include <time.h>
#include <conio.h>
#include <iomanip>
using namespace std;

int board[4][4] = { 0, }, c2ob[16] = { 0, }, best=0, score = 0, g_over = 0;

int b_init();
void r_gen();
void print();
bool gojud();
int up();
int down();
int left();
int right();

int main(){
	int i, j;
	char c;
	srand((unsigned int)time(NULL));
	r_gen();
	r_gen();
	while (1){
		print();
		if (g_over>0){
			if (g_over == 1){
				if (score > best){
					best = score;
					cout << score << " is the NEW BEST Score!!" << endl << endl;
				}
				score = 0;
			}
			else if (g_over == 2){
				score = 0;
				cout << "Game Over. No more valid moves." << endl << endl;
			}
			cout << "Do you want to play again? (y/n) ";
			cin >> c;
			if (c == 'y' || c == 'Y'){
				for (i = 0; i < 4; i++){
					for (j = 0; j < 4; j++){
						board[i][j] = 0;
					}
				}
				r_gen();
				r_gen();
				g_over = 0;
				continue;
			}
			else if (c == 'n' || c == 'N')
				exit(1);
			else
				continue;
		}
		else{
			cout << "W : Move Up\n";
			cout << "A : Move Left\n";
			cout << "S : Move Down\n";
			cout << "D : Move Right\n";
			cout << "X : Exit\n";
		}
		c=_getch();
		if (c == 'w' || c == 'W') { up(); }
		else if (c == 'a' || c == 'A') { left(); }
		else if (c == 's' || c == 'S') { down(); }
		else if (c == 'd' || c == 'D') { right(); }
		else if (c == 'x' || c == 'X') { exit(1); }
		else { continue; }
	}
	return 0;
}
int b_init(){
	int i, j, b_cnt = 0;
	for (i = 0; i<4; i++){
		for (j = 0; j<4; j++){
			if (!board[i][j]){
				c2ob[b_cnt] = (i * 10 + j);
				b_cnt++;
			}
		}
	}
	return b_cnt;
}
void r_gen(){
	int r;
	r = rand() % b_init();
	board[c2ob[r] / 10][c2ob[r] % 10] = (rand() % 2 + 1) * 2;
}
void print(){
	int i, j;
	system("cls");
	for (i = 0; i<4; i++){
		cout << "+---------+---------+---------+---------+\n|         |         |         |         |" << endl;
		for (j = 0; j<4; j++){
			cout << "|   " << setw(2);
			if (board[i][j])
				cout << board[i][j];
			else
				cout << " ";
			cout << "    ";
		}
		cout << "|\n|         |         |         |         |" << endl;
	}
	cout << "+---------+---------+---------+---------+\n\nBEST  : " << best << endl;
	cout << "SCORE : " << score << endl << endl;
}
bool gojud(){
	int x, y, cnt = 0;
	bool s = false;
	for (x = 0; x < 4; x++, cnt = 0){
		for (y = 1; y < 4; y++){
			if (board[cnt][x] == board[y][x])
				s = true;
			cnt++;
		}
	}
	for (y = 0; y < 4; y++, cnt = 0){
		for (x = 1; x < 4; x++){
			if (board[y][cnt] == board[y][x])
				s = true;
			cnt++;
		}
	}
	return s;
}
int up(){
	int x, y, cnt = 0, s = 0;
	for (x = 0; x<4; x++, cnt = 0){
		for (y = 1; y<4; y++){
			if (board[y][x]){
				if (board[cnt][x] == board[y][x]){
					board[cnt][x] += board[y][x];
					score += board[cnt][x];
					board[y][x] = 0;
					s++;
					if (board[cnt][x]>63){
						g_over = 1;
						return 0;
					}
				}
				else{
					if (board[cnt][x] && y != (cnt + 1)){
						board[++cnt][x] = board[y][x];
						board[y][x] = 0;
						s++;
					}
					else if (!board[cnt][x]){
						board[cnt][x] = board[y][x];
						board[y][x] = 0;
						cnt--;
						s++;
					}
				}
				cnt++;
			}
		}
	}
	if (s)
		r_gen();
	if (!b_init() && !gojud())
		g_over = 2;
	return 0;
}
int down(){
	int x, y, cnt = 3, s = 0;
	for (x = 0; x<4; x++, cnt = 3){
		for (y = 2; y>=0; y--){
			if (board[y][x]){
				if (board[cnt][x] == board[y][x]){
					board[cnt][x] += board[y][x];
					score += board[cnt][x];
					board[y][x] = 0;
					s++;
					if (board[cnt][x]>63){
						g_over = 1;
						return 0;
					}
				}
				else{
					if (board[cnt][x] && y != (cnt - 1)){
						board[--cnt][x] = board[y][x];
						board[y][x] = 0;
						s++;
					}
					else if (!board[cnt][x]){
						board[cnt][x] = board[y][x];
						board[y][x] = 0;
						cnt++;
						s++;
					}
				}
				cnt--;
			}
		}
	}
	if (s)
		r_gen();
	if (!b_init() && !gojud())
		g_over = 2;
	return 0;
}
int left(){
	int x, y, cnt = 0, s = 0;
	for (y = 0; y<4; y++, cnt = 0){
		for (x = 1; x < 4; x++){
			if (board[y][x]){
				if (board[y][cnt] == board[y][x]){
					board[y][cnt] += board[y][x];
					score += board[y][cnt];
					board[y][x] = 0;
					s++;
					if (board[y][cnt]>63){
						g_over = 1;
						return 0;
					}
				}
				else{
					if (board[y][cnt] && x != (cnt + 1)){
						board[y][++cnt] = board[y][x];
						board[y][x] = 0;
						s++;
					}
					else if (!board[y][cnt]){
						board[y][cnt] = board[y][x];
						board[y][x] = 0;
						cnt--;
						s++;
					}
				}
				cnt++;
			}
		}
	}
	if (s)
		r_gen();
	if (!b_init() && !gojud())
		g_over = 2;
	return 0;
}
int right(){
	int x, y, cnt = 3, s = 0;
	for (y = 0; y<4; y++, cnt = 3){
		for (x = 2; x >= 0; x--){
			if (board[y][x]){
				if (board[y][cnt] == board[y][x]){
					board[y][cnt] += board[y][x];
					score += board[y][cnt];
					board[y][x] = 0;
					s++;
					if (board[y][cnt]>63){
						g_over = 1;
						return 0;
					}
				}
				else{
					if (board[y][cnt] && x != (cnt - 1)){
						board[y][--cnt] = board[y][x];
						board[y][x] = 0;
						s++;
					}
					else if (!board[y][cnt]){
						board[y][cnt] = board[y][x];
						board[y][x] = 0;
						cnt++;
						s++;
					}
				}
				cnt--;
			}
		}
	}
	if (s)
		r_gen();
	if (!b_init() && !gojud())
		g_over = 2;
	return 0;
}
