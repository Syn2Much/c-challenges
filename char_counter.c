/*
 * CHALLENGE: Character Counter
 *
 * Build a program that takes a string as a command-line argument
 * and prints a breakdown of its contents.
 *
 * Requirements:
 *   1. Count how many uppercase, lowercase, digits, and special characters are in the string.
 *      Usage: ./charcount "Hello World 123!"
 *   2. Print each count on its own line.
 *
 * Constraints:
 *   - Validate that exactly one argument is provided.
 *   - Use a loop to walk the string character by character.
 *
 * Hints:
 *   - <ctype.h> gives you isupper(), islower(), isdigit(), isalpha().
 *   - A string is just an array of chars ending with '\0'.
 *   - strlen() gives you the length to loop over.
 *
 * Expected output:
 *   $ ./charcount "Hello World 123!"
 *   Uppercase: 2
 *   Lowercase: 8
 *   Digits: 3
 *   Special: 3
 */

 #include <ctype.h>
 #include <stdio.h> 
#include <stdlib.h>
#include <string.h>

 int main (int argc, char* argv[]) {
   if((argc > 2) || argv == 0 ) {
        printf("One argument only");
        exit(0);   
 }  
    
    int count = strlen(argv[1]);
    char *word = argv[1];
    int uppercase = 0, lowercase = 0, digits = 0, special = 0;
    for(int i = 0; i < count; i++) {
        if (isupper(word[i])) {
            uppercase++;
        } else if (islower(word[i])) {
            lowercase++;
    } else if (isdigit(word[i])) {
            digits++;
 } else{
    special++;
 }}


 printf("Uppercase: %d\nLowercase: %d\nDigits: %d\nAlpha: %d\n",uppercase,lowercase,digits,special);


}
 
