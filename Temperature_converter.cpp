// Temperature converter between Celsius, Fahrenheit, and Kelvin (legacy, Aug 21, 2006)
#include <stdio.h>

int main() {
    double C = 0, F = 0, K = 0;
    char T[4];

    for (;;) {
        printf("Celsius : C, Fahrenheit : F, Kelvin : K\n");
        printf("Enter the two-letter conversion code (e.g., CF). (To exit: END) -> ");

        scanf("%3s", T);

        if (((T[0] == 'E') && (T[1] == 'N') && (T[2] == 'D')) ||
            ((T[0] == 'e') && (T[1] == 'n') && (T[2] == 'd'))) {
            break;
        }

        if (((T[0] == 'C') && (T[1] == 'F')) || ((T[0] == 'c') && (T[1] == 'f'))) {
            printf("Enter Celsius -> ");
            scanf("%lf", &C);
            F = (((double)C * 9.0) / 5.0) + 32.0;
            printf("Fahrenheit : %lf\n", F);
        }

        if (((T[0] == 'F') && (T[1] == 'C')) || ((T[0] == 'f') && (T[1] == 'c'))) {
            printf("Enter Fahrenheit -> ");
            scanf("%lf", &F);
            C = (((double)F * 5.0) / 9.0) - 32.0;
            printf("Celsius : %lf\n", C);
        }

        if (((T[0] == 'C') && (T[1] == 'K')) || ((T[0] == 'c') && (T[1] == 'k'))) {
            printf("Enter Celsius -> ");
            scanf("%lf", &C);
            K = C + 273.15;
            printf("Kelvin : %lf\n", K);
        }

        if (((T[0] == 'K') && (T[1] == 'C')) || ((T[0] == 'k') && (T[1] == 'c'))) {
            printf("Enter Kelvin -> ");
            scanf("%lf", &K);
            C = K - 273.15;
            printf("Celsius : %lf\n", C);
        }

        if (((T[0] == 'F') && (T[1] == 'K')) || ((T[0] == 'f') && (T[1] == 'k'))) {
            printf("Enter Fahrenheit -> ");
            scanf("%lf", &F);
            K = (((double)F * 5.0) / 9.0) - 32.0 + 273;
            printf("Kelvin : %lf\n", K);
        }

        if (((T[0] == 'K') && (T[1] == 'F')) || ((T[0] == 'k') && (T[1] == 'f'))) {
            printf("Enter Kelvin -> ");
            scanf("%lf", &K);
            F = (((double)K * 9.0) / 5.0) + 32.0 - 273;
            printf("Fahrenheit : %lf\n", F);
        }
    }
    return 0;
}
