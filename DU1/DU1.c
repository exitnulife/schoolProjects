#include <stdio.h>
int main() {
    int value = 32333; //vstupní hodnota
    double x = value;

    //A5 = finální hodnota dělení "x" a hodnoty bankovky 5000
    //B2 =  finální hodnota dělení "x" a hodnoty bankovky 2000
    //C1, D5, E2, F1.....
    
     //5000
    double A5 = x / 5000;
    int pocet5000x = 0;
    while (A5 >= 1)
    {
        x = x - 5000;
        pocet5000x++;
        A5 = A5 - 1;
    }
    //2000
    double B2 = x / 2000; 
    int pocet2000x = 0;
    while (B2 >= 1)
    {
        x = x - 2000;
        pocet2000x++;
        B2 = B2 - 1;
    }
    //1000
    double C1 = x / 1000; 
    int pocet1000x = 0;
    while (C1 >= 1)
    {
        x = x - 1000;
        pocet1000x++;
        C1 = C1 - 1;
    }
    //500
    double D5 = x / 500;
    int pocet500x = 0;
    while (D5 >= 1)
    {
        x = x - 500;
        pocet500x++;
        D5 = D5 - 1;
    }
    //200
    double E2 = x / 200;
    int pocet200x = 0;
    while (E2 >= 1)
    {
        x = x - 200;
        pocet200x++;
        E2 = E2 - 1;
    }
    //100
    double F1 = x / 100;
    int pocet100x = 0;
    while (F1 >= 1)
    {
        x = x - 100;
        pocet100x++;
        F1 = F1 - 1;
    }

    printf("%s ", "Bankovka 5000:");
    printf("%d \n", pocet5000x);
    printf("%s ", "Bankovka 2000:");
    printf("%d \n", pocet2000x);
    printf("%s ", "Bankovka 1000:");
    printf("%d \n", pocet1000x);
    printf("%s ", "Bankovka 500:");
    printf("%d \n", pocet500x);
    printf("%s ", "Bankovka 200:");
    printf("%d \n", pocet200x);
    printf("%s ", "Bankovka 100:");
    printf("%d \n", pocet100x);
    
    return 0;
}