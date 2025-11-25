#include <stdio.h>

//0:
//vzkresluje vyplněný obdélník
void draw_filled_rectangle(int x, int y) { 
    for (int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++){
            printf("x");
        }
        printf("\n");
    }
}
//1:
//vzkresluje dutý obdélník
void draw_hollow_rectangle(int x, int y) { 
for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++){
            if (i == 0 || i == y - 1 || j == 0 || j == x - 1){
                printf("x");}
            else {
                printf(" ");}
        }
        printf("\n");
    }
}
//2:
//vykresluje obdélník vyplněný čísly, jejiž hodnota horizontálně vzrůstá
void draw_rectangle_filled_with_numbers_horizontally(int x, int y){ 
    int numbers = 0;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++){
            if (i == 0 || i == y - 1 || j == 0 || j == x - 1){
                printf("x");}
            else{
                    
                    if (numbers < 10){
                        printf("%d",numbers);
                        numbers += 1;
                    }
                    else {
                        numbers = 0;
                        printf("%d",numbers);
                        numbers += 1;
                    }
                }  
        }
        printf("\n");
    }
}
//3:
//vykresluje blackslash linii
void draw_backslash_line(int x){ 
    for (int i = 0; i < x; i++){
        for (int j = 0; j < i; j++) {
           printf(" ");
        }
        printf("x\n");
    }
}
//4:
//vykresluje slash linii
void draw_slash_line(int x){ 
    int originalValue = x;
    for (int i = 0; i < originalValue; i++){
        x -= 1;
        for (int j = x; j > 0; j--) {
            printf(" ");
        }
        printf("x\n");
    }
}
//5:
//vykresluje dutý trojúhelník
void draw_triangle(int x){ 
    x -= 1;
    int originalValue = x;
    for (int i = 0; i < originalValue; i++){
        x -= 1;
        //odsazení zleva
        for (int j = x + 1; j > 0; j--) { 
            printf(" ");
        }
        //print levé strany
        printf("x");
        //vyplnění trojúhelníku
        if (i >= 1) { 
            for (int k = 1; k < originalValue - x; k++) {
                printf(" ");
                if (k > 1) {
                    printf(" ");
                }
            }
            //print pravé strany
            printf("x");
        }
        printf("\n");
    }
    //vypsání posledního řádku
    for (int i = 0; i < 2 * originalValue + 1; i++) { 
        printf( "x");
    }
        printf("\n");
}
//6:
//vykresluje písmeno T
void draw_t(int x, int y){ 
    for (int i = 0; i < x; i++) {
        printf("x");
    }
    printf("\n");
    for (int i = 0; i < y - 1; i++) {
        for (int j = 0; j < x / 2; j++) {
                printf(" ");
            }
        printf("x\n");
    }   
}
//7:
//vykresluje písmeno P
void draw_p(int x, int y){
    //vrch hlavy P
    for (int i = 0; i < x; i++) {
        printf("x");
    }
    printf("\n");
    //střed hlavy P
    int sizeOfPHead = (y / 2) - 1;
    int holeSizeInsideP = x - 2;
    for (int i = 0; i < sizeOfPHead; i++) {
        printf("x");
        for (int j = 0; j < holeSizeInsideP; j++) {
        printf(" ");
        }
        printf("x\n");
    }
    //spodek hlavy P
    for (int i = 0; i < x; i++) {
        printf("x");
    }
    printf("\n");
    //tvorba nožičky
    int heightOfPLeg = y - sizeOfPHead - 2;
    for (int i = 0; i < heightOfPLeg; i++) {
        printf("x\n");
    }
}
//9 (BONUS):
//vykresluje obdélník vyplněný čísly, jejiž hodnota vertikálně vzrůstá
void draw_rectangle_filled_with_numbers_vertically(int x, int y){
    int rows = 0; //číslo řádku
    int numbers = 0; //print čísla ve sloupci
    //první řádek
    for (int i = 0; i < x; i++) {
        printf("x");
    }
    //střed s čísly
    printf("\n");
    for (int i = 0; i < y - 2; i++) {
        printf("x");
        numbers = rows;
        //print čísel v řádku
        for (int j = 0; j < x -2; j++) {
             if (numbers >= 10) {
                numbers %= 10;
            }
             if (rows >= 10) {
                rows %= 10;
            }
            printf("%d",numbers);
            numbers += y - 2;
        }
        rows++;
        printf("x\n");
    }
    //poslední řádek
    for (int i = 0; i < x; i++) {printf("x");}
    printf("\n");
}


int main() {
    int obrazec = 0;
    int a = 0;
    int b = 0;
    scanf("%d%d%d", &obrazec, &a, &b);

    int shape = obrazec; //typ obrazce
    int x = a; //výška
    int y = b; //šířka

    switch (shape) {
        case 0:
            draw_filled_rectangle(x, y);
            break;
        case 1:
            draw_hollow_rectangle(x, y);
            break;
        case 2:
            draw_rectangle_filled_with_numbers_horizontally(x, y);
            break;
        case 3:
            draw_backslash_line(x);
            break;
        case 4:
            draw_slash_line(x);
            break;
        case 5:
            draw_triangle(x);
            break;
        case 6:
            draw_t(x, y);
            break;
        case 7:
            draw_p(x, y);
            break;
        case 9:
            draw_rectangle_filled_with_numbers_vertically(x, y);
            break;
        default:
            printf("Neznamy obrazec\n");
            break;
    }
    return 0;
}