#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>

/**
 * Passing memory addresses, bitwise ops, signed ints, shift ops, two's compliment, bit masking
 */

int baseToDecimal(char *number, int baseFrom, int sizeOfNumber)
{
    int result = 0;
    int toThePowerOf = 0;

    for (int i = (sizeOfNumber - 2); i >= 0; --i)
    {

        if (isalpha(number[i]))
        {
            int charCode = ((int)tolower(number[i])) - 87;
            result += charCode * pow(baseFrom, toThePowerOf);
        }
        else
        {
            result += (number[i] - '0') * pow(baseFrom, toThePowerOf);
        }

        toThePowerOf++;
    }

    printf("%s in the base %d equals %d in base 10\n", number, baseFrom, result);

    return result;
}

char *convertBase(unsigned int numberToConvert, int base, char *pConvertedNumber)
{
    char allValues[] = "0123456789abcdef";

    if (base < 2 || base > 16)
    {
        printf("Enter a number between 2 and 16\n");
        exit(1);
    }

    pConvertedNumber[32] = '\0';

    do
    {
        int value = numberToConvert % base;

        pConvertedNumber = pConvertedNumber - 1;

        *pConvertedNumber = allValues[value];

        numberToConvert /= base;

    } while (numberToConvert != 0);

    return pConvertedNumber;
}

int main()
{

    unsigned int numberSix = 6;   //110
    unsigned int numberSeven = 7; // 111

    char *pConvertedNumber;
    pConvertedNumber = malloc(33 * sizeof(char));

    // printf("%s \n", convertBase(numberSix, 2, pConvertedNumber));

    // unsigned int oneCompSolution = ~numberSix ;

    // printf("~%s  ", convertBase(numberSix, 2, pConvertedNumber));
    // // printf("%s & ", convertBase(numberSeven, 2, pConvertedNumber));
    //  printf("= %s\n\n ", convertBase(oneCompSolution, 2, pConvertedNumber));

    // printf("Negative %d is %d",numberSix,oneCompSolution);

    // unsigned int shiftLeftTwo = numberSix << 2;

    // printf("%s << 2 =  ", convertBase(numberSix, 2, pConvertedNumber));
    // // printf("%s & ", convertBase(numberSeven, 2, pConvertedNumber));
    // printf("%s = %d\n\n ", convertBase(shiftLeftTwo, 2, pConvertedNumber), shiftLeftTwo);

    // printf("Negative %d is %d",numberSix,oneCompSolution);

    // unsigned int shiftRightTwo = numberSix >> 2;

    // printf("%s << 2 =  ", convertBase(numberSix, 2, pConvertedNumber));
    // // printf("%s & ", convertBase(numberSeven, 2, pConvertedNumber));
    // printf("%s = %d\n\n ", convertBase(shiftRightTwo, 2, pConvertedNumber), shiftRightTwo);

    unsigned int analyzeMyBits = 170; // 10101010
    unsigned int theMask = 15;        // 00001111
    unsigned int last4Bits = analyzeMyBits & theMask;

    printf("last 4 bits = %s\n", convertBase(last4Bits, 2, pConvertedNumber));

    free(pConvertedNumber);

    return 0;
}