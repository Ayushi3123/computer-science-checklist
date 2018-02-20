#include <stdio.h>

void main()
{
    printf("\n");

    /**
     * Conditionals & logical operators
     */

    int num1 = 1, num2 = 2;

    printf("Is 1 > 2 : %d \n\n", num1 > num2);

    if (num1 > num2)
    {
        printf("%d is greated than %d \n\n", num1, num2);
    }
    else if (num1 < num2)
    {
        printf("%d is less than %d \n\n", num1, num2);
    }
    else
    {
        printf("%d is equal to %d \n\n", num1, num2);
    }

    int custAge = 38;

    if (custAge > 21 && custAge < 35)
        printf("Customer is allowed\n\n");
    else
        printf("Customer is not welcome\n\n");

    // Missed less than ten days work AND
    // Over 30 000 in sales OR
    // Signed up more than 30 customers

    int bobMissedDays = 8, bobTotalSales = 24000, bobNewCustomers = 32;

    if (bobMissedDays < 10 && bobTotalSales > 30000 || bobNewCustomers > 30)
        printf("Bob gets a raise\n\n");

    custAge = 38;

    char *legalAge = custAge > 21 ? "true" : "false";

    printf("Customer of legal age? %s \n\n", legalAge);

    int numOfProducts = 10;
    printf("I bought %s products \n\n", numOfProducts > 1 ? "many" : "one");

    /**
     * Size of type
     */

    printf("A char takes up %d bytes\n\n", sizeof(char));
    printf("A int takes up %d bytes\n\n", sizeof(int));
    printf("A long int takes up %d bytes\n\n", sizeof(long int));
    printf("A float takes up %d bytes\n\n", sizeof(float));
    printf("A double takes up %d bytes\n\n", sizeof(double));

    int bigInt = 2147483647;

    printf("I am bigger than you may have heard %d \n\n", bigInt);

    int numberHowBig = 0;

    printf("how many bits? ");
    scanf(" %d", &numberHowBig);
    printf("\n\n");

    int myIncrementor = 1, myMultiplier = 1, finalValue = 1;

    while (myIncrementor < numberHowBig)
    {
        myMultiplier *= 2;
        finalValue = finalValue + myMultiplier;
        myIncrementor++;
    }

    if (numberHowBig == 0 || numberHowBig == 1)
    {
        printf("Top value %d \n\n", numberHowBig);
    }
    else
    {
        printf("Top value %d \n\n", finalValue);
    }

    /**
     * Loops
     */

    int secretNumber = 10, numberGuessed = 0;

    while (1)
    {
        printf("Guess my secret number: ");
        scanf(" %d", &numberGuessed);

        if (numberGuessed == secretNumber)
        {
            printf("Nice!\n\n");
            break;
        }
    }

    char sizeOfShirt;

    do
    {
        printf("Size of shirt? (S,M,L)");
        scanf(" %c", &sizeOfShirt);
    } while (sizeOfShirt != 'S' && sizeOfShirt != 'M' && sizeOfShirt != 'L');

    for (int counter = 0; counter < 40; counter++)
    {
        if (counter % 2 == 0)
            continue;
        printf("%d\n\n", counter);
    }
}