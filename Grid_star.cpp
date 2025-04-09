// Draw an asterisk at a chosen (x, y) point in a 10x10 grid.

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;

#define SMAX 10

void gotos(int x, int y);
void chprint(char chs[]);

struct Location{
	int x;
	int y;
	//char chs[100];
	inline void save(int n);
	inline void print();
};

int sam[SMAX][SMAX]={0, };

inline void Location::save(int n){
	//gotos(x, y);
	//chprint(chs);
	sam[y][x]='*';
}

inline void Location::print(){
	for(int i=0 ; i<SMAX ; i++){
		for(int j=0 ; j<SMAX ; j++){
			if(sam[i][j]!='*')
				printf("%c ", sam[i][j]);
			else
				printf("%c ", sam[i][j]);
		}
		cout << endl;
	}
}

void main(){
	bool sw=false;
	int x=0, y=0, n=0, dn=0, tn=0, cnt=0, cntt=1, nn=0, xn=0, yn=0;
	char in[100]={0, }, xs[100]={0, }, ys[100]={0, }, ns[100]={0, };
	for(int i=0 ; i<SMAX ; i++){
		for(int j=0 ; j<SMAX ; j++){
			sam[i][j]='.';
		}
	}
	Location to[10];
	to[0].print();
	for(int k=0 ; ; k++){
		dn=cntt+2;
		tn=0;
		for(int i=0 ; ; i++){
			if(dn!=0){
				dn/=10;
				tn++;
			}
			else
				break;
		}
		cntt=1;
		for(int i=0 ; i<SMAX ; i++){
			for(int j=0 ; j<SMAX ; j++){
				if(sam[i][j]=='*')
					cntt++;
			}
		}
		for(int i=1 ; i<tn ; i++){
			cout << " ";
		}
		cout << "   x,y(,n)" << endl;
		cout << n+1 << "> ";
		gets(in);
		system("cls");
		yn=0; xn=0; nn=0; tn=0; cnt=0;
		for(int i=0 ; i<100 ; i++){
			if(in[i]=='\0'){
				break;
			}
			if(in[i]==','){
				tn++;
			}
			else if(tn==0){
				xs[i]=in[i];
				xn++;
			}
			else if(tn==1){
				ys[i-cnt]=in[i];
				yn++;
			}
			else if(tn==2){
				ns[i-cnt]=in[i];
				nn++;
			}
			cnt++;
		}
		x=0; y=0;
		for(int i=0 ; i<(sizeof(xs)/sizeof(xs[0])) ; i++){
			if(xs[i]=='\0')
				break;
			x+=(xs[i]-49)*pow((long double)10, (int)xn-i-1);
		}
		for(int i=0 ; i<(sizeof(ys)/sizeof(ys[0])) ; i++){
			if(ys[i]=='\0')
				break;
			y+=(ys[i]-49)*pow((long double)10, (int)yn-i-1);
		}
		for(int i=0 ;  ; i++){
			if(ns[i]=='\0')
				break;
			n+=(ns[i]-48)*pow((long double)10, (int)nn-i-1);
			sw=true;
		}
		if(sw){
			to[n%10].x=x;
			to[n%10].y=y;
			//strcpy(to[n].chs,"*");
			to[n%10].save(n);
			sw=false;
		}
		else{
			to[cntt%10].x=x;
			to[cntt%10].y=y;
			//strcpy(to[cntt].chs,"*");
			to[cntt%10].save(n);
		}
		n=0;
		to[0].print();
	}
}

/*void gotos(int x, int y){  
	for(int i=0 ; i<y-1 ; i++){
		cout << "." << endl;
	}
	for(int i=0 ; i<x ; i++){
		cout << ".";
	}
}*/

//void chprint(char chs[]){
//	cout << chs << endl;
//}
