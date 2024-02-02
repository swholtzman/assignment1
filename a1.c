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
 * read from said file.
 *
 * @param   inputFileName   The file that is to be read.
 * @return  char *          Character arrays.
 *
 * @note    Exits the program with an error message if the file cannot be opened.
 */
char *readFile(const char *inputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    
    if (inputFile == NULL) {

        perror(stderr, "Invalid input data. File empty or unfound.");
        exit(EXIT_FAILURE);

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

    // PSEUDO CODE FOR BASIC IDEA

    // if (string1.length == string2.length) {
    //     for (int i = 0; i < string1.length; i++) {
    //         if (string1[i] is in string2[]) {
    //             continue;
    //         } else {
    //             return;
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
 * isAnagram() method and retrieving its response and printing a message
 * depending on whether the two strings are anagrams.
 *
 * @param   string1[]    The first string.
 * @param   string2[]    The second string.
 * @param   inputFile    The file that is to be read from.
 * @param   outputFile   The file that is to be written to.
 *
 * @return  none
 */
void printMsg(char string1[], char string2[], const char *inputFile, const char *outputFile) {

    readFile(inputFile);

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
 *                      1 otherwise
 */
int main()
{
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";

    char string1[1000]; //just to avoid errors during production
    char string2[1000]; //just to avoid errors during production

    printMsg(string1, string2, inputFile, outputFile);

    return 0;

}

