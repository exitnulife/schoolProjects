#include <stdio.h>
#include <stdlib.h>

void gridCalculation(int rows, int cols, char* grid){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        grid[i * cols + j] = '.';
        }
    }
}

void gridPrint(int rows, int cols, char* grid){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", grid[i * cols + j]);
        }
        printf("\n");
    }
}

int indexCalculation(int row, int col, int cols) {
    return row * cols + col;
}

void moveTurtle(int direction, int* turtleCol, int* turtleRow){
    switch (direction) {
        case 0:
            *turtleCol = *turtleCol + 1;
            break;
        case 1:
            *turtleRow = *turtleRow + 1;
            break;
        case 2:
            *turtleCol = *turtleCol - 1;
            break;
        case 3:
            *turtleRow = *turtleRow - 1;
            break;
        default:
            fprintf(stderr, "Error in moveTurtle");
        break;
    }
}

void checkTurtleBoundaries(int* turtleCol, int cols, int* turtleRow, int rows){
    if (*turtleCol >= cols) {*turtleCol = 0;}
    if (*turtleCol < 0) {*turtleCol = cols - 1;}
    if (*turtleRow >= rows) {*turtleRow = 0;}
    if (*turtleRow < 0) {*turtleRow = rows - 1;}
}

void userInputProcessing(int rows, int cols, char* grid){
    char input = 0;
    int direction[3] = {0,0,0};
    int turtleRow[3] = {0, 0, 0};
    int turtleCol[3] = {0,0 ,0};
    int turtleCount = 1;
    int maxTurtleCount = 3;
    while (scanf(" %c", &input) == 1) {
        if (input == 'f' && turtleCount < maxTurtleCount) {
            turtleCount++;
        }
        else if (input == 'x') {
            gridPrint(rows, cols, grid);
            return;
        }         
        for (int i = 0; i < turtleCount; i++) {
            if (input == 'o') {
                int index = indexCalculation(turtleRow[i], turtleCol[i], cols);
                if (grid[index] == '.') {
                    grid[index] = 'o';  
                } 
                else if (grid[index] == 'o') {
                    grid[index] = '.';  
                }
            }
            else if (input == 'm') {
                moveTurtle(direction[i], &turtleCol[i], &turtleRow[i]);
                checkTurtleBoundaries(&turtleCol[i], cols, &turtleRow[i], rows);
            }
            else if (input == 'r') {
                direction[i] = (direction[i] + 1) % 4;
            }
            else if (input == 'l') {
                direction[i] = (direction[i] - 1 + 4) % 4;
            }        
        }
    }
}
    
int main(){
    int rows = 0;
    int cols = 0;
    scanf("%d %d", &rows, &cols);
    char* grid = malloc(rows * cols * sizeof(char));
    if (grid == NULL) {
        printf("Error in allocation of grid.\n");
        return 1;
    }

    gridCalculation(rows, cols, grid);
    userInputProcessing(rows, cols, grid);

    free(grid);
    return 0;
}
