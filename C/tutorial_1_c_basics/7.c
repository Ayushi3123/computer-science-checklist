#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void partOne(), partTwo(), partThree(), partFour();

void main()
{
    // partOne();
    // partTwo();
    // partThree();
    partFour();
}

/**
 * bool, scanf
 */
void partOne()
{
    bool isANumber = true;
    int number;
    int sumOfNumbers = 0;

    do
    {
        printf("Enter a number: ");
        isANumber = (scanf("%d", &number)) == 1;
        if (isANumber)
        {
            sumOfNumbers = sumOfNumbers + number;
        }
    } while (isANumber);

    printf("The sum is %d\n\n", sumOfNumbers);
}

void partTwo()
{
    printf("Type ~ and return to exit \n\n");

    char theChar;

    while ((theChar = getchar()) != '~')
    {
        putchar(theChar);
    }
}

/**
 * gets, puts, fgets, fputs
 */
void partThree()
{
    char name[50];
    printf("What is your name? ");

    gets(name);

    puts("Hi");
    puts(name);

    printf("What is your name? ");
    fgets(name, 50, stdin);
    fputs("Hi ", stdout);
    fputs(name, stdout);
}

/**
 * char * varName creates char array, the while will loop until the end of the string
 */
void partFour(){
    char * randomString = "Just some random text";
    while(*randomString){
        putchar(*randomString++);
    }


}
