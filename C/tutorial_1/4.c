/**
 * Totally new to pointers so this lesson is kinda cool
 * 
 *          & is used to get the pointer memory location
 *          * is used to get the value of the pointer in memory
 */

#include <stdio.h>
#include <stdlib.h>

void pointerBasics(), pointersAndArrays(), pointerRandomNumbers(int *rand1, int *rand2), pointersAndFunctionArguments(), editMessageSent(char *message, int size);
void pointersAndFunctionArgumentsStrings();

void main()
{
    //pointerBasics();
    //pointersAndArrays();
    //pointersAndFunctionArguments();
    pointersAndFunctionArgumentsStrings();
}

/**
 * Basics of pointers
 */
void pointerBasics()
{
    int rand1 = 12, rand2 = 15;

    printf("rand1 = %p : rand2 = %p\n\n", &rand1, &rand2);

    printf("rand1 = %d : rand2 = %d\n\n", &rand1, &rand2);

    printf("Size of int %d\n\n", sizeof(rand1));

    int *pRand1 = &rand1;

    printf("pointer = %p\n\n", pRand1);

    printf("pointer = %d\n\n", pRand1);

    printf("PPointer value %d\n\n", *pRand1);
}

/**
 * Accessing arrays using pointers
 */
void pointersAndArrays()
{
    int primeNumbers[] = {2, 3, 5, 7};

    printf("First index %d\n\n", primeNumbers[0]);

    printf("First index %d\n\n", *primeNumbers);

    printf("First index %d\n\n", primeNumbers[1]);

    printf("First index %d\n\n", *(primeNumbers + 1));

    char *students[4] = {"Jaco", "Mo", "Francois", "Evan"};

    for (int i = 0; i < 4; i++)
    {
        printf("%s : %d\n\n", students[i], &students[i]);
    }
}

/**
 *  Run the basic pointer and function arguments code
 */
void pointersAndFunctionArguments()
{
    int rand1 = 0, rand2 = 0;

    printf("Main before function call\n\n");

    printf("rand1 = %d\n\n", rand1);
    printf("rand2 = %d\n\n", rand2);

    pointerRandomNumbers(&rand1, &rand2);

    printf("Main after function call\n\n");

    printf("rand1 = %d\n\n", rand1);
    printf("rand2 = %d\n\n", rand2);
}

/**
 * Updates values using pointers
 */
void pointerRandomNumbers(int *rand1, int *rand2)
{
    *rand1 = rand() % 50 + 1;
    *rand2 = rand() % 50 + 1;

    printf("New rand1 in function = %d\n\n", *rand1);
    printf("New rand2 in function = %d\n\n", *rand2);
}

/**
 * Runs the pointer with function argument strings code
 */
void pointersAndFunctionArgumentsStrings()
{
    char randomMessage[] = "Edit my function";

    printf("Original message = %s\n\n", randomMessage);

    editMessageSent(randomMessage, sizeof(randomMessage));

    printf("New message = %s\n\n", randomMessage);
}

/**
 * Edits the message variable using a pointer
 */
void editMessageSent(char *message, int size)
{
    char newMessage[] = "New Message";
    if (size > sizeof(newMessage))
    {
        for (int i = 0; i < sizeof(newMessage); i++)
        {
            message[i] = newMessage[i];
        }
    }
    else
    {
        printf("Message too big");
    }
}