/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char symbols[] = "!@#$%^&*()-_=+[]{};:'\",.<>/?\\|~`";

// Function to get a random symbol
char getRandomSymbol() {
    return symbols[rand() % (sizeof(symbols) - 1)]; // Exclude null terminator
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Random symbols: ");
    for (int i = 0; i < 30; i++) {
        printf("%c\n", getRandomSymbol());
    }
    printf("\n");

    return 0;
}
*/