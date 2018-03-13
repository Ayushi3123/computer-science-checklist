#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

/**
 * Binary file IO & Error Handling in C
 */

void writeStringToBinary()
{
    FILE *pFile;

    char *buffer;

    size_t dataInFile;

    long fileSize;

    pFile = fopen("names.bin", "rb+");

    if (pFile == NULL)
    {
        perror("Error Occured");
        printf("Error Code %d\n", errno);

        printf("Creating File\n\n");

        pFile = fopen("names.bin", "wb+");
        if (pFile == NULL)
        {
            perror("Error Occured");
            printf("Error Code %d\n", errno);
            exit(1);
        }
    }

    char name[] = "Derek Banas";
    fwrite(name, sizeof(name[0]), sizeof(name) / sizeof(name[0]), pFile);

    fseek(pFile, 0, SEEK_END);
    fileSize = ftell(pFile);

    rewind(pFile);

    buffer = (char *)malloc(sizeof(char) * fileSize);

    if (buffer == NULL)
    {
        perror("Error Occured");
        printf("Error Code %d\n", errno);
        exit(2);
    }

    dataInFile = fread(buffer, 1, fileSize, pFile);

    if (dataInFile != fileSize)
    {
        perror("Error Occured");
        printf("Error Code %d\n", errno);
        exit(3);
    }

    printf("%s\n", buffer);
    printf("\n");

    fclose(pFile);
    free(buffer);
}

void writeArrayToBinary()
{
    FILE *pFile;

    size_t dataInFile;

    long fileSize;

    pFile = fopen("randomnums.bin", "rb+");

    if (pFile == NULL)
    {
        perror("Error Occured");
        printf("Error Code %d\n", errno);

        printf("Creating File\n\n");

        pFile = fopen("randomnums.bin", "wb+");
        if (pFile == NULL)
        {
            perror("Error Occured");
            printf("Error Code %d\n", errno);
            exit(1);
        }
    }

    int randomNumbers[20];
    for (int i = 0; i < 20; i++)
    {
        randomNumbers[i] = rand() % 100;
        printf("Number %d is %d\n", i, randomNumbers[i]);
    }

    fwrite(randomNumbers, sizeof(int), 20, pFile);

    long randomIndexNumber;
    int numberAtIndex;

    printf("Which random number do you want?");
    scanf("%ld", &randomIndexNumber);

    fseek(pFile, randomIndexNumber * sizeof(int), SEEK_SET);
    fread(&numberAtIndex, sizeof(int), 1, pFile);

    printf("The random number at idnex %d is %d\n", randomIndexNumber, numberAtIndex);

    fclose(pFile);

}

int main()
{

    writeStringToBinary();

    writeArrayToBinary();

    return 0;
}