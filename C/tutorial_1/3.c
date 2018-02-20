#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void runMenu(), stringsAndArrays(), changeVariables();
int addTwoInts(int num1, int num2);

int globalVar = 0;

void main()
{
    //runMenu();
    //stringsAndArrays();

    int total = addTwoInts(1, 2);
    printf("Total %d", total);

    int age = 10;
    globalVar = 50;

    printf("age before function call : %d\n\n", age);
    printf("globalVar before function call : %d\n\n", globalVar);

    changeVariables();

    printf("age after function call : %d\n\n", age);
    printf("globalVar after function call : %d\n\n", globalVar);
}

void changeVariables()
{
    int age = 40;
    globalVar = 100;
    printf("age inside function call : %d\n\n", age);
    printf("globalVar inside function call : %d\n\n", globalVar);
}

/**
 *  Runs a simple menu and switch statement
 */
void runMenu()
{
    int whatToDo = 0;

    do
    {
        printf("\n");
        printf("1. What time is it?\n");
        printf("2. What is todays date?\n");
        printf("3. What day is it?\n");
        printf("4. Quit\n");

        scanf(" %d", &whatToDo);
    } while (whatToDo < 1 || whatToDo > 4);

    switch (whatToDo)
    {
    case 1:
        printf("time");
        break;
    case 2:
        printf("date");
        break;
    case 3:
        printf("day");
        break;
    default:
        printf("Goodbye");
        exit(0);
        break;
    }
}

/**
 * Strings and arrays sections
 */
void stringsAndArrays()
{

    printf("\n\n");

    char wholeName[] = "Jaco Jansen van Vuuren";

    int primeNumbers[3] = {2, 3, 5};

    int morePrimes[] = {13, 17, 19, 23};

    printf("The first prime in the list is %d\n\n", primeNumbers[0]);

    char thirdCity[] = "Paris";

    char yourCity[30];

    printf("What city do you live in? ");

    fgets(yourCity, 30, stdin);

    for (int i = 0; i < 30; i++)
    {
        if (yourCity[i] == '\n')
        {
            yourCity[i] = '\0';
            break;
        }
    }
    printf("Hello %s\n\n", yourCity);

    printf("Is your city Paris? %d\n\n", strcmp(yourCity, thirdCity));

    char yourState[] = ", South Africa";

    strcat(yourCity, yourState);

    printf("You live in %s\n\n", yourCity);

    printf("Letters in Paris : %d\n\n", strlen(thirdCity));

    strncpy(yourCity, "Do re mi fa so la ti do, wassup", sizeof(yourCity));

    printf("New City is %s\n\n", yourCity);
}

/**
 * Adds two integers
 */
int addTwoInts(int num1, int num2)
{
    return num1 + num2;
}