// A simple console program to draw stars: right triangle, isosceles triangle, and diamond.

#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
    int m = 4, l, i, j, k;
    while (m) {
        printf(" ** Star Drawing Program **\n");
        printf("1. Right Triangle  2. Isosceles Triangle  3. Diamond  4. Exit Program\n");
        printf("\t\t\t\t\t     Choice: ");
        m = getch();
        m -= 48;
        printf("[%d]\n", m);
        switch (m) {
            case 1:
                printf("Drawing a right triangle.\n");
                printf("Enter length: ");
                scanf("%d", &l);
                for (i = 1; i <= l; i++) {
                    for (j = 0; j < i; j++) {
                        printf("*");
                    }
                    printf("\n");
                }
                break;
            case 2:
                printf("Drawing an isosceles triangle.\n");
                printf("Enter length: ");
                scanf("%d", &l);
                for (i = 1; i <= l; i++) {
                    for (j = l - i; j > 0; j--) {
                        printf(" ");
                    }
                    for (k = 0; k < 2 * i - 1; k++) {
                        printf("*");
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("Drawing a diamond.\n");
                printf("Enter length: ");
                scanf("%d", &l);
                for (i = l - 1; i > -l; i--) {
                    for (j = 0; j < abs(i); j++) {
                        printf(" ");
                    }
                    for (k = 0; k < 2 * (l - abs(i)) - 1; k++) {
                        printf("*");
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting the program. Good job!");
                m = 0;
                break;
        }
        printf("\n");
    }
    return 0;
}
