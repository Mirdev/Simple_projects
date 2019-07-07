#include<stdio.h>
main(){
	double C=0, F=0, K=0;
	char T[4];

	for( ; ; ){
		printf("Celsius : C, Fahrenheit : F, Kelvin : K\n");
		printf("Input two capital of degrees from A to B, in a row. (For example(Celsius->Fahrenheit: CF)(If you want to quit, type END) -> ");

    scanf("%s", T);

    if(((T[0]=='E')&&(T[1]=='N')&&(T[2]=='D'))||((T[0]=='e')&&(T[1]=='n')&&(T[2]=='d'))){
      break;
    }

    if(((T[0]=='C')&&(T[1]=='F'))||((T[0]=='c')&&(T[1]=='f'))){
      printf("Input Celsius temperature -> ");
      scanf("%lf", &C);
      F=((((double)C*9.0)/5.0)+32.0);
      printf("Fahrenheit temperature : %lf\n", F);
    }

    if(((T[0]=='F')&&(T[1]=='C'))||((T[0]=='f')&&(T[1]=='c'))){
      printf("Input Fahrenheit temperature -> ");
      scanf("%lf", &F);
      C=((((double)F*5.0)/9.0)-32.0);
      printf("Celsius temperature : %lf\n", C);
    }

    if(((T[0]=='C')&&(T[1]=='K'))||((T[0]=='c')&&(T[1]=='k'))){
      printf("Input Celsius temperature -> ");
      scanf("%lf", &C);
      K=(C+273.15\);
      printf("Kelvin temperature : %lf\n", K);
    }

    if(((T[0]=='K')&&(T[1]=='C'))||((T[0]=='k')&&(T[1]=='c'))){
      printf("Input Kelvin temperature -> ");
      scanf("%lf", &K);
      C=(K-273.15);
      printf("Celsius temperature : %lf\n", C);
    }

    if(((T[0]=='F')&&(T[1]=='K'))||((T[0]=='f')&&(T[1]=='k'))){
      printf("Input Fahrenheit temperature -> ");
      scanf("%lf", &F);
      K=(((((double)F*5.0)/9.0)-32.0)+273);
      printf("Kelvin temperature : %lf\n", K);
    }

    if(((T[0]=='K')&&(T[1]=='F'))||((T[0]=='k')&&(T[1]=='f'))){
      printf("Input Kelvin temperature -> ");
      scanf("%lf", &K);
      F=(((((double)K*9.0)/5.0)+32.0)-273);
      printf("Fahrenheit temperature : %lf\n", F);
    }
	}
}
