#include <stdio.h>
#include <stdlib.h>

void histogramCalculation(int* histogram, unsigned int numbersQuantity, unsigned int numbersRange){
    unsigned int number = 0;
    for (int i = 0; i < numbersQuantity; i++) {
        scanf("%d", &number);
        if (number >= numbersRange && number <= numbersRange + 8) {
            int offset = number - numbersRange;
            histogram[offset]++; 
        }
        else {
            histogram[9]++;
        }
    }
}

int highestNumberOfCalculation(int numbersRange){
    unsigned int highestValue = numbersRange + 8;
    unsigned int numberOfSpacesOfTheHighestNumber = 0;
    while (highestValue > 0) {
        highestValue = highestValue / 10;
        numberOfSpacesOfTheHighestNumber = numberOfSpacesOfTheHighestNumber + 1;
    }
    return numberOfSpacesOfTheHighestNumber;
}

void printHorizontalHistogram(int* histogram, int numbersRange){
    int highestNumber = highestNumberOfCalculation(numbersRange);
    unsigned int currentValue = 0;
    unsigned int currentNumberOfSpaces = 0;
    for (int i = 0; i < 9; i++) {
        currentValue = numbersRange + i;
        unsigned int numberOfDigits = 0;
            unsigned int tempNumberOfDigits = currentValue;
            if (tempNumberOfDigits == 0) {
                numberOfDigits = 1;
            } 
            else {
                while (tempNumberOfDigits > 0) {
                tempNumberOfDigits = tempNumberOfDigits / 10;
                numberOfDigits++;
                }
            }
        unsigned int numberOfSpaces = highestNumber - numberOfDigits;
        for (int k = 0; k < numberOfSpaces; k++) {
            printf(" ");
        }
        printf("%d", currentValue);
        if (histogram[i] > 0) {
            printf(" ");
            for (int j = 0; j < histogram[i]; j++){
                printf("#");
            }
        }
        printf("\n");
    }
    if (histogram[9] > 0) {
        printf("invalid:");
        printf(" ");
        for (int j = 0; j < histogram[9]; j++){
            printf("#");
        }
    }
    printf("\n");
}

void horizontalOrVerticalMode(int* histogram,char histogramType, int numbersRange){
    if (histogramType == 'h' || histogramType == 'H') {
        printHorizontalHistogram(histogram, numbersRange);
    } 
    else if (histogramType == 'v' || histogramType == 'V') {
        printf("Sorry, ten jsem tentokrát nestíhal. See ya!\n");
    }
    else {
        printf("Neplatný mód vykreslení!\n");
    }
}

int main(){

    int histogram[10] = {0};
    unsigned int numbersQuantity = 0;
    unsigned int numbersRange = 0;
    char histogramType;
    scanf(" %c", &histogramType); 
    scanf("%u", &numbersQuantity);
    scanf("%u", &numbersRange);
    histogramCalculation(histogram, numbersQuantity, numbersRange);
    horizontalOrVerticalMode(histogram, histogramType, numbersRange);
    
    return 0;
}