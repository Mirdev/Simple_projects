// For Windows Visual Studio

/*
    Bright Puzzle (Lights Out-like Puzzle) Solver
    ---------------------------------------------
    This program is a single-state (touch-once) version of PuzzlegameSolver_Bright.cpp.
    In other words, it serves as a prototype of PuzzlegameSolver_Bright.cpp.

    How to use:
    - You will be prompted to enter the map layout, line by line.
    - Each number must be either 0 or 1.
    - Enter the `/` key on a new line to finish input.
    - The program will find the minimum sequence of "tap" operations 
      that turns all non-zero tiles to zero (i.e., makes the board fully "bright").
    - Tapping a tile toggles itself and its 4 neighbors (up, down, left, right).

    Output:
    - Initial and final state of the map
    - Time taken to compute the solution
    - Minimum number of taps and the positions of each tap
*/


#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

bool solved = true;
int numTiles = 0, width = 0, height = 0, activeSum = 0;
int **map = (int **)malloc(sizeof(int *));
typedef struct Position {
    int x;
    int y;
};
Position *coords = (Position *)malloc(sizeof(Position));

void initialize();
int solve(int start, int level, int pos[]);
void toggle(int index);
bool isCleared();
void printMap();

int main() {
    int i = 0, j = 0, c = 0, value = 0, *solution = (int *)malloc(sizeof(int));
    bool finishInput = false;
    DWORD startTime = 0;

    cout << "Enter map layout (finish input with `/` key):" << endl;
    for (i = 0;; i++) {
        map = (int **)realloc(map, sizeof(int) * (i + 1));
        map[i] = (int *)malloc(sizeof(int));
        for (j = 0;; j++) {
            c = getch();
            if (c == '/') {
                finishInput = true;
                cout << endl;
                break;
            } else if (c == 13) {
                cout << endl;
                break;
            } else if (c == 8) {
                j -= 2;
                printf("\b \b");
                if (j < -1) {
                    i--;
                    j = width - 1;
                    system("cls");
                    cout << "Enter map layout (finish input with `/` key):" << endl;
                    for (int m = 0; m < i + 1; m++) {
                        for (int n = 0; n < j + 1; n++) cout << map[m][n];
                        if (m != i) cout << endl;
                    }
                }
                continue;
            } else if (c > '2' || c < '0') {
                j--;
            } else {
                value = (c > '1') ? c - '3' : c - '0';
                map[i][j] = value;
                cout << (char)c;
                map[i] = (int *)realloc(map[i], sizeof(int) * (j + 2));
            }
        }
        width = j;
        if (finishInput) break;
    }
    height = i + 1;

    printMap();
    initialize();
    startTime = GetTickCount();
    for (i = 1;; i++) {
        solution = (int *)realloc(solution, sizeof(int) * i);
        solve(0, i - 1, solution);
        if (!solved) break;
    }
    printMap();
    cout << "Time taken: " << (double)(GetTickCount() - startTime) / 1000 << " sec" << endl;
    cout << "Minimum taps: " << i << endl << endl;
    for (j = i - 1; j > -1; j--) cout << i - j << " : " << solution[j] << endl;

    for (i = 0; i < height; i++) free(map[i]);
    free(map);
    free(coords);
    free(solution);

    getch();
    return 0;
}

void initialize() {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (map[i][j]) {
                coords = (Position *)realloc(coords, sizeof(Position) * (numTiles + 1));
                coords[numTiles].y = i;
                coords[numTiles].x = j;
                numTiles++;
                if (map[i][j] == 1) activeSum++;
            }
}

int solve(int start, int level, int pos[]) {
    int i;
    for (i = start; i < numTiles - level && solved; i++) {
        toggle(i);
        if (activeSum > 5 * (level + 1)) {
            toggle(i);
            return 0;
        }
        if (level) solve(i + 1, level - 1, pos);
        else if (isCleared()) solved = false;
        if (solved) toggle(i);
    }
    pos[level] = i;
    return 0;
}

bool isCleared() {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (map[i][j] > 0) return false;
    return true;
}

void printMap() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            if (map[i][j] > 0) cout << "□";
            else if (map[i][j]) cout << "■";
            else if (!map[i][j]) cout << "　";  // Full-width space
        cout << endl;
    }
    cout << endl;
}

void toggle(int index) {
    int y = coords[index].y, x = coords[index].x;
    map[y][x] *= -1;
    activeSum += map[y][x];
    if (y > 0 && map[y - 1][x]) {
        map[y - 1][x] *= -1;
        activeSum += map[y - 1][x];
    }
    if (x > 0 && map[y][x - 1]) {
        map[y][x - 1] *= -1;
        activeSum += map[y][x - 1];
    }
    if (y < ::height - 1 && map[y + 1][x]) {
        map[y + 1][x] *= -1;
        activeSum += map[y + 1][x];
    }
    if (x < ::width - 1 && map[y][x + 1]) {
        map[y][x + 1] *= -1;
        activeSum += map[y][x + 1];
    }
}
