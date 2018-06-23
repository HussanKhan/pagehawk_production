#include <stdio.h>

int main() {
    short year, age;
    short current_year = 2018;

    // Enums, can only accept certien strings
    // Char has only one charcter, anything single quite
    // "" is a string

    printf("Enter Year of Birth: ");
    scanf("%d", &year);

    age = current_year - year;

    printf("\nYour age is about: %d", age);

    return 0;
}
