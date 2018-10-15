#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "func.h"

//Reading and checking data
int balanced(Shoulder *kor, FILE *f1)
{
    char x;
    int flag;
    fseek( f1 , 2, SEEK_CUR );  
    fscanf(f1, "%d", &kor->length_left);
    if (kor->length_left <0)
        return 0;
    fseek( f1 , 1 , SEEK_CUR );
    fscanf(f1, "%c", &x);
    fseek( f1 , -1 , SEEK_CUR );
    
    if (x != '(')
    {   
        if (!isdigit(x))
            return 0;
        fscanf(f1, "%d", &kor->cargo_left);
        if (kor->cargo_left <0)
            return 0;
    }
    
    else
    {  
        kor->left = createShoulder();
        flag = balanced(kor->left,f1);
        if (!flag)
            return 0;
        kor->cargo_left += (kor->left->cargo_left + kor->left->cargo_right);
    }
    fseek( f1 , 2 , SEEK_CUR );
    fscanf(f1, "%d", &kor->length_right);
    if (kor->length_right <0)
        return 0;
    fseek( f1 , 1 , SEEK_CUR );
    fscanf(f1, "%c", &x);
    fseek( f1 , -1 , SEEK_CUR );
    
    if (x != '(')
    {
        if (!isdigit(x))
            return 0;
        fscanf(f1, "%d", &kor->cargo_right);
        if (kor->cargo_right <0)
            return 0;
    }
    
    else
    {

        kor->right = createShoulder();
        flag = balanced(kor->right,f1);
        if (!flag)
            return 0;
        kor->cargo_right += (kor->right->cargo_left + kor->right->cargo_right);

    }
    fseek( f1 , 2 , SEEK_CUR );
    printf("L %d %d R %d %d\n",kor->length_left, kor->cargo_left,kor->length_right,kor->cargo_right);
    if (kor->cargo_left * kor->length_left != kor->cargo_right * kor->length_right)
        return 0;
    return 1;
}


int main()
{
    //reading a file
    char* input_file = (char*)malloc(100*sizeof(char));
    printf("File name is: ");
    fgets(input_file,100,stdin);
    input_file[strlen(input_file)-1] = '\0';
    FILE *f1;
    f1 = fopen(input_file, "r+");
        

    if (!f1)
    {
        printf("Fail with the start file\n" );
       	return 0;
    }
    delete_space(f1,input_file);
    fseek( f1 , 0 , SEEK_SET );
    Shoulder* head = createShoulder();
    //Data checking
    if (!(balanced(head, f1)))
        printf("weigth_or_length_false\n");
    else
        if (head->cargo_left * head->length_left != head->cargo_right * head->length_right)
            printf("false\n");
        else
            printf("true\n");
    //Freeing memory
    clear(head);
    free(input_file);
    fclose(f1);
    return 0;
}