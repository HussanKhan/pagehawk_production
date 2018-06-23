#include <stdio.h>

int main() {
    char str[100];
    int i;

    printf("Enter some string: ");
    scanf("%s", str);

    printf("\nYou Entered: %s", str);

    printf("\nEnter some number: ");
    scanf("%d", &i);

    printf("\nYou Entered: %d", i);
    return 0;
}
