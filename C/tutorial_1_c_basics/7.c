#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void partOne(), partTwo(), partThree(), partFour(), partFive(), partSix();

void main()
{
    // partOne();
    // partTwo();
    // partThree();
    // partFour();
    // partFive();
    partSix();
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
void partFour()
{
    char *randomString = "Just some random text";
    while (*randomString)
    {
        putchar(*randomString++);
    }

    printf("\n\n");

    char *randomString2 = "Just some random text";

    int i = 0;
    while (randomString2[i] != '\0')
    {
        putchar(randomString2[i++]);
    }
}

void noMoreNewLine(char *theString)
{
    char *isANewLine;
    isANewLine = strrchr(theString, '\n');
    if (isANewLine)
    {
        *isANewLine = '\0';
    }
}

void makeLowerCase(char *theString)
{
    int i = 0;
    while (theString[i])
    {
        theString[i] = tolower(theString[i]);
        i++;
    }
}

/**
 * String manipulation
 */
void partFive()
{
    char doYouWantToQuit[10];
    do
    {
        printf("Enter quit to quit: ");

        fgets(doYouWantToQuit, 10, stdin);

        noMoreNewLine(doYouWantToQuit);

        makeLowerCase(doYouWantToQuit);
    } while (strcmp(doYouWantToQuit, "quit"));

    printf("Thanks for using this awesome quit app\n\n");
}

void getCharInfo()
{
    char theChar;
    while ((theChar == getchar()) != '\n')
    {
        printf("Letter or Number %d\n\n", isalnum(theChar));
        printf("Alphabetic Char %d\n\n", isalpha(theChar));
        printf("Standard blank %d\n\n", isblank(theChar));
        printf("Number char %d\n\n", isdigit(theChar));
        printf("Anything but %d\n\n", isgraph(theChar));
        printf("is Lower %d\n\n", islower(theChar));
        printf("is Upper %d\n\n", isupper(theChar));
        printf("is Punctionation %d\n\n", ispunct(theChar));
        printf("is Space %d\n\n", isspace(theChar));
    }
}

/**
 * Char information 
 */
void partSix()
{
    getCharInfo();
}