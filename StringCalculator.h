#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isStringEmpty(const char* input) {
    if (strcmp(input, "") == 0 || strcmp(input, "0") == 0) {
        return 1;
    } else {
        return 0;
    }
}
int isValidNumber(const char* token) {
    char* endptr;
    long num = strtol(token, &endptr, 10);
    if (*endptr != '\0') {
        return 0;
    }
    if (num < 0) {
        return -1;
    }
    return (num <= 1000);
}
int calculateSum(const char* input) {
    int sum = 0;
    char* token;
    char* delimiter = ", \n//;";
    char* inputCopy = strdup(input); // create a copy of the input string
    token = strtok(inputCopy, delimiter);
    while (token != NULL) {
        if (isValidNumber(token)) {
            sum += atoi(token);
        }
        token = strtok(NULL, delimiter);\
    }
    free(inputCopy); // free the memory allocated for the copy of the input string
    return sum;
}
int add(const char* input) {
    if (isStringEmpty(input)) {
        return 0;
    }
    return calculateSum(input);
}
has context menu
