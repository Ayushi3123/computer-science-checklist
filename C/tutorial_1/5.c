/**
 * Structs
 */

#include <stdio.h>
#include <stdlib.h>

struct dogFavs
{
    char *food;
    char *friend;
};

typedef struct dog
{
    const char *name;
    const char *breed;
    int avgHeightCm;
    int avgWeightLbs;

    struct dogFavs favoriteThings;

} dog;

void getDogInfo(struct dog theDog)
{
    printf("\n");

    printf("Name: %s\n", theDog.name);
    printf("Breed: %s\n", theDog.breed);
    printf("Avg Height: %d cm\n", theDog.avgHeightCm);
    printf("Avg Weight: %d lbs\n", theDog.avgWeightLbs);
}

void getMemoryLocations(struct dog theDog)
{
    printf("Name Location: %d\n", theDog.name);
    printf("Breed Location: %d\n", theDog.breed);
    printf("Avg Height Location: %d\n", &theDog.breed);
    printf("Avg Weight Location: %d\n", &theDog.breed);
}

void getDogsFavs(dog theDog)
{
    printf("\n");
    printf("%s loves %s and his friend is %s\n", theDog.name, theDog.favoriteThings.food, theDog.favoriteThings.friend);
}

void setDogWeightPtr(dog *theDog, int newWeight)
{
    (*theDog).avgWeightLbs = newWeight;
    printf("Weight was changed to %d\n", theDog->avgWeightLbs);
}

void main()
{
    // struct dog cujo = {"Cujo", "Saint Bernard", 90, 264};

    // getDogInfo(cujo);

    // struct dog cujo2 = cujo;

    // getMemoryLocations(cujo);
    // getMemoryLocations(cujo2);

    dog benji = {"Benji", "Sily Terrier", 25, 9, {"Meat", "Jaco"}};

    setDogWeightPtr(&benji, 15);

    //  getDogsFavs(benji);

    printf("The weight in main is %d\n", benji.avgWeightLbs);
}