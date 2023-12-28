#include "Source/NeoTypes.h"

typedef struct
{
    char* Name;
    uint8 Age;
    char* Gender;

    double Height;
    double Weight;
} person;

sint32 main(sint32 argc, char* *argv)
{
    person* Person;
    person* PersonSaved;

    Person = malloc(sizeof(person));
    Person->Name = "John";
    Person->Age = 25;
    Person->Gender = "Male";
    Person->Height = 1.75;
    Person->Weight = 75.5;

    memSave(Person, sizeof(person), "person");

    PersonSaved = memLoad("person", sizeof(person));
    printf("%s %d %s %lf %lf\n", PersonSaved->Name, PersonSaved->Age, PersonSaved->Gender, PersonSaved->Height, PersonSaved->Weight);

    return 0;
}