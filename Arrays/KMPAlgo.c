#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPS(char* pattern, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
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

void KMP(char* text, char* pattern) {
    int N = strlen(text);
    int M = strlen(pattern);

    int* lps = (int*)malloc(M * sizeof(int));
    if (lps == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    computeLPS(pattern, M, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    free(lps);
}

int main() {
    char text[100], pattern[50];

    printf("Enter the text: ");
    scanf("%99[^\n]", text);  // Read up to 99 characters until newline (excluding newline)
    getchar();  // Consume the newline character

    printf("Enter the pattern: ");
    scanf("%49[^\n]", pattern);  // Read up to 49 characters until newline (excluding newline)
    getchar();  // Consume the newline character

    KMP(text, pattern);

    return 0;
}