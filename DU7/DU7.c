#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int day;
    char* stockName;
    float startingPrice;
    float finalPrice;
    int tradesCount;
} stockInformation;

void reverseOutputValueString(int outputPosition, char* outputValue){
    for (int i = 0; i < outputPosition / 2; i++) {
        char temp = outputValue[i];
        outputValue[i] = outputValue[outputPosition - 1 - i];
        outputValue[outputPosition - 1 - i] = temp;
    }
}

void underscoresForTradesCount(stockInformation* stockInformationArray, int index){
    char inputValue[13];
    char outputValue[20];
    int outputPosition = 0;
    snprintf(inputValue, sizeof(inputValue), "%d", stockInformationArray[index].tradesCount);
    int length = strlen(inputValue);
    for (int i = length - 1, positionFromEnd = 0; i >= 0; i--, positionFromEnd++) {
        if (positionFromEnd > 0 && positionFromEnd % 3 == 0) {
            outputValue[outputPosition] = '_';
            ++outputPosition;
        }
        outputValue[outputPosition] = inputValue[i];
        ++outputPosition;
    }
    outputValue[outputPosition] = '\0';
    reverseOutputValueString(outputPosition, outputValue);
    printf("%s", outputValue);
}

void printStocks(stockInformation* stockInformationArray, int rowCount, char* stockName){
    int index = rowCount - 1;
    while (index >= 0) {
        if (strcmp(stockInformationArray[index].stockName, stockName) == 0){
            printf("<tr>\n");
            printf("\t<td><b>%d</b></td>\n", stockInformationArray[index].day);
            printf("\t<td><b>%s</b></td>\n", stockInformationArray[index].stockName);
            printf("\t<td><b>%.2f</b></td>\n", stockInformationArray[index].startingPrice);
            printf("\t<td><b>%.2f</b></td>\n", stockInformationArray[index].finalPrice);
            float differenceResult = stockInformationArray[index].finalPrice - stockInformationArray[index].startingPrice;
            printf("\t<td><b>%.2f</b></td>\n", differenceResult);
            printf("\t<td><b>");
            underscoresForTradesCount(stockInformationArray, index);
            printf("</b></td>\n");
            printf("</tr>\n");
        }
        else {
            printf("<tr>\n");
            printf("\t<td>%d</td>\n", stockInformationArray[index].day);
            printf("\t<td>%s</td>\n", stockInformationArray[index].stockName);
            printf("\t<td>%.2f</td>\n", stockInformationArray[index].startingPrice);
            printf("\t<td>%.2f</td>\n", stockInformationArray[index].finalPrice);
            float differenceResult = stockInformationArray[index].finalPrice - stockInformationArray[index].startingPrice;
            printf("\t<td>%.2f</td>\n", differenceResult);
            printf("\t<td>");
            underscoresForTradesCount(stockInformationArray, index);
            printf("</td>\n");
            printf("</tr>\n");
        }
        index--;
    }
}

void checkTicker(stockInformation* stockInformationArray, char* stockName, int index){
    bool highestTradeCountFound = (index != -1);
    if (highestTradeCountFound) {
        printf("<h1>%s: highest volume</h1>\n", stockName);
        printf("<div>Day: %d</div>\n", stockInformationArray[index].day);
        printf("<div>Start price: %.2f</div>\n", stockInformationArray[index].startingPrice);
        printf("<div>End price: %.2f</div>\n", stockInformationArray[index].finalPrice);
        printf("<div>Volume: ");
        underscoresForTradesCount(stockInformationArray, index);
        printf("</div>\n");
    }
    else {
        printf("Ticker %s was not found\n", stockName);
    }
}

void HTMLOutput(stockInformation* stockInformationArray, int rowCount, char* stockName, int index){
    printf("<html>\n");
    printf("<body>\n");
    printf("<div>\n");
    checkTicker(stockInformationArray, stockName, index);
    printf("</div>\n");
    printf("<table>\n");
    printf("<thead>\n");
    printf("<tr><th>Day</th><th>Ticker</th><th>Start</th><th>End</th><th>Diff</th><th>Volume</th></tr>\n");
    printf("</thead>\n");
    printf("<tbody>\n");
    printStocks(stockInformationArray, rowCount, stockName);
    printf("</tbody>\n");
    printf("</table>\n");
    printf("</body>\n");
    printf("</html>\n");
}

int highestTradesCount(stockInformation* stockInformationArray, int rowCount, char* stockName){
    int index = -1;
    int maxTradersCount = 0;
    for (int i = 0; i < rowCount; i++) {
        if (strcmp(stockName, stockInformationArray[i].stockName) == 0) {
            if (stockInformationArray[i].tradesCount > maxTradersCount) {
                maxTradersCount = stockInformationArray[i].tradesCount;
                index = i;
            }
        }
    }
    return  index;
}

void fillStockInformation(int token, stockInformation* stockInformationArray, char* input, int start, int index){
    switch (token) {
        case 0: 
            stockInformationArray[index].day = atoi(&input[start]);
        break;
        case 1: 
            stockInformationArray[index].stockName = malloc((strlen(&input[start]) + 1) * sizeof(char));
            strcpy(stockInformationArray[index].stockName, &input[start]);
        break;
        case 2: 
            stockInformationArray[index].startingPrice = atof(&input[start]);
        break;
        case 3: 
            stockInformationArray[index].finalPrice = atof(&input[start]);
        break;
        case 4: 
            stockInformationArray[index].tradesCount = atoi(&input[start]);
        break;
    }
}

void sortStock(char separator, char* input, stockInformation* stockInformationArray, int index){
    int start = 0;
    int token = 0;
    for (int i = 0; input[i] != '\0'; i++) {   
        if (input[i] == separator) {
            input[i] = '\0';
            fillStockInformation(token, stockInformationArray, input, start, index);
            start = i + 1;
            ++token;
        }
    }
    if (input[start] != '\0') {
    fillStockInformation(token, stockInformationArray, input, start, index);
    }
}

void stockInformationSeparation(char* stockName, int rowCount, stockInformation* stockInformationArray){
    for (int i = 0; i < rowCount; i++) {
        char input[101] = {0};
        fgets(input, 101, stdin);
        input[strcspn(input, "\n")] = '\0';
        sortStock(',', input, stockInformationArray, i);
    }
}

int main(int argc, char** argv){
    if (argc != 3) {
        printf("Wrong parameters\n");
        return 1; 
    }
    char* stockName = argv[1];
    char* inputRowCount = argv[2];
    int rowCount = atoi(inputRowCount);
    stockInformation* stockInformationArray = malloc(rowCount * sizeof(stockInformation));
    stockInformationSeparation(stockName, rowCount, stockInformationArray);
    int index = highestTradesCount(stockInformationArray, rowCount, stockName);
    HTMLOutput(stockInformationArray, rowCount, stockName, index);
    for (int i = 0; i < rowCount; i++) {
        free(stockInformationArray[i].stockName);
    }
    free(stockInformationArray);
    return 0;
}