// Program to calculate the minimum number of coins for a given amount of change

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long change = 0;
    int coin[4] = {500, 100, 50, 10};

    cout << "Enter the amount of change: ";
    cin >> change;

    if (change < 0) {
        change = abs(change);
        cout << "Converted to positive: " << change << " won" << endl;
    }

    cout << "\nChange breakdown (number of coins):" << endl;
    for (int i = 0; i < 4; i++) {
        int num = change / coin[i];
        cout << coin[i] << " won coin: " << num << " pcs" << endl;
        change -= num * coin[i];
    }
    return 0;
}
