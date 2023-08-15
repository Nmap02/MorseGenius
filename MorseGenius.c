#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "morsegenius_header.h"

struct MorseDictionary {
    char character;
    const char *conversion;
};

struct MorseDictionary table[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
    {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
    {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."}, {' ', "/"},
};

void clearScreen() {
    printf("\033[H\033[J");
}

void cls() {
    system("cls");
}

char* findConversion(char character) {
    for (int i = 0; i < sizeof(table) / sizeof(table[0]); i++) {
        if (table[i].character == character) {
            return strdup(table[i].conversion);
        }
    }
    return NULL;
}

char findCharacter(const char *conversion) {
    for (int i = 0; i < sizeof(table) / sizeof(table[0]); i++) {
        if (strcmp(table[i].conversion, conversion) == 0) {
            return table[i].character;
        }
    }
    return '\0';
}

char* convertToText(const char *string) {
    char *converted = (char *)malloc(strlen(string) + 1);
    if (converted == NULL) {
        printf("Memory allocation error.\n");
        return NULL;
    }

    char *ptrConverted = converted;
    const char *token = strtok(strdup(string), " \t\n\\");
    while (token != NULL) {
        char character = findCharacter(token);
        if (character != '\0') {
            *converted++ = character;
        }
        token = strtok(NULL, " \t\n\\");
    }
    *converted = '\0';

    return ptrConverted;
}

char* convertToMorse(const char *string) {
    int size = strlen(string);
    char *converted = (char *)malloc(size * 5 + 1);
    if (converted == NULL) {
        printf("Memory allocation error.\n");
        return NULL;
    }

    *converted = '\0';

    for (int i = 0; i < size; i++) {
        char character = toupper(string[i]);
        const char *conversion = findConversion(character);

        if (conversion != NULL) {
            strcat(converted, conversion);
            if (i < size - 1) {
                strcat(converted, " ");
            }
            free((char *)conversion);
        }
    }

    return converted;
}

char* readString(const char *prompt) {
    printf("%s", prompt);

    char *string = NULL;
    size_t size = 0;
    ssize_t charsRead = getline(&string, &size, stdin);

    if (charsRead == -1) {
        printf("Error reading input.\n");
        free(string);
        return NULL;
    }

    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }

    return string;
}

void convertMorseToText() {
    char *morseString = readString("[\033[1m\033[33m!\033[0m] Enter the morse code: ");
    if (morseString != NULL) {
        char *text = convertToText(morseString);
        printf("[\033[1m\033[33m!\033[0m] Converted text: %s\n", text);
        free(morseString);
        free(text);
    }
}

void convertTextToMorse() {
    char *textString = readString("[\033[1m\033[33m!\033[0m] Enter the text: ");
    if (textString != NULL) {
        char *morse = convertToMorse(textString);
        printf("[\033[1m\033[33m!\033[0m] Converted morse code: %s\n", morse);
        free(textString);
        free(morse);
    }
}

void processMorseFileToTextFile() {
    char inputFileName[100];
    char outputFileName[100];

    printf("[\033[32m?\033[0m] Input file name: ");
    fgets(inputFileName, sizeof(inputFileName), stdin);
    inputFileName[strcspn(inputFileName, "\n")] = '\0';

    printf("[\033[32m?\033[0m] Output file name: ");
    fgets(outputFileName, sizeof(outputFileName), stdin);
    outputFileName[strcspn(outputFileName, "\n")] = '\0';

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return;
    }

    char *row = NULL;
    size_t size = 0;
    ssize_t charsRead;

    while ((charsRead = getline(&row, &size, inputFile)) != -1) {
        if (row[charsRead - 1] == '\n') {
            row[charsRead - 1] = '\0';
        }

        char *convertedContent = convertToText(row);
        fprintf(outputFile, "%s\n", convertedContent);
        free(convertedContent);
    }

	printf("[\033[1m\033[33m!\033[0m] File successfully generated!\n");

    free(row);
    fclose(inputFile);
    fclose(outputFile);
}

void processTextFileToMorseFile() {
    char inputFileName[100];
    char outputFileName[100];

    printf("[\033[32m?\033[0m] Input file name: ");
    fgets(inputFileName, sizeof(inputFileName), stdin);
    inputFileName[strcspn(inputFileName, "\n")] = '\0';

    printf("[\033[32m?\033[0m] Output file name: ");
    fgets(outputFileName, sizeof(outputFileName), stdin);
    outputFileName[strcspn(outputFileName, "\n")] = '\0';

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return;
    }

    char *row = NULL;
    size_t size = 0;
    ssize_t charsRead;

    while ((charsRead = getline(&row, &size, inputFile)) != -1) {
        if (row[charsRead - 1] == '\n') {
            row[charsRead - 1] = '\0';
        }

        char *convertedContent = convertToMorse(row);
        fprintf(outputFile, "%s\n", convertedContent);
        free(convertedContent);
    }

	printf("\n[\033[1m\033[33m!\033[0m] File successfully generated!\n");

    free(row);
    fclose(inputFile);
    fclose(outputFile);
}

int main() {
	clearScreen();
	cls();
	header();
	char option;

    do {
        printf("\n");
        printf("[\033[32m1\033[0m] Morse -> Text\n");
        printf("[\033[32m2\033[0m] Morse File -> Text File\n");
        printf("[\033[32m3\033[0m] Text -> Morse\n");
        printf("[\033[32m4\033[0m] Text File -> Morse File\n");
        printf("[\033[32m0\033[0m] Exit\n");

        printf("\n[\033[32m?\033[0m] Choose an option: ");
        scanf(" %c", &option);
        getchar();

        switch (option) {
            case '1':
                convertMorseToText();
                break;
            case '2':
                processMorseFileToTextFile();
                break;
            case '3':
                convertTextToMorse();
                break;
            case '4':
                processTextFileToMorseFile();
                break;
            case '0':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please choose a valid option.\n");
        }

    } while (option != '0');

    return 0;
}
