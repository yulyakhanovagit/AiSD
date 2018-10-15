#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef struct Shoulder
{
    int length_left;
    int cargo_left;
    int length_right;
    int cargo_right;
    struct Shoulder *left;
    struct Shoulder *right;

}Shoulder;

// Create list

Shoulder* createShoulder()
{
    Shoulder* create = (Shoulder*)malloc(sizeof(Shoulder));
    create->length_left = 0;
    create->cargo_left = 0;
    create->length_right = 0;
    create->cargo_right = 0;
    create->left=NULL;
    create->right=NULL;
    return create;
}
//Clear list
void clear(Shoulder *head)
{
    if (!head)
    {
        return;
    }
    if (head->left)
    {
        clear(head->left);
    }
    if (head->right)
    {
        clear(head->right);
    }
    free(head);
    return;
}

//cleaning spaces
void delete_space(FILE *f, char*file)
{
    char x[100];
    int i=0;
    while(!feof(f))
    {
        fscanf(f, "%c", &x[i]);
        if (isspace(x[i]))   
            i--;
        i++;
    }
    fclose(f);
    f = fopen(file,"w+");
    fwrite(x,sizeof(char),i-1,f);
    return;
}