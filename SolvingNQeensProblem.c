
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int n;
int path[15] = { 0, };	
int pathcnt = 0;
int outputcnt = 0;


int isPromising(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (path[i] == col + 1) 
			return 0;	
		else if (path[i] - col == row - i + 1) 
			return 0;			
		else if (path[i] - i == col - row + 1) 
			return 0;	
	}
	return 1;
}

void backtracking(int row) {

	if (row == n) {
		pathcnt++; 
		printf("%d: [", ++outputcnt);
		for (int i = 0; i < n; i++) {
			if (i != n - 1) {
				printf("<%d,%d>, ", i + 1, path[i]);
			}
			else {
				printf("<%d,%d>] ", i + 1, path[i]);
			}
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isPromising(row, i)) {
			path[row] = i + 1;	
			backtracking(row + 1);
		}
		else continue;
	}
}


int main() {

	scanf_s("%d", &n);

	backtracking(0);

	printf("Total number: %d", pathcnt);

	printf("\n\npress to exit ");
	_getch(); 
}
