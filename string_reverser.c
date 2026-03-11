/*
 * CHALLENGE: String Reverser
 *
 * Build a program that reverses a string in-place without using any library functions.
 *
 * Requirements:
 *   1. Accept a string as a command-line argument.
 *      Usage: ./reverse "hello world"
 *   2. Reverse the string and print it.
 *
 * Constraints:
 *   - Don't use strrev(), or any string library function for the reversal.
 *   - Reverse it manually using a loop and character swapping.
 *   - Work on a copy of argv[1], not the original.
 *
 * Hints:
 *   - You only need to loop halfway through the string.
 *   - Swapping two values needs a temp variable (or the XOR trick if you're feeling spicy).
 *   - malloc() + strcpy() to make a mutable copy, or use a local array with strlen().
 *
 * Expected output:
 *   $ ./reverse "hello world"
 *   dlrow olleh
 *
 * Bonus:
 *   - Reverse word order instead of characters: "hello world" → "world hello"
 *   - Handle multiple arguments: reverse each one and print on separate lines.
 */

int str_len(const char *s);
void str_copy(char *dst, const char *src);
void reverse_in_place(char *s);
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>

 int main(int argc, char* argv[]){
    if (argc < 2) {
        printf("Command Line Arguments Required");
        exit(1);
    }
    if(argv[1][0] == '-') {
        printf("No Numbers Allowed Even Negative!");
         exit(200);
    }
    if (isdigit(*argv[1])) {
        printf("No Numbers Allowed");
        exit(200);
    }
    char *strptr = argv[1];
    char output[200] = {0};
  
    printf("%d\n", str_len(strptr));
    str_copy(output, strptr);
    printf("%d\n", str_len(output));

    reverse_in_place(output);
    printf("%s",output);
 }

int str_len(const char *s) {
    int len = 0;
     while (s[len] != '\0') {
        len++;
    }
    return len;
}

void str_copy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

void reverse_in_place(char *s) {
    int len = str_len(s);
    char temp;
    for(int i = 0; i < len / 2; i++) {
        temp = s[len-1-i];
        s[len-i] = s[i];
        s[i] = temp;
    }
}
