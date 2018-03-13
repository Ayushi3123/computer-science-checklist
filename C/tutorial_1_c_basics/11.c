#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/**
 * File IO
 * a - append
 * a+ 
 * r - read
 * w - write
 */

/**
 * Writes to the file
 */
int write()
{
    int randomNumber;

    FILE *pFile;

    pFile = fopen("randomnumbers.txt", "w");

    if (!pFile)
    {
        printf("Error: Could not write to file");
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        randomNumber = rand() % 100;
        fprintf(pFile, "%d\n", randomNumber);
    }

    printf("Write Successfull");

    if (fclose(pFile) != 0)
    {
        printf("Error: File not closed\n");
    }

    return 0;
}

/**
 * Reads from the file
 */
int read()
{
    char buffer[1000];
    FILE *pFile;

    pFile = fopen("randomnumbers.txt", "r");

    if (!pFile)
    {
        printf("Error: Could not write to file");
        return 1;
    }

    // while(fgets(buffer,1000,pFile) != NULL){
    //     printf("%s",buffer);
    // }

    while (fscanf(pFile, "%s", buffer) == 1)
    {
        puts(buffer);
    }

    printf("Read Successfull");

    if (fclose(pFile) != 0)
    {
        printf("Error: File not closed\n");
    }

    return 0;
}

int moveAround()
{
    char buffer[1000];
    FILE *pFile;

    pFile = fopen("randomwords.txt", "r+");

    if (!pFile)
    {
        printf("Error: Could not write to file");
        return 1;
    }

    fputs("Messing with strings", pFile);

    // SEEK SET = from beginning
    // SEEK CUR = from current position
    // SEEK END = from end
    fseek(pFile, 12, SEEK_SET);

    fputs(" Files ", pFile);

    fseek(pFile, 0, SEEK_SET);

    while (fscanf(pFile, "%s", buffer) == 1)
    {
        puts(buffer);
    }

    printf("Read Successfull");

    fseek(pFile, 0, SEEK_END);
    long numberOfBytes = ftell(pFile);
    printf("Number of bytes in file:%d\n", numberOfBytes);

    if (fclose(pFile) != 0)
    {
        printf("Error: File not closed\n");
    }

    return 0;
}

int main()
{
    if (write() != 0)
        return 1;
    if (read() != 0)
        return 1;
    if (moveAround() != 0)
        return 1;
}