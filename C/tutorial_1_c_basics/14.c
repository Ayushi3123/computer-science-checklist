#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>

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

    char numberToConvert[] = "74";
    baseToDecimal(numberToConvert, 8, sizeof(numberToConvert));

    printf("a : %d\n", 'a');
    printf("A : %d\n", 'A');
    printf("b : %d\n", 'b');
    printf("c : %d\n", 'c');
    printf("d : %d\n", 'd');
    printf("e : %d\n", 'e');
    printf("f : %d\n", 'f');

    char numberToConvert2[] = "3c";
    baseToDecimal(numberToConvert2, 16, sizeof(numberToConvert2));

    return 0;
}