#include<iostream>
#include<conio.h>
#include<cmath>
#include<climits>
#include<windows.h>
using namespace std;

//Maximum denominator : 1073741823

FILE *fl;
double f(double x){
	return 1/(x*x);
}
void fprint(char *e, double a, double b, int n, double m, double l, double s){
	fprintf(fl,"Function %s\n", e);
	fprintf(fl,"Result [From %lf to %lf, Devided by %d section, By using rectangle method(midpoint)] =          %lf\n",a,b,n,m);
	fprintf(fl,"Result [From %lf to %lf, Devided by %d section, By using trapezoidal rule] =            %lf\n",a,b,n,l);
	fprintf(fl,"Result [From %lf to %lf, Devided by %d section, By using Simpson's rule] =     %lf\n",a,b,n,s);
}
void fprint2(char *e, double a, double b, int n, double m, double l){
	fprintf(fl,"Function %s\n", e);
	fprintf(fl,"Result [From %lf to %lf, Devided by %d section, By using rectangle method(midpoint)] =          %lf\n",a,b,n,m);
	fprintf(fl,"Result [From %lf to %lf, Devided by %d section, By using trapezoidal rule] =            %lf\n",a,b,n,l);
}
int main(){
	//Initialize
	char *e="1/(x*x)";
	int n, flag=0, k=0, tmp, slt, t, st;
	double a, b;
	double dx, dx2, mx, s=0, m=0, l=0;
	fl=fopen("result.txt", "a+");

	//Input
	cout << "Function " << e << endl;
	cout << "from : ";
	cin >> a;
	cout << "to : ";
	cin >> b;
	cout << "1.Set a number of sector directly, 2.Maximum number of sector, 3.Maximum number of sector/2, 4.Maximum number of sector/4" << endl;
	cin >> slt;
	if(!(slt-1)){
		cout << "A number of sector : ";
		cin >> n;
	}
	else{
		if(slt==2){
			cout << "Maximum number of sector. n=" << INT_MAX << endl;
			n=INT_MAX;
		}
		else if(slt==3){
			cout << "Half of maximum number of sector. n=" << INT_MAX/2 << endl;
			n=INT_MAX/2;
		}
		else if(slt==4){
			cout << "Quarter of maximum number of sector. n=" << INT_MAX/4 << endl;
			n=INT_MAX/4;
		}
		cout << "Press Any Key To Continue...";
		getch();
	}

	t=GetTickCount();

	//Common
	if(!(n%2))
		dx=(b-a)/double(n);
	dx2=(b-a)/double(n);

	for(int i=0 ; i<=n ; i++){
		if(i>0 && i<=n){						//rectangle method(midpoint)
			mx=(2*a+dx2*(2*i-1))/2;
			m+=f(mx);
		}
		if(i==0 || i==n)						//trapezoidal rule
			l+=f(a+dx2*i);
		else if(i>0 && i<n)
			l+=2*f(a+dx2*i);
		if(!(n%2)){								//Simpson's rule
			if(i>0 && i<n && i%2!=0)
				s+=4*f(a+(dx*i));
			else if(i>0 && i<n && i%2!=1)
				s+=2*f(a+(dx*i));
			else
				s+=f(a+(dx*i));
		}
		if(!i){									//Print of processing
			system("cls");
			cout << "Processing..." << endl;
		}
	}
	m*=dx2;
	l*=dx2/2;
	if(!(n%2))
		s*=dx/3;

	//result
	system("cls");
	cout << "Complete." << endl;
	st=GetTickCount()-t;
	cout << "Function " << e << endl;
	cout << "Spent time : " << st << "ms\n";
	cout << "n = " << n << endl;
  cout << "Result [From " << a << " to " << b << ", Devided by " << n << " section, By using rectangle method(midpoint)]" << endl;
	cout << " = " << m << endl;
  cout << "Result [From " << a << " to " << b << ", Devided by " << n << " section, By using trapezoidal rule]" << endl;
	cout << " = " << l << endl;
	if(!(n%2)){
		cout << "Result [From " << a << " to " << b << ", Devided by " << n << " section, By using Simpson's rule]" << endl;
		cout << " = " << s << endl;
	}
	if(n%2)
		cout << "Mean : " << (m+l)/2 << endl;
	else
		cout << "Mean : " << (m+l+s)/3 << endl;

	//Save file
	fprintf(fl,"n = %d\n", n);
	if(!(n%2))
		fprint(e, a, b, n, m, l, s);
	else
		fprint2(e, a, b, n, m, l);
	fprintf(fl, "Mean =");
	tmp=n;
	for(k=0 ; !flag ; )
		if(n!=0){
			k++;
			n/=10;
		}
		else
			flag=1;
	flag=0;
	n=tmp;
	for(int i=0 ; i<k ; i++)
		fprintf(fl, " ");
	if(n%2)
		fprintf(fl, "                                                                                    %lf", (m+l)/2);
	else
		fprintf(fl, "                                                                                    %lf", (m+l+s)/3);
	fprintf(fl, "\nSpent time : %dms\n\n", st);
	fclose(fl);
	return 0;
}
