/*
<--------------------------------Problem Statement------------------------------------->
You are required to write a C/C++ program to perform the following tasks:
1. Generate a random integer.
2. Determine the highest base of that integer using the formula: Highest
base of an integer = max(all the digits in an integer) + 1. For
example, the highest base of 456 = max(4,5,6) = 6+1 = 7.
Your program should adhere to the following requirements:
• The program should generate a random integer where the integer should
exactly have 10 digits with last place digit should be at least 5. That is,
your number can be 5294967296 but it can not be 4294967296.
• The program should also print a nice message saying that ”The Highest
Base of a 5294967296 is 10.”
*/

#include <stdio.h>         // these libraries provide functions for input/output operations, memory allocation, and time-related functions
#include <stdlib.h>
#include <time.h>          // generate different for different times


size_t generateRandomNumber(size_t min, size_t max)           // generate a random integer between min and max (inclusive)
{
    return (rand() % (max - min + 1)) + min;                           // no issues if we remove  min 
}

int main() {
                                                                       // Seeding the random number generator with the current time
    srand(time(0));

                                                                       // here we generate the first digit (between 6 and 9) as asked in question
    int firstDigit = generateRandomNumber(6, 9);

                                                                       // here now we will generate the remaining 9 digits randomly (between 0 and 9)
    size_t base = 0;
    for (int i = 0; i < 9; i++) {
        base = base * 10 + generateRandomNumber(0, 9);
    }

                                                                      // now we will combine both to get the 10-digit random integer
    size_t randomNumber = firstDigit * 1000000000ll + base;

    printf("Random 10-digit integer: %lu\n", randomNumber);
    printf("The Highest Base of a %lu is 10.\n", randomNumber);

    return 0;
}
