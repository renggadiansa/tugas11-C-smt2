#include <stdio.h>

int soal8() {
    int n, guess, low, high;

    printf("Enter the upper limit of the range (1 - n): ");
    scanf("%d", &n);

    low = 1;
    high = n;

    while (low < high) {
        guess = (low + high) / 2;

        printf("Is your number less than %d (yes/no): ", guess);
        char response[3];
        scanf("%s", response);

        if (response[0] == 'y' || response[0] == 'Y') {
            high = guess;
        } else if (response[0] == 'n' || response[0] == 'N') {
            low = guess + 1;
        } else {
            printf("Invalid input. Please enter 'yes' or 'no'.\n");
        }
    }

    printf("Since your number is less than %d but not less than %d, it must be %d.\n", high, low, low);

    return 0;
}