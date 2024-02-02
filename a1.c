#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/**
 * @brief   Determines if parameter is a char.
 *
 * This function checks a given input character to see if it is a letter.
 *
 * @param   ch    The character to check.
 * @return  int   1 if it is a letter, 0 if it is not a letter.
 */
int isLetter(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}


/**
 * @brief   Reads a file to fill two arrays with letters.
 *
 * This function reads a given input file to populate two arrays with the letters
 *      read from said file.
 *
 * @param   inputFileName   The file that is to be read.
 * @return  char *          Character arrays.
 *
 * @note    Exits the program with an error message if the file cannot be opened.
 */
char *readFile(const char *inputFileName, char **string1, char **string2) {
    // **string1 and **string2 are double pointers: pointers to pointers to char.
    // they are used to store the addresses of the arrays we will dynamically allocate

    FILE *inputFile = fopen(inputFileName, "r");
    
    if (inputFile == NULL) {

        perror("Invalid input data. File empty or unfound.");

        fclose(inputFile);

        exit(EXIT_FAILURE);

    }

    int ch;
    int lineCount = 0;

    // size_t is a datatype in C that is used to represent the 
    // size of an array or container. 
    // It is an unsigned-integer type that is platform dependent.
    size_t size1 = 0;
    size_t size2 = 0;

    while ((ch = fgetc(inputFile)) != EOF) {

        if (ch == "\n") {
            lineCount++;

            // ignore anything beyond the second line in the file.
            if (lineCount > 1) {
                break;
            }

        // checks the character to see if it is a letter.
        } else if (isLetter(ch)) {

            //for the first line in the file.
            if (lineCount == 0) {

                // resize allocated memory to account for the character we are
                // trying to add.
                *string1 = realloc(*string1, (size1 + 1) * sizeof(char));

                if (*string1 == NULL) {
                    perror("Error reallocating memory");
                    exit(EXIT_FAILURE);
                }

                // assigning the character ch to the space at the current index
                // in the character array pointed to by string1.
                (*string1)[size1] = (char)ch;
                size1++;
            }

        } else {

            *string2 = realloc(*string2, (size2 + 1) * sizeof(char));

            if (*string2 == NULL) {
                perror("Error reallocating memory");
                exit(EXIT_FAILURE);
            }

            (*string2)[size2] = (char)ch;
            size2++;

        }
    }
    
    fclose(inputFile);
    
}


/**
 * @brief   Checks if two strings are anagrams of each other.
 *
 * This function takes two null-terminated character arrays (strings) and compares 
 *      their contents to determine if the strings are anagrams (same set of characters, 
 *      ignoring order).
 *
 * @param   string1[]   The first string to compare (null-terminated).
 * @param   string2[]   The second string to compare (null-terminated).
 * @return  int         Returns 1 if the two strings are anagrams, and 0 otherwise.
 *
 * @note    Anagrams are defined as strings with the same length and the same set 
 *              of characters (ignoring order).
 *
 * @warning The function behavior is undefined if either or both input strings 
 *              are empty.
 */
int isAnagram(char string1[], char string2[]) {

    // PSEUDO CODE FOR BASIC IDEA OF FUNCTION

    // if (string1.length == string2.length) {
    //     for (int i = 0; i < string1.length; i++) {
    //         if (string1[i] is in string2[]) {
    //             continue;
    //         } else {
    //             return 1;
    //         }
    //     }
    // } else {
    //     return 0;
    // }

    // return 1;
}


/**
 * @brief   Prints a message to the output file.
 *
 * This function acts as the "quarterback" of the program, calling on the
 *      isAnagram() method and retrieving its response and printing a message
 *      depending on whether the two strings are anagrams.
 *
 * @param   string1[]    The first string.
 * @param   string2[]    The second string.
 * @param   inputFile    The file that is to be read from.
 * @param   outputFile   The file that is to be written to.
 *
 * @return  none
 */
void printMsg(char string1[], char string2[], const char *inputFile, const char *outputFile) {

    // readFile(inputFile);

    if (isAnagram(string1, string2)) {
        fprintf("1! anagram", outputFile);
    } else {
        fprintf("0! not anagram", outputFile);
    }
}


/**
 * @brief  The main entry point of the program.
 *
 * @param   none
 * @return  int   0 if there are no errors in execution,
 *                      1 otherwise.
 */
int main()
{
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";

    // using char * rather than a fixed array allows for dynamic
    // memory allocation rather than fixed.
    char *string1 = NULL;
    char *string2 = NULL;

    printMsg(&string1, &string2, inputFile, outputFile);

    // "free" the meory allocated to our character arrays.
    free(string1);
    free(string2);
    
    return 0;

}

