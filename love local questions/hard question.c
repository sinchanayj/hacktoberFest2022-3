#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to compute the longest prefix that is also a suffix (LPS) array
void computeLPS(char *pattern, int *lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < strlen(pattern)) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to find the shortest palindrome by adding characters in front
char *shortestPalindrome(char *s) {
    // Concatenate the string with a separator and its reverse
    char *concatenated = malloc((2 * strlen(s) + 2) * sizeof(char));
    sprintf(concatenated, "%s#%s", s, strdup(s));
    reverseString(concatenated);

    int n = strlen(concatenated);
    int *lps = (int *)malloc(n * sizeof(int));
    computeLPS(concatenated, lps);

    // Length of the palindrome part
    int palindromeLength = lps[n - 1];

    // Length of characters to be added in front
    int charactersToAdd = strlen(s) - palindromeLength;

    // Create the result string
    char *result = malloc((charactersToAdd + strlen(s) + 1) * sizeof(char));
    sprintf(result, "%.*s%s", charactersToAdd, s + palindromeLength, s);

    free(lps);
    free(concatenated);

    return result;
}

int main() {
    char s[50000]; // Assuming the maximum length of the string is 50000

    // Read the string
    printf("Enter the string: ");
    scanf("%s", s);

    char *result = shortestPalindrome(s);

    printf("Shortest palindrome by adding characters in front: %s\n", result);

    free(result);

    return 0;
}
