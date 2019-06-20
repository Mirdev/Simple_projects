#include<iostream>
using namespace std;

#define MAX 100
char buf[MAX]={0,};
char per[MAX]={0,};

int num[MAX]={0,};
bool occ[MAX]={0,};
int n=0, m=1, size=0;

void TD(int);
void arysiz(char[]);
void input(char[]);

FILE *fp;

int main(){
	fp=fopen("result.txt", "w+");
	cout << "Input elements for permutation (split by using space or ,) : ";
	cin >> buf;fflush(stdin);
	input(buf);
	arysiz(per);
	while(1){
		cout << "print: 1.only monitor 2.only file 3.both of monitor and file" << endl;
		cin >> m;fflush(stdin);
		system("cls");
		if(m<1 || m>3)
			cout << "*** You should select between 1-3. ***\n" << endl;
		else
			break;
	}
	if(m==2)
		cout << "Printing..." << endl;
	TD(0);
	if(m==2){
		system("cls");
		cout << "Print completed." << endl;
	}
	if(m!=1)
		fprintf(fp, "%d", n);
	if(m!=2)
		cout << n << endl;
	fclose(fp);
	return 0;
}

void TD(int j){
	int x;
	if(j==::size){
		for(x=0 ; x<::size ; x++){
			if(m!=1)
				fprintf(fp, "%c", per[num[x]]);
			if(m!=2)
				cout << per[num[x]];
		}
		if(m!=1)
			fprintf(fp, "\n");
		if(m!=2)
			cout << endl;
		n++;
		j--;
	}
	for(x=0 ; x<::size ; x++){
		if(occ[x]==true)
			continue;
		num[j]=x;
		occ[num[j]]=true;
		TD(j+1);
		occ[num[j]]=false;
	}
}

void arysiz(char x[]){
	int i;
	for(i=0 ; x[i] ; i++)
		::size++;
}

void input(char x[]){
	int i, n=0;
	for(i=0 ; x[i] ; i++)
		if(x[i]!=','){
			per[n]=x[i];
			n++;
		}
}
