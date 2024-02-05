# Anagram Checker

This simple C program reads two strings from a file, determines if they are anagrams, and outputs the result to another file. An anagram is a word or phrase formed by rearranging the letters of another, using all the original letters exactly once.

### How to Use

**Input File:**
Ensure your input file (input.txt) is correctly formatted. The program expects two strings, each on a separate line.
**Run the Program:** Compile and run the program using a C compiler. 
For example:
bash
Copy code
gcc anagram_checker.c -o anagram_checker
./anagram_checker

From here, use the following terminal inputs to properly execute the code:
 - *make clean* 
 - *make convert_input* 
 - *make run* 
 - *make convert_output*
 - *make clean*
 - *make check* 

**Check Output:** The result (whether the strings are anagrams or not) will be written to the output file (output.txt).
Functions

##### isLetter(char ch)
Determines if a character is a letter. Returns 1 if it is, 0 otherwise.

##### getLength(char str[])**
Returns the length of a character array.

##### readFile(const char *inputFileName, char **string1, char **string2)
Reads a file and populates two arrays with letters. Exits with an error message if the file cannot be opened.

##### isAnagram(char *string1, char *string2)
Checks if two strings are anagrams of each other. Anagrams are defined as strings with the same length and the same set of characters (ignoring order).

##### printMsg(char string1[], char string2[], const char *inputFileName, const char *outputFileName)
Prints a message to the output file, indicating whether the two strings are anagrams or not.

##### main()
The main entry point of the program. Reads input, checks for anagrams, and outputs the result.

## Important Notes

- Ensure the input file contains two strings, each on a separate line.
- Anagrams are case-insensitive.
- The program dynamically allocates memory for strings; freeing memory is handled at the end of the execution.
Feel free to use and modify the code according to your needs! If you encounter any issues or have suggestions for improvement, please open an issue.
