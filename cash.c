#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    float dollars;
    do
    {
         dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    int cents = round(dollars * 100);

    int coins = 0;
    // we will be using modulo, applying in this order to get remainders: quarter(25) -> dime (10) -> nickel (5) -> penny (1)

    while (cents != 0){
        // counting how many quarters while also removing the quarters
        coins += cents/25;
        cents = cents%25;

        // dimes (10)
        coins += cents/10;
        cents %= 10;

        // nickels (5)
        coins += cents/5;
        cents %=5;

        // pennies(1)
        coins += cents / 1;
        cents %= 1;
    }

    printf("%d\n", coins);
}