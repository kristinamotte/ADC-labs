#include <stdio.h>
#include <ctype.h>
#include <string.h> 

#define LENGTH 32

int main() {
    char text[LENGTH];

    printf("Type random sentense\n");
    scanf("%[^\n]", text);

    for (int i = 0; i < strlen(text); i++) {
        if (isupper(text[i])) {
            text[i] = tolower(text[i]);
        }

        if (!isalpha(text[i])) {
            text[i] = ' ';
        }
    }

    for (int i = 0; i < strlen(text) - 1; i++) {
        if (!isspace(text[i + 1]) && !isspace(text[i])) {
            int count = 0;
            const char *tmp = text;
            char string2find[3] = {text[i], text[i+1]};

            while((tmp = strstr(tmp, string2find))) {
                count++;
                tmp++;
            }    

            printf("%s - %d; ", string2find, count);
        }
    }
    
    return 0;
};