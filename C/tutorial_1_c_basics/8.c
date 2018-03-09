#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void partOne(), partTwo();

int main()
{

    // partOne();
    partTwo();

    return 0;
}

/**
 * Basic malloc use
 */
void partOne()
{
    int amtOfNumbersToStore;

    printf("How many numbers should we store: ");
    scanf("%d", &amtOfNumbersToStore);

    int *pRandomNumbers;

    pRandomNumbers = (int *)malloc(amtOfNumbersToStore * sizeof(int));

    if (pRandomNumbers != NULL)
    {
        int i = 0;
        printf("Enter a number or quit: ");

        while (i < amtOfNumbersToStore && scanf("%d", &pRandomNumbers[i]) == 1)
        {
            printf("Enter a number or Quit: ");
            i++;
        }

        printf("\nYou entered the following numbers\n");

        for (int j = 0; j < i; j++)
        {
            printf("%d\n", pRandomNumbers[j]);
        }
    }

    free(pRandomNumbers);
}

struct product
{
    float price;
    char productName[30];
};

/**
 * More malloc usage
 */
void partTwo()
{
    struct product *pProducts;
    int i, j;

    int numberOfProducts;

    printf("Enter the number of products to store: ");

    scanf("%d", &numberOfProducts);

    pProducts = (struct product *)malloc(numberOfProducts * sizeof(struct product));

    for (i = 0; i < numberOfProducts; i++)
    {
        printf("Enter a product name: ");
        scanf("%s", &(pProducts + i)->productName);
        printf("Enter a product price: ");
        scanf("%f", &(pProducts + i)->price);
    }

    printf("Products stored\n");

    for (j = 0; j < numberOfProducts; ++j)
    {
        printf("%s\t%.2f\n", (pProducts + j)->productName, (pProducts + j)->price);
    }

    free(pProducts);
}