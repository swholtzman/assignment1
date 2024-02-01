#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isLetter(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

char *readFile(const char *inputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    
    if (inputFile == NULL) {

        perror(stderr, "Invalid input data. File empty or unfound.");
        exit(EXIT_FAILURE);

    }
    

    fclose(inputFile);

    return result;
}

int main()
{
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";

    return 0;

}

