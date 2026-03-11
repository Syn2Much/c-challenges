/*
 * CHALLENGE: Random Password Generator
 *
 * Build a program that generates a random password from a set of allowed characters.
 *
 * Requirements:
 *   1. Define a character set containing lowercase, uppercase, and digits.
 *   2. Generate a 20-character password by randomly picking from that set.
 *   3. Print the final password as a single string.
 *
 * Constraints:
 *   - Seed the RNG so the output differs between runs.
 *   - Don't index out of bounds on the character array.
 *   - Null-terminate the result so it prints cleanly with %s.
 *
 * Bonus:
 *   - Accept password length as a command-line argument.
 *   - Add special characters to the charset.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]) {

   
    char *endptr;
    long val = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0' || val <= 0){
        printf("Usage: ./pwgen <count>\n");
    exit(1);
    }
    if (argc > 2) {
        printf("Usage: ./pwgen <count>\n");
    exit(1);
    }

    for (int f = 0; f < argc; f++) {
        printf("argv[%d]: %s\n",f, argv[f]);
    }

    char allowed_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789#S@-=!";
    char password[val + 1];
    size_t charset_len = strlen(allowed_characters);
    srand((unsigned int) time(NULL));
   
    for (int i = 0; i < val; i++) {
        password[i] = allowed_characters[rand() % charset_len];
      
    }
    password[val] = '\0';

    printf("Your Passowrd is %s\n", password);
    printf("%s", argv[1]);
}
