#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char* inputPath;
    char* outputPath;
    char* needle;
    bool isFlagI;
} args;

int checkFlagO(int argc, char** argv, args* arguments, bool* isFlagO, int i) {
    if (*isFlagO == true) {
        printf("Parameter -o provided multiple times\n");
        return 1;
    }
    *isFlagO = true;
    if (!(i + 1 < argc)) {
        printf("Missing output path\n");
        return 1;
    }
    arguments->outputPath = argv[i + 1];
    return 0;
}

int checkFlagI(args* arguments) {
    if (arguments->isFlagI == true) {
        printf("Parameter -i provided multiple times\n");
        return 1;
    }
    arguments->isFlagI = true;
    return 0;
}

int checkMandatoryParameters(char** argv, int* mandatoryParameters, args* arguments, int i) {
    if (*mandatoryParameters > 1) {
        printf("Too many parameters provided\n");
        return 1;
    }
    if (*mandatoryParameters == 0) {
        arguments->inputPath = argv[i];
    }
    if (*mandatoryParameters == 1) {
        arguments->needle = argv[i];
    }
    ++(*mandatoryParameters);
    return 0;
}

int checkParameters(int argc, char** argv, args* arguments, bool* isFlagO, int* mandatoryParameters) {
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-o")) {
            if (checkFlagO(argc, argv, arguments, isFlagO, i) != 0) {
                return 1;
            }
            ++i;
            continue;
        }
        if (!strcmp(argv[i], "-i")) {
            if (checkFlagI(arguments) != 0) {
                return 1;
            }
        }
        if (*argv[i] != '-') {
            if (checkMandatoryParameters(argv, mandatoryParameters, arguments, i) != 0) {
                return 1;
            }
        }
    }
    if (arguments->inputPath == NULL) {
        printf("Input path not provided\n");
        return 1;
    }
    if (arguments->needle == NULL) {
        printf("Needle not provided\n");
        return 1;
    }
    return 0;
}

void convertNeedleToLowercase(args arguments, char* lowercaseNeedle) {
    if (arguments.isFlagI) {
        for (int i = 0; arguments.needle[i] != '\0'; i++) {
        lowercaseNeedle[i] = (char)tolower(arguments.needle[i]);
        }
    }
}

void convertBufferToLowercase(int* index, char* lowercaseBuffer, char* buffer) {
    for (int i = 0; buffer[i] != '\0'; i++) {
        lowercaseBuffer[i] = (char)tolower(buffer[i]);
        *index = i;
    }
}

void outputWithIflag(args arguments, char* lowercaseBuffer, char* lowercaseNeedle, char* buffer, FILE* outputFile) {
    if (strstr(lowercaseBuffer, lowercaseNeedle) != NULL) {
        if (arguments.outputPath != NULL) {
        fprintf(outputFile, "%s", buffer);
        }
        else {
        printf("%s", buffer);
        }
    }
}

void outputWithoutIflag(args arguments, FILE* outputFile, char* buffer){
    if (arguments.outputPath != NULL) {
        fprintf(outputFile, "%s", buffer);
    }
    else {
        printf("%s", buffer);
    }
}

void output(args arguments, FILE* inputFile, FILE* outputFile){
    char buffer[101] = {0};
    char lowercaseBuffer[101] = {0};
    char lowercaseNeedle[101] = {0};
    int index = 0;
    convertNeedleToLowercase(arguments, lowercaseNeedle);
    while (fgets(buffer, 101, inputFile) != NULL) {
        if (arguments.isFlagI) {
            convertBufferToLowercase(&index, lowercaseBuffer, buffer);
            lowercaseBuffer[index + 1] = '\0';
            outputWithIflag(arguments, lowercaseBuffer, lowercaseNeedle, buffer, outputFile);
        }
        else if (strstr(buffer, arguments.needle) != NULL) {
            outputWithoutIflag(arguments, outputFile, buffer);
        }
    }
    fclose(inputFile);
    if (outputFile != NULL) {
        fclose(outputFile);
    }
}

int main(int argc, char** argv) {
    args arguments = {NULL, NULL, NULL, false};
    int mandatoryParameters = 0;
    bool isFlagO = false;
    if (checkParameters(argc, argv, &arguments, &isFlagO, &mandatoryParameters) != 0) { return 1; }
    FILE* inputFile = fopen(arguments.inputPath, "r");
    FILE* outputFile = NULL;
    if (arguments.outputPath != NULL) {
        outputFile = fopen(arguments.outputPath, "w");
    }
    output(arguments, inputFile, outputFile);
    return 0;
}