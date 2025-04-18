// Simulates digit-by-digit addition and subtraction of string-based integers.

#include <iostream>
#include <string.h>
#include <windows.h>
#include <math.h>

void s2a(char[], char[]);
void s2s(char[], char[]);

int i, j, s, c = 0, cnt = 0;
char buf1[50] = {0}, buf2[50] = {0}, s2i[51] = {0}, op;

int main(int argc, char **argv) {
    while (1) {
        std::cout << "Enter first number (no leading zeros): ";
        std::cin >> buf1;
        std::cout << "Enter second number (no leading zeros): ";
        std::cin >> buf2;
        std::cout << "Enter operator (+ or -): ";
        std::cin >> op;

        switch (op) {
        case '+': s2a(buf1, buf2); break;
        case '-': s2s(buf1, buf2); break;
        default:
            std::cout << "Invalid operator!";
            Sleep(500);
            system("cls");
            continue;
        }

        system("cls");
        std::cout << "First(length) " << op << " Second(length) = Result(length)" << std::endl;
        std::cout << buf1 << "(" << strlen(buf1) << ") " << op << " "
                  << buf2 << "(" << strlen(buf2) << ") = ";

        for (i = 1; i < 52; i++) {
            if (s2i[i] != '\0' && !(s2i[i - 1] == '\0' && s2i[i] == '0')) {
                std::cout << s2i[i];
                cnt++;
            }
        }
        std::cout << " (" << cnt << ")" << std::endl;

        std::cout << "\nReset? (c to continue) : ";
        std::cin >> op;
        if (op == 'c' || op == 'C') {
            system("cls");
            continue;
        } else {
            break;
        }
    }
    return 0;
}

void s2a(char n1[], char n2[]) {
    int in1 = strlen(n1) - 1, in2 = strlen(n2) - 1;
    for (i = 0;; i++) {
        s = c + n1[in1 - i] + n2[in2 - i] - 96;
        if (s > 9) {
            c = s / 10;
            s %= 10;
        } else c = 0;
        s2i[50 - i] = s + 48;
        if ((in1 - i) <= 0 || (in2 - i) <= 0) {
            if (strlen(n1) > strlen(n2)) {
                s2i[49 - i] = c + n1[in1 - i - 1];
                for (j = i + 1; j < i + abs(in1 - in2); j++)
                    s2i[49 - j] = n1[in1 - j - 1];
            } else if (strlen(n1) < strlen(n2)) {
                s2i[49 - i] = c + n2[in2 - i - 1];
                for (j = i + 1; j < i + abs(in1 - in2); j++)
                    s2i[49 - j] = n2[in2 - j - 1];
            }
            break;
        }
    }
    if (c != 0) s2i[48 - i] = c + 48;
}

void s2s(char n1[], char n2[]) {
    int in1 = strlen(n1) - 1, in2 = strlen(n2) - 1;
    for (i = 0;; i++) {
        if (strlen(n1) < strlen(n2))
            s = n2[in2 - i] - n1[in1 - i] - c;
        else
            s = n1[in1 - i] - n2[in2 - i] - c;

        if (s < 0) {
            c = 1;
            s += 10;
        } else {
            c = 0;
        }

        s2i[50 - i] = s + 48;

        if ((in1 - i) <= 0 || (in2 - i) <= 0) {
            if (strlen(n1) > strlen(n2)) {
                s2i[49 - i] = n1[in1 - i - 1];
                for (j = i + 1; j < i + abs(in1 - in2); j++)
                    s2i[49 - j] = n1[in1 - j - 1];
            } else if (strlen(n1) < strlen(n2)) {
                s2i[49 - i] = n2[in2 - i - 1];
                for (j = i + 1; j < i + abs(in1 - in2); j++)
                    s2i[49 - j] = n2[in2 - j - 1];
                s2i[48 - j] = '-';
                cnt--;
            }
            break;
        }
    }
}
