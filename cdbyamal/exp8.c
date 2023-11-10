#include <stdio.h>
#include <string.h>

int matchExpression(const char *str) {
    int state = 0;
    int i = 0;

    while (str[i] != '\0') {
        switch (state) {
            case 0:
                if (str[i] == 'a') {
                    state = 1;
                } else if (str[i] == 'b') {
                    state = 2;
                } else {
                    return 0; 
                }
                break;

            case 1:
                if (str[i] == 'a') {
                    state = 1;
                } else if (str[i] == 'b') {
                    state = 2;
                } else {
                    return 0;  
                }
                break;

            case 2:
                if (str[i] == 'b') {
                    state = 2;
                } else {
                    return 0;  
                }
                break;
        }
        i++;
    }

    return (state == 1 || state == 2);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (matchExpression(str)) {
        printf("The string \"%s\" is accepted.\n", str);
    } else {
        printf("The string \"%s\" is rejected.\n", str);
    }

    return 0;
}

