//For windows visual studio

//The Bright game is based on tile map. One touch the tile will turn on and another touch will turn off.
//In addition, when one tile turn to on, then near tiles such as up, down, left and right also turn on or off.
//Furthermore, for hard mode, full bright situation will given two touch(one touch makes tiles deemed).

//In this program, the tile map matches 0-None tile, 1-Bright tile(or Deemed tile on double touch mode), 2-Bright tile(Hard mode only)
//If this program can solve the situation, then it will print the solving method.
//In this situation, they print step and tile number of we can touch.
//For example, maximum touch number for full bright is 1, the map is
//[111
// 010
// 111]
//and the result is
//1 : 1
//2 : 3
//3 : 4
//4 : 5
//5 : 7
//It means that you should touch the first tile on first.

#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

bool s=true;
int n=0, x=0, y=0, d=0;
int **map = (int **)malloc(sizeof(int *));
typedef struct XY{
	int x;
	int y;
};
XY *ord=(XY *)malloc(sizeof(XY));

void init();
void fn(int sp, int level, int pos[]);
void tap(int n, int add);
bool jd();
void print();

int main(){
	int i=0, j=0, c=0, *pos = (int *)malloc(sizeof(int));
	bool f=false;
	DWORD count=0;

	//just input number is enough to continue.
	cout << "Maximum touch number for full bright on a tile(1~2) : ";
	while(1){
		d = getch()-48;
		if(d<3 && d>0){
			cout << d << endl;
			break;
		}
	}
	//Input map shape. 0 is None tile, 1 or 2 is actual tile.
	//If you input 2 in max touch number, then you can input 0, 1, 2. Or 1 is 0, 1.
	//Enter is Ok. And if you want to end to make a map, press / key to continue.
	cout << "map shape(end : / key) : " << endl;
	for(i=0 ; ; i++){
		map = (int **)realloc(map, sizeof(int)*(i+1));
		map[i] = (int *)malloc(sizeof(int));
		for(j=0 ; ; j++){
			c = getch();
			if(c=='/'){
				f=true;
				cout << endl;
				break;
			}
			else if(c==13){
				cout << endl;
				break;
			}
			else if(c==8){
				j-=2;
				printf("\b \b");
				if(j<-1){
					i--;
					j=x-1;
					system("cls");
					cout << "Maximum touch number for full bright on a tile(1~2) : ";
					cout << d << endl;
					cout << "map shape(end : / key) : " << endl;
					for(int m=0 ; m<i+1 ; m++){
						for(int n=0 ; n<j+1 ; n++){
							cout << map[m][n];
						}
						if(m!=i)
							cout << endl;
					}
				}
				continue;
			}
			else if(c>49+d || c<48) j--;
			else{
				map[i][j] = c-48;
				cout << map[i][j];
				map[i] = (int *)realloc(map[i], sizeof(int)*(j+2));
			}
		}
		x=j;
		if(f) break;
	}
	y=i+1;

	print();
	init();
	count = GetTickCount();
	for(i=1 ; ; i++){
		pos = (int *)realloc(pos, sizeof(int)*i);
		fn(0, i-1, pos);
		if(!s) break;
	}
	print();
	cout << "Taking time : " << (double)(GetTickCount()-count)/1000 << "초" << endl;
	cout << "Minimum number of step : " << i << endl << endl;
	for(j = i-1 ; j>-1 ; j--) cout << i-j << " : " << pos[j] << endl;

	for(i=0 ; i<y ; i++) free(map[i]);
	free(map);
	free(ord);
	free(pos);

	getch();
	return 0;
}

void init(){
	for(int i=0 ; i<y ; i++)
		for(int j=0 ; j<x ; j++)
			if(map[i][j]){
				ord=(XY *)realloc(ord, sizeof(XY)*(n+1));
				ord[n].y = i;
				ord[n].x = j;
				n++;
			}
}

void fn(int sp, int level, int pos[]){
	int i;
	for(i=sp ; i<n && s ; i++){
		tap(i, 1);
		if(level) fn(i, level-1, pos);
		else if(jd()) s=false;
		if(s) tap(i, -1);
	}
	pos[level]=i;
}

bool jd(){
	for(int i=0 ; i<y ; i++)
		for(int j=0 ; j<x ; j++)
			if(map[i][j]%(d+1)) return false;
	return true;
}

void print(){
	for(int i=0 ; i<y ; i++){
		for(int j=0 ; j<x ; j++)
			if(map[i][j]%(d+1)==1) cout << "□";
			else if(map[i][j]%(d+1)==2) cout << "▦";
			else if(map[i][j]&&!(map[i][j]%(d+1))) cout << "■";
			else if(!map[i][j]) cout << "　";
		cout << endl;
	}
	cout << endl;
}

void tap(int a, int add){
	int y = ord[a].y, x = ord[a].x;
	map[y][x]+=add;
	if(y>0)
		if(map[y-1][x]) map[y-1][x]+=add;
	if(x>0)
		if(map[y][x-1]) map[y][x-1]+=add;
	if(y<::y-1)
		if(map[y+1][x]) map[y+1][x]+=add;
	if(x<::x-1)
		if(map[y][x+1]) map[y][x+1]+=add;
}
