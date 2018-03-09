/*
 * Multiline comment
 */

// Single line comment

#include <stdio.h>
#include <string.h>

#define MYNAME "Jaco Jansen van Vuuren"

int globalVar = 100;

main()
{

    /**
     * Variable declarations
     */
    char firstLetter = 'J';

    int age = 23;

    long int superBigNum = -33222642;

    float pi = 3.14159;

    double reallyBigDecimal = 3.15599979646646464646461616;

    /**
     * Basic functions
     */
    printf("\n");

    printf("This will print to screen\n\n");

    printf("I am %d years old\n\n", age);

    printf("Bug Number : %ld\n\n", superBigNum);

    printf("Pi = %.5f\n\n", pi);

    printf("Double = %.15f\n\n", reallyBigDecimal);

    printf("The first letter in my name is %c\n\n", firstLetter);

    printf("My name is %s\n\n", "Jaco");

    char myName[] = "Jaco Jansen van Vuuren";

    printf("My name is %s\n\n", myName);

    strcpy(myName, "Jacobus Jansen van Vuuren");

    printf("My name is %s\n\n", myName);

    /**
     * Printf and scanf
     */
    char middleInitial;

    printf("What is your middle initial?\n\n");

    scanf(" %C", &middleInitial);

    printf("Middle initial %c\n\n", middleInitial);

    char firstname[30], lastname[30];

    printf("What is your name?\n\n");

    scanf(" %s %s", firstname, lastname);

    printf("Your name is %s %c %s\n\n", firstname, middleInitial, lastname);

    int month, day, year;

    printf("What is your birth date? \n\n");

    scanf(" %d/%d/%d", &month, &day, &year);

    printf("Birth date %d/%d/%d\n\n", month, day, year);

    /**
     * Math
     */

    int num1 = 12, num2 = 15, numAns;

    float decimal1 = 1.2, decimal2 = 1.5, decimalAns;

    printf("Integer Calc %d\n\n", num2 / num1);

    printf("Float Calc %f\n\n", decimal2 / decimal1);

    printf("Modulus %d\n\n", num2 % num1);

    int randomNum = 1;

    printf("1 += 2 %d\n\n", randomNum += 2);

    printf("%d += 2 %d\n\n", randomNum, randomNum += 2);

    int exNum = 1;

    printf("++%d : %d\n\n", exNum, ++exNum);

    exNum = 1;

    printf("%d++ : %d\n\n", exNum, exNum++);

    /**
     *  Casting
     */
    int numberEx = 12;

    int numberEx2 = 14;

    printf("numberEx / numberEx2 : %f\n\n", (float)numberEx2 / numberEx);
}