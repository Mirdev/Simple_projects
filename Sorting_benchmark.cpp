// Sorting algorithm benchmark tool
// Generates arrays using different randomization methods and compares the performance of various sorting algorithms.
// Outputs results to a file including elapsed time and sorted data.
// TMI:
// "This code reflects both a technical challenge and nostalgic memory from the netbook era."

#include<iostream>
#include<ctime>
#include<cstring>
#include<windows.h>
using namespace std;

void rand_arr(int,int,int);
void print_arr(int,int);
void selection_sort_n(int);
void selection_sort_m(int);
void selection_sort(int);
void bubble_sort(int);
void insertion_sort(int);
void asdf_sort(int);
void arr_copy(int,int);
void file_save(int,char*,int,int);
void init(int&,int&,int&,char&);

#define ORIGINE 0
#define SELECTION 1
#define BUBBLE 2
#define INSERTION 3
#define ASDF 4

#define NSIZE 10
#define SIZE 100000000

FILE *fp;
clock_t t;
int a[SIZE]={0,}, sel[SIZE], ins[SIZE], asd[SIZE], i, j, tmp;

int main(){
	int size=10, type=1, nsize=10;
	char finit='n';

	init(size, type, nsize, finit);

	rand_arr(size, nsize, type);
	//print_arr(ORIGINE, size);

	selection_sort(size);
	//print_arr(SELECTION, size);
	selection_sort_n(size);
	//print_arr(SELECTION, size);
	selection_sort_m(size);
	//print_arr(SELECTION, size);
	insertion_sort(size);
	//print_arr(INSERTION, size);
	//asdf_sort(size);
	//print_arr(ASDF, size);
	bubble_sort(size);
	//print_arr(BUBBLE, size);

	return 0;
}

void init(int &size, int &type, int &nsize, char &finit){
	srand((unsigned)time(NULL));
a:
	cout << "Array Size : ";	cin >> size;
	if(size<0||size>100000000)
		goto a;
b:
	cout << "Randomization Method (1.Repetition, 2.No Repetition, 3.Partial Shuffle): ";	cin >> type;
	if(type<1||type>3)
		goto b;
c:
	cout << "Initialize result file? (y/n): ";	cin >> finit;
	if(!(finit=='y'||finit=='Y'||finit=='n'||finit=='N'))
		goto c;
	if(type==3){
d:
		cout << "Size division number: ";	cin >> nsize;
		if(nsize>=size)
			goto d;
	}

	switch(finit){
		case 'N':
		case 'n':	cout << "\nResult file will not be initialized.\n" << endl;
			break;
		case 'Y':
		case 'y':
			cout << "\nInitializing result file.\n" << endl;
			fp=fopen("result.txt", "w+");
			fclose(fp);
	}

	cout << "Generating " << size << " data elements.\n" << endl;
}

void file_save(int size, char *str, int ary[], int time){
	fp=fopen("result.txt", "a+");
	if(!strcmp(str, "array randomizing")){
		fprintf(fp, "\n\n");
		fprintf(fp, "Data Size : %d\n", size);
	}
	fprintf(fp, "%s started.\n", str);
	fprintf(fp, "%s completed.\n", str);
	for(i=1 ; i<size+1 ; i++){
		fprintf(fp,"%9d",ary[i-1]);
		if(!(i%13))
			fprintf(fp,"\n");
	}
	fprintf(fp, "\nElapsed Time: %dms\n\n", time);
	fclose(fp);
}

void asdf_sort(int size){
	arr_copy(ASDF, size);
	cout << "Starting asdf sort...\n";
	t=GetTickCount();
	for(i=1 ; i<size ; i++){
		if(asd[i-1]>asd[i]){
			tmp=asd[i-1];
			asd[i-1]=asd[i];
			asd[i]=tmp;
			for(j=i ; j>0 ; j--)
				if(asd[j-1]>asd[j]){
					tmp=asd[j-1];
					asd[j-1]=asd[j];
					asd[j]=tmp;
				}
		}
	}
	cout << "asdf sort completed.\n";
	cout << "Elapsed Time: " << GetTickCount()-t << "ms\n" << endl;
	file_save(size, "asdf sorting", asd, GetTickCount()-t);
}

void insertion_sort(int size){
	arr_copy(INSERTION, size);
	cout << "Starting insertion sort...\n";
	t=GetTickCount();
	for(i=1 ; i<size ; i++){
		tmp=ins[i];
		for(j=i-1 ; j>-1&&ins[j]>tmp ; j--)
			ins[j+1]=ins[j];
		ins[j+1]=tmp;
	}
	cout << "Insertion sort completed.\n";
	cout << "Elapsed Time: " << GetTickCount()-t << "ms\n" << endl;
	file_save(size, "insertion sorting", ins, GetTickCount()-t);
}

