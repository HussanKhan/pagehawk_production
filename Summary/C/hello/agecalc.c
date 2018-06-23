#include <stdio.h>

int main() {
    short year, age;
    short current_year = 2018;

    printf("Enter Year of Birth: ");
    scanf("%d", &year);

    age = current_year - year;

    printf("\nYour age is about: %d", age);

    return 0;
}
