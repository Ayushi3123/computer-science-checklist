#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

/**
 * base conversion
 */


char *convertBase(unsigned int numberToConvert, int base)
{
    char buffer[33];
    char *pConvertedNumber;
    char allValues[] = "0123456789abcdef";

    if (base < 2 || base > 16)
    {
        printf("Enter a number between 2 and 16\n");
        exit(1);
    }

    pConvertedNumber = &buffer[sizeof(buffer) - 1];
    *pConvertedNumber = '\0';

    do
    {
        int value = numberToConvert % base;

        pConvertedNumber = pConvertedNumber - 1;

        *pConvertedNumber = allValues[value];

        numberToConvert /= base;

    } while (numberToConvert != 0);

    printf("%s", pConvertedNumber);

    return pConvertedNumber;
}

int main()
{
    unsigned int numberOne = 60;

    printf("%d in Base 2 = ", numberOne);
    convertBase(numberOne, 2);

    printf("%d in Base 8 = ", numberOne);
    convertBase(numberOne, 8);

    printf("%d in Base 16 = ", numberOne);
    convertBase(numberOne, 16);

    return 0;
}