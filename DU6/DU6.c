#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void countChars(char* inputRow, int* pLowercase, int* pUppercase, int* pSpaces) {
    *pLowercase = 0;
    *pUppercase = 0;
    *pSpaces = 0;
    for (int i = 0; inputRow[i] != '\0'; i++) {
        if (islower(inputRow[i])){
            (*pLowercase)++;
        }    
        if (isupper(inputRow[i])){
            (*pUppercase)++;
        }
        if (inputRow[i] == ' '){
            (*pSpaces)++;
        }
    }
}
void normalizeWord(char* inputWord, char* outputNormalizedWord) {
    if (inputWord[0] == '\0') {
        outputNormalizedWord[0] = '\0';
        return;
    }
    bool isUpper = false;
    for (int i = 0; inputWord[i] != '\0'; i++) {
        if (isupper(inputWord[i])) {
            isUpper = true;
        }
    }
    int outputPosition = 0;
    for (int i = 0; inputWord[i] != '\0'; i++) {
        char currentChar = inputWord[i];
        if (isUpper == true) {
            if (i == 0) {
                currentChar = (char)toupper((unsigned char)inputWord[i]);
            }
            else {
                currentChar = (char)tolower((unsigned char)inputWord[i]);
            }
        }
        else {
            currentChar = (char)toupper((unsigned)currentChar);
        }
        if (toupper(inputWord[i]) == tolower(inputWord[i + 1]) || tolower(inputWord[i]) == toupper(inputWord[i + 1])) {
            if (outputPosition == 0 || tolower(currentChar) != tolower(outputNormalizedWord[outputPosition - 1])) {
                outputNormalizedWord[outputPosition] = currentChar;
                outputPosition++;
            }
        }
        else if (outputPosition == 0 || currentChar != outputNormalizedWord[outputPosition - 1]) {
                outputNormalizedWord[outputPosition] = currentChar;
                outputPosition++;
        }
        else {continue;}
    }
    outputNormalizedWord[outputPosition] = '\0';
}
void normalizeRow(char* inputRow, char* outputNormalizedRow) {
    char currentWord[52];
    char normalizedWord[52];
    int wordIndex = 0;
    int outputIndex = 0;
    size_t inputLength = strlen(inputRow);
    for (size_t i = 0; i <= inputLength; i++) {
        if (inputRow[i] != ' ' && inputRow[i] != '\0') {
            currentWord[wordIndex] = inputRow[i];
            wordIndex++;
        }    
        else if(wordIndex > 0){
            currentWord[wordIndex] = '\0';
            normalizeWord(currentWord, normalizedWord);
            if (outputIndex > 0 && normalizedWord[0] != '\0') {
                outputNormalizedRow[outputIndex++] = ' ';
            }
            for (int j = 0; normalizedWord[j] != '\0'; j++) {
            outputNormalizedRow[outputIndex++] = normalizedWord[j];
            }
            wordIndex = 0;
        }    
    }
    outputNormalizedRow[outputIndex] = '\0';
    if (outputIndex > 0 && outputNormalizedRow[outputIndex - 1] == ' ') {
        outputNormalizedRow[outputIndex - 1] = '\0';
    }
}
void printRowStatistics(int preLower, int postLower, int preUpper, int postUpper, int preSpace, int postSpace, bool isLastRow) {
    printf("lowercase: %d -> %d\n", preLower, postLower);
    printf("uppercase: %d -> %d\n", preUpper, postUpper);
    printf("spaces: %d -> %d\n", preSpace, postSpace);
    if (!isLastRow) {
        printf("\n");
    }
}
void processInput(int numberOfRows, char* inputRow, char* outputRow) {
    for (int i = 0; i < numberOfRows; i++) {
        if (fgets(inputRow, 52, stdin) == NULL) {
            break; 
        }
        inputRow[strcspn(inputRow, "\n")] = '\0';
        int preLower = 0;
        int preUpper = 0;
        int preSpace = 0;
        int postLower = 0;
        int postUpper = 0;
        int postSpace = 0;
        countChars(inputRow, &preLower, &preUpper, &preSpace);
        normalizeRow(inputRow, outputRow);
        countChars(outputRow, &postLower, &postUpper, &postSpace);
        printf("%s\n", outputRow);
        bool isLastRow = (i == numberOfRows - 1);
        printRowStatistics(preLower, postLower, preUpper, postUpper, preSpace, postSpace, isLastRow);
    }
}
int main(){
    char inputRow[52] = {0};
    char outputRow[52] = {0};
    fgets(inputRow, 52, stdin);
    int numberOfRows = atoi(inputRow);
    processInput(numberOfRows, inputRow, outputRow);
    return 0;
}