void bubble_sort(int size){
	int f=1;
	cout << "Starting bubble sort...\n";
	t=GetTickCount();
	for(i=1 ; i<size ; i++){
		for(j=0 ; j<size-i ; j++){
			if(a[j]>a[j+1]){
				tmp=a[j+1];
				a[j+1]=a[j];
				a[j]=tmp;
				f=0;
			}
		}
		if(f)
			break;
		f=1;
	}
	cout << "Bubble sort completed.\n";
	cout << "Elapsed Time: " << GetTickCount()-t << "ms" << endl;
	file_save(size, "bubble sorting", a, GetTickCount()-t);
}

void selection_sort(int size){
	int j_;
	arr_copy(SELECTION, size);
	cout << "Starting selection sort...\n";
	t=GetTickCount();
	for(i=0 ; i<size-1 ; i++){
		j_=i;
		for(j=i+1 ; j<size ; j++){
			if(sel[j]<sel[j_])
				j_=j;
		}
		if(j_!=i){
			tmp=sel[j_];
			sel[j_]=sel[i];
			sel[i]=tmp;
		}
	}
	cout << "Selection sort completed.\n";
	cout << "Elapsed Time: " << GetTickCount()-t << "ms\n" << endl;
	file_save(size, "selection sorting", sel, GetTickCount()-t);
}

void selection_sort_m(int size){
	int max=0, j_;
	arr_copy(SELECTION, size);
	cout << "Starting selection sort (max first)...\n";
	t=GetTickCount();
	for(i=size-1 ; i>-1 ; i--){
		for(j=0 ; j<i+1 ; j++){
			if(max<sel[j]){
				max=sel[j];
				j_=j;
			}
		}
		tmp=sel[i];
		sel[i]=max;
		sel[j_]=tmp;
		max=0;
	}
	cout << "Selection sort (max first) completed.\n";
	cout << "Elapsed Time: " << GetTickCount()-t << "ms\n" << endl;
	file_save(size, "selection sorting(max)", sel, GetTickCount()-t);
}

void selection_sort_n(int size){
	int min=2147483647, j_;
	arr_copy(SELECTION, size);
	cout << "Starting selection sort (min first)...\n";
	t=GetTickCount();
	for(i=0 ; i<size ; i++){
		for(j=i ; j<size ; j++){
			if(min>sel[j]){
				min=sel[j];
				j_=j;
			}
		}
		tmp=sel[i];
		sel[i]=min;
		sel[j_]=tmp;
		min=2147483647;
	}
	cout << "Selection sort (min first) completed.\n";
	cout << "Elapsed Time: " << GetTickCount()-t << "ms\n" << endl;
	file_save(size, "selection sorting(min)", sel, GetTickCount()-t);
}

void arr_copy(int x, int size){
	switch(x){
		case SELECTION:
			for(i=0 ; i<size ; i++)
				sel[i]=a[i];
			break;
		case INSERTION:
			for(i=0 ; i<size ; i++)
				ins[i]=a[i];
			break;
		case ASDF:
			for(i=0 ; i<size ; i++)
				asd[i]=a[i];
			break;
	}
}

void rand_arr(int size, int nsize, int x){
	int r;
	bool f=false;

	cout << "Generating array...\n";
	t=GetTickCount();

	switch(x){
		case 1:
			cout << "Generating array with repetition allowed.\n";
			for(i=0 ; i<size ; i++)
				a[i]=rand()%size+1;
			break;
		case 2:
			cout << "Generating array with no repetition.\n";
			for(i=1 ; !f ; i+=(rand()%5)+1){
				for(int k=0 ; k<size ; k++){
					if(!a[k]){
						f=false;
						break;
					} else {
						f=true;
					}
				}
				r=rand()%size;
				if(!a[r])
					a[r]=i;
				else
					i--;
			}
			break;
		case 3:
			cout << "Generating array with partial shuffle.\n";
			for(i=0 ; i<size ; i++)
				a[i]=i+1;
			for(i=0 ; i<size/nsize ; i++){
				r=rand()%size;
				tmp=a[r];
				a[r]=a[size-r-1];
				a[size-r-1]=tmp;
			}
			break;
	}

	cout << "Array randomization complete.\n";
	cout << "Elapsed Time: " << GetTickCount()-t << "ms\n" << endl;
	file_save(size, "array randomizing", a, GetTickCount()-t);
}

void print_arr(int x, int size){
	cout << "Printing array...\n";
	for(i=0 ; i<size ; i++){
		switch(x){
			case ORIGINE:
			case BUBBLE:
				cout << a[i] << " ";
				break;
			case SELECTION:
				cout << sel[i] << " ";
				break;
			case INSERTION:
				cout << ins[i] << " ";
				break;
			case ASDF:
				cout << asd[i] << " ";
				break;
		}
	}
	cout << endl;
	cout << "Print completed.\n\n";
}
