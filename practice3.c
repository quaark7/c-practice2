#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char str[256];
    
    printf("Enter a string: ");

    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    int count = 0;
    const char vowels[] = "aeyiuoAEYUIO";

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        bool isLetter = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        bool isVowel = false;

        for (int j = 0; vowels[j] != '\0'; j++) {
            if (c == vowels[j]) {
                isVowel = true;
                break;
            }
        }

        if (isLetter && !isVowel) {
            count++;
        }
    }

    printf("Number of consonants: %d\n", count);

    return 0;
}