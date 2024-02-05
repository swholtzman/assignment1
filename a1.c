#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Student Numbers for Assignment Participants:
 * Sam Holtzman - A01308106
 * Isaac Lauzon - A
 * Aathavan Sriharan - A
 * Ranveer Rai - A
*/

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
 * @brief   Gets the size of a character array.
 *
 * Takes a character array as input and iterates through it to find its length.
 *
 * @param   str[]   The character array we wish to count.
 * @return  size_t  The size of the input array as a size_t datatype.
 */
size_t getLength(char str[])
{
    size_t lengthStr = 0;
    while (str[lengthStr] != '\0')
    {
        lengthStr++;
    }

    return lengthStr;
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
void readFile(const char *inputFileName, char **string1, char **string2)
{
    // **string1 and **string2 are double pointers: pointers to pointers to char.
    // they are used to store the addresses of the arrays we will dynamically allocate

    FILE *inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL)
    {

        perror("Error");

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

    while ((ch = fgetc(inputFile)) != EOF)
    {

        if (ch == '\n')
        {
            lineCount++;

            
        }
        // checks the character to see if it is a letter.
        else if (isLetter(ch))
        {

            // for the first line in the file.
            if (lineCount == 0)
            {

                // resize allocated memory to account for the character we are
                // trying to add.
                *string1 = realloc(*string1, (size1 + 1) * sizeof(char));

                if (*string1 == NULL)
                {
                    perror("Error");
                    exit(EXIT_FAILURE);
                }

                // assigning the character ch to the space at the current index
                // in the character array pointed to by string1.
                (*string1)[size1] = (char)ch;
                size1++;
            }

            else if (lineCount == 1)
            {

                *string2 = realloc(*string2, (size2 + 1) * sizeof(char));

                if (*string2 == NULL)
                {
                    perror("Error");
                    exit(EXIT_FAILURE);
                }

                (*string2)[size2] = (char)ch;
                size2++;
            }
        }
    }

    // make space for an extra character at the end of each array
    *string1 = realloc(*string1, (size1 + 1) * sizeof(char));
    *string2 = realloc(*string2, (size2 + 1) * sizeof(char));

    // make sure theres something in each array
    if (*string1 == NULL || *string2 == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    // add a NULL-terminator to the end of each character array
    (*string1)[size1] = '\0';
    // printf("string1: %s\n", *string1);

    (*string2)[size2] = '\0';
    // printf("string2: %s\n", *string2);

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
int isAnagram(char *string1, char *string2)
{

    int letterCount[26] = {0};

    // get the length of each character array
    size_t length1 = getLength(string1);
    size_t length2 = getLength(string2);

    // ensure they are the same length, meaning they have the same number of characters
    // if one has a different number of characters, it cannot be an anagram
    if (length1 == length2)
    {

        // count occurences of each letter in the string1 character array
        for (int i = 0; i < length1; ++i)
        {
            // make the character lowercase for easier comparison
            char ch = tolower(string1[i]);

            if (isLetter(ch))
            {
                // find the index of the character in the alphabet
                int index = ch - 'a';

                // increment the count for the found letter
                letterCount[index]++;
            }
        }

        for (int i = 0; i < length1; ++i)
        {
            char ch = tolower(string2[i]);

            if (isLetter(ch))
            {

                int index = ch - 'a';

                // subtract the found letter from the letterCount array.
                letterCount[index]--;
            }
        }

        // if letterCount comes out as a 0 value, that means both strings contained
        // the same amount of identical characters and are anagrams.
        for (int i = 0; i < 26; ++i)
        {

            if (letterCount[i] != 0)
            {
                // not an aanagram
                return 0;
            }
        }

        // an anagram
        return 1;
    }

    // different lengths, not an anagram
    return 0;
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
void printMsg(char string1[], char string2[], const char *inputFileName, const char *outputFileName)
{

    // open necessary file for program usage
    FILE *outputFile = fopen(outputFileName, "w");

    // error handling for invalid output file
    if (outputFile == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    // if the two strings are anagrams, print to the file that they are
    // if not, print to the file that they are not.
    if (isAnagram(string1, string2))
    {
        fprintf(outputFile, "1! anagram");
    }

    else
    {
        fprintf(outputFile, "0! not anagram");
    }

    // close file locally where they were opened
    fclose(outputFile);
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

    readFile(inputFile, &string1, &string2);
    printMsg(string1, string2, inputFile, outputFile);

    // "free" the meory allocated to our character arrays.
    free(string1);
    free(string2);

    return 0;
}
