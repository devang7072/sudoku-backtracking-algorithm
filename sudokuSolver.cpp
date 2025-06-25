#include <iostream>
#define N 9
using namespace std;

int grid[N][N] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

bool isInRow(int row, int num) {
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num) return true;
    return false;
}

bool isInCol(int col, int num) {
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num) return true;
    return false;
}

bool isInBox(int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[startRow + row][startCol + col] == num) return true;
    return false;
}

bool isValid(int row, int col, int num) {
    return !isInRow(row, num) && !isInCol(col, num) &&
           !isInBox(row - row % 3, col - col % 3, num);
}

bool findEmptyCell(int &row, int &col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool solveSudoku() {
    int row, col;
    if (!findEmptyCell(row, col))
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isValid(row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku())
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGridBoxed() {
    cout << "┌───────┬───────┬───────┐\n";
    for (int row = 0; row < N; row++) {
        cout << "│ ";
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
            if ((col + 1) % 3 == 0)
                cout << "│ ";
        }
        cout << "\n";
        if ((row + 1) % 3 == 0 && row != 8)
            cout << "├───────┼───────┼───────┤\n";
    }
    cout << "└───────┴───────┴───────┘\n";
}

int main() {
    if (solveSudoku())
        printGridBoxed();
    else
        cout << "No solution exists.\n";
    return 0;
}
