#include <stdio.h>
#include <string.h>

int lengthOfLastWord(const char *s) {
    // Find the last non-space character in the string
    int len = strlen(s);
    int lastCharIndex = len - 1;
    while (lastCharIndex >= 0 && s[lastCharIndex] == ' ') {
        lastCharIndex--;
    }

    // Find the length of the last word
    int lastWordLength = 0;
    while (lastCharIndex >= 0 && s[lastCharIndex] != ' ') {
        lastWordLength++;
        lastCharIndex--;
    }

    return lastWordLength;
}

int main() {
    // Example usage
    char s[10000]; // Assuming the maximum length of the string is 10000
    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    int result = lengthOfLastWord(s);
    printf("Length of the last word: %d\n", result);

    return 0;
}

