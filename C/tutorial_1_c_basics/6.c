#include <stdlib.h>
#include <stdio.h>

void partOne(), partTwo();

typedef struct product
{
    const char *name;
    float price;
    struct product *next;
} product;

void printLinkedList(product *pProduct);

void main()
{
    partOne();
    partTwo();
}

/**
 * Unions, Enumerated Types, the Designated Initializer, Using unions in Structs
 */
void partOne()
{
    typedef union {
        short individual;
        float pound;
        float ounce;
    } amount;

    amount orangeAmt = {.ounce = 16};
    orangeAmt.individual = 4;

    printf("Orange juice amount: %.2f : size %d\n\n", orangeAmt.ounce, sizeof(orangeAmt.ounce));

    printf("Number of oranges: %d : size %d\n\n", orangeAmt.individual, sizeof(orangeAmt.individual));

    orangeAmt.pound = 1.5;

    printf("Orange juice amount: %.2f : size %d\n\n", orangeAmt.pound, sizeof(orangeAmt.pound));

    typedef enum { INDIV,
                   OUNCE,
                   POUND } quantity;

    typedef struct
    {
        char *brand;
        amount theAmount;
        quantity quantityType;
    } orangeProduct;

    orangeProduct productOrdered = {"Chiquita", .theAmount.ounce = 12, .quantityType = OUNCE};

    printf("You boought %.2f ounces of %s oranges\n\n", productOrdered.theAmount.ounce, productOrdered.brand);

    if (productOrdered.quantityType == INDIV)
    {
        printf("You bought %d oranges\n\n", productOrdered.theAmount.individual);
    }
    else if (productOrdered.quantityType == OUNCE)
    {
        printf("You bought %.2f ounces of oranges\n\n", productOrdered.theAmount.ounce);
    }
    else
    {
        printf("You bought %.2f pounds of oranges\n\n", productOrdered.theAmount.pound);
    }
}

/**
 * Recursive Structures, Linked Lists
 */
void partTwo()
{
    product tomato = {"Tomato", .51, NULL};
    product potato = {"Potato", 1.21, NULL};
    product lemon = {"Lemon", 1.69, NULL};
    product milk = {"Milk", 3.09, NULL};
    product turkey = {"Turkey", 1.86, NULL};

    tomato.next = &potato;
    potato.next = &lemon;
    lemon.next = &milk;
    milk.next = &turkey;

    product apple = {"Apple", 1.58, NULL};

    lemon.next = &apple;
    apple.next = &milk;

    printLinkedList(&tomato);
}

/**
 * Prints a linked list
 */
void printLinkedList(product *pProduct)
{
    while (pProduct != NULL)
    {
        //(*varName). ->
        printf("A %s costs %.2f\n\n", (*pProduct).name, pProduct->price);

        pProduct = pProduct->next;
    }
}