#include <stdio.h>

#define ELEMENTS 4
#define SUBSETS 4

int subsets[SUBSETS][ELEMENTS] = {
    {1, 1, 0, 0},   // S1 = {0,1}
    {0, 0, 1, 1},   // S2 = {2,3}
    {0, 1, 1, 0},   // S3 = {1,2}
    {1, 0, 0, 1}    // S4 = {0,3}
};

int covered[ELEMENTS] = {0};
int selected[SUBSETS] = {0};
int found = 0;

void exactCover(int index)
{
    if(found)
        return;

    int complete = 1;

    for(int i = 0; i < ELEMENTS; i++)
    {
        if(covered[i] != 1)
        {
            complete = 0;
            break;
        }
    }

    if(complete)
    {
        found = 1;

        printf("Exact Cover Exists\n");
        printf("Selected Subsets: ");

        for(int i = 0; i < SUBSETS; i++)
        {
            if(selected[i])
                printf("S%d ", i + 1);
        }

        printf("\n");
        return;
    }

    if(index == SUBSETS)
        return;

    int possible = 1;

    for(int i = 0; i < ELEMENTS; i++)
    {
        if(subsets[index][i] && covered[i])
        {
            possible = 0;
            break;
        }
    }

    if(possible)
    {
        selected[index] = 1;

        for(int i = 0; i < ELEMENTS; i++)
        {
            if(subsets[index][i])
                covered[i]++;
        }

        exactCover(index + 1);

        for(int i = 0; i < ELEMENTS; i++)
        {
            if(subsets[index][i])
                covered[i]--;
        }

        selected[index] = 0;
    }

    exactCover(index + 1);
}

int main()
{
    exactCover(0);

    if(!found)
        printf("Exact Cover Does Not Exist\n");

    return 0;
}
