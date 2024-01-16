#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define AMOUNT_OF_NAMES 30
#define MAX_NAME_LENGTH 20

char names[AMOUNT_OF_NAMES][MAX_NAME_LENGTH];
int isDuplicate(char *name, int current_index);
int case_insensitive_compare(char *str1, char *str2);
int random_number(int max);

int isDuplicate(char *name, int current_index)
{
    int i;
    for (i = 0; i < current_index; i++)
    {
        if (case_insensitive_compare(name, names[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int case_insensitive_compare(char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (tolower((unsigned char)*str1) != tolower((unsigned char)*str2))
        {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int random_number(int max)
{
    static int initialized = 0;

    if (!initialized)
    {
        srand(time(NULL));
        initialized = 1;
    }

    int num = rand() % (max + 1);

    return num;
}

int main()
{
    int i;
    int j;
    printf("Please Enter %d names:\n", AMOUNT_OF_NAMES);
    for (i = 0; i < AMOUNT_OF_NAMES; i++)
    {
        scanf("%s", names[i]);
        if (strlen(names[i]) > MAX_NAME_LENGTH)
        {
            printf("The entered name is too long. Please run the program again...\n");
            exit(0);
        }
        if (isDuplicate(names[i], i) == 1)
        {
            printf("Duplicate name found: %s Please run the program again...\n");
            exit(0);
        }
    }
    for (j = 0; j < 10; j++)
    {
        char *randomName = names[random_number(AMOUNT_OF_NAMES - 1)];
        printf("%s\n", randomName);
    }

    return 0;
}