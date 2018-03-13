#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/**
 * Linked list and structs
 */

struct product
{
    float price;
    char productName[30];
    struct product *next;
};

struct product *pFirstNode = NULL;
struct product *pLastNode = NULL;

void createNewList()
{
    struct product *pNewStruct = (struct product *)malloc(sizeof(struct product));

    pNewStruct->next = NULL;

    printf("Enter Product Name: ");
    scanf("%s", &(pNewStruct)->productName);
    printf("Enter Product Price: ");
    scanf("%f", &(pNewStruct)->price);

    pFirstNode = pLastNode = pNewStruct;
}

void inputData()
{
    if (pFirstNode == NULL)
    {
        createNewList();
    }
    else
    {
        struct product *pNewStruct = (struct product *)malloc(sizeof(struct product));
        printf("Enter Product Name: ");
        scanf("%s", &(pNewStruct)->productName);
        printf("Enter Product Price: ");
        scanf("%f", &(pNewStruct)->price);

        if (pFirstNode == pLastNode)
        {
            pFirstNode->next = pNewStruct;
            pLastNode = pNewStruct;
            pNewStruct->next = NULL;
        }
        else
        {
            pLastNode->next = pNewStruct;
            pNewStruct->next = NULL;
            pLastNode = pNewStruct;
        }
    }
}

void outputData()
{
    struct product *pProducts = pFirstNode;
    printf("Products Entered\n\n");
    while (pProducts != NULL)
    {
        printf("%s costs %.2f\n\n", pProducts->productName, pProducts->price);
        pProducts = pProducts->next;
    }
}

void main()
{
    inputData();
    inputData();
    inputData();

    outputData();
}